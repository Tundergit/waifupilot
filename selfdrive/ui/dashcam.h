#include <time.h>
#include <dirent.h>

#define CAPTURE_STATE_NONE 0
#define CAPTURE_STATE_CAPTURING 1
#define CAPTURE_STATE_NOT_CAPTURING 2
#define CAPTURE_STATE_PAUSED 3
#define CLICK_TIME 0.2
#define RECORD_INTERVAL 180 // Time in seconds to rotate recordings; Max for screenrecord is 3 minutes
#define RECORD_FILES 40 // Number of files to create before looping over

typedef struct dashcam_element {
  int pos_x;
  int pos_y;
  int width;
  int height;
} dashcam_element;

dashcam_element lock_button;

int captureState = CAPTURE_STATE_NOT_CAPTURING;
int captureNum = 0;
int start_time = 0;
int elapsed_time = 0; // Time of current recording
int click_elapsed_time = 0;
int click_time = 0;
char filenames[RECORD_FILES][50]; // Track the filenames so they can be deleted when rotating

bool lock_current_video = false; // If true save the current video before rotating
bool locked_files[RECORD_FILES]; // Track which files are locked
int lock_image; // Stores reference to the PNG
int files_created = 0;

int get_time() {
  // Get current time (in seconds)

  int iRet;
  struct timeval tv;
  int seconds = 0;

  iRet = gettimeofday(&tv,NULL);
  if (iRet == 0) {
    seconds = (int)tv.tv_sec;
  }
  return seconds;
}

struct tm get_time_struct() {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  return tm;
}

void remove_file(char *videos_dir, char *filename) {
  if (filename[0] == '\0') {
    // Don't do anything if no filename is passed
    return;
  }

  int status;
  char fullpath[64];
  snprintf(fullpath,sizeof(fullpath),"%s/%s", videos_dir, filename);
  status = remove(fullpath);
  if (status == 0) {
    printf("Removed file: %s\n", fullpath);
  }
  else {
    printf("Unable to remove file: %s\n", fullpath);
    perror("Error message:");
  }
}

void save_file(char *videos_dir, char *filename) {
  if (!strlen(filename)) {
    return;
  }

  // Rename file to save it from being overwritten
  char cmd[128];
  snprintf(cmd,sizeof(cmd), "mv %s/%s %s/saved_%s", videos_dir, filename, videos_dir, filename);
  printf("save: %s\n",cmd);
  system(cmd);
}

void stop_capture() {
  char videos_dir[50] = "/storage/emulated/0/videos";

  if (captureState == CAPTURE_STATE_CAPTURING) {
    system("killall -SIGINT screenrecord");
    captureState = CAPTURE_STATE_NOT_CAPTURING;
    elapsed_time = get_time() - start_time;
    if (elapsed_time < 3) {
      remove_file(videos_dir, filenames[captureNum]);
    } else {
      //printf("Stop capturing screen\n");
      captureNum++;

      if (captureNum > RECORD_FILES-1) {
        captureNum = 0;
      }
    }
  }
}

void start_capture() {
  captureState = CAPTURE_STATE_CAPTURING;
  char cmd[128] = "";
  char videos_dir[50] = "/storage/emulated/0/videos";

  //////////////////////////////////
  // NOTE: make sure videos_dir folder exists on the device!
  //////////////////////////////////
  struct stat st = {0};
  if (stat(videos_dir, &st) == -1) {
    mkdir(videos_dir,0700);
  }
  /*if (captureNum == 0 && files_created == 0) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("/storage/emulated/0/videos")) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
        strcpy(filenames[files_created++], ent->d_name);
      }
      captureNum = files_created;
      closedir (dir);
    }
  }*/

  if (strlen(filenames[captureNum]) && files_created >= RECORD_FILES) {
    if (locked_files[captureNum] > 0) {
      save_file(videos_dir, filenames[captureNum]);
    }
    else {
      // remove the old file
      remove_file(videos_dir, filenames[captureNum]);
    }
    locked_files[captureNum] = 0;
  }

  char filename[64];
  struct tm tm = get_time_struct();
  snprintf(filename,sizeof(filename),"%04d%02d%02d-%02d%02d%02d.mp4", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  snprintf(cmd,sizeof(cmd),"screenrecord --size 1280x720 --bit-rate 5000000 %s/%s&",videos_dir,filename);
  //snprintf(cmd,sizeof(cmd),"screenrecord --size 960x540 --bit-rate 5000000 %s/%s&",videos_dir,filename);
  strcpy(filenames[captureNum],filename);

  printf("Capturing to file: %s\n",cmd);
  start_time = get_time();
  system(cmd);

  if (lock_current_video) {
    // Lock is still on so mark this file for saving
    locked_files[captureNum] = 1;
  }
  else {
    locked_files[captureNum] = 0;
  }

  files_created++;
}

bool screen_lock_button_clicked(int touch_x, int touch_y, dashcam_element el) {
  if (captureState == CAPTURE_STATE_NOT_CAPTURING) {
    // Don't register click if we're not recording
    return false;
  }

  if (touch_x >= el.pos_x && touch_x <= el.pos_x + el.width) {
    if (touch_y >= el.pos_y && touch_y <= el.pos_y + el.height) {
      return true;
    }
  }
  return false;
}

bool screen_button_clicked(int touch_x, int touch_y) {
  if (touch_x >= 1660 && touch_x <= 1810) {
    if (touch_y >= 885 && touch_y <= 1035) {
      return true;
    }
  }
  return false;
}

void draw_date_time(UIState *s) {
  if (captureState == CAPTURE_STATE_NOT_CAPTURING) {
    // Don't draw if we're not recording
    return;
  }

  // Draw the current date/time

  int rect_w = 465;
  int rect_h = 80;
  int rect_x = (1920-rect_w)/2;
  int rect_y = (1080-rect_h-10);

  // Get local time to display
  char now[50];
  struct tm tm = get_time_struct();
  snprintf(now,sizeof(now),"%04d/%02d/%02d  %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

  nvgBeginPath(s->vg);
    nvgRoundedRect(s->vg, rect_x, rect_y, rect_w, rect_h, 15);
    nvgFillColor(s->vg, nvgRGBA(0, 0, 0, 100));
    nvgFill(s->vg);
    nvgStrokeColor(s->vg, nvgRGBA(255,255,255,80));
    nvgStrokeWidth(s->vg, 6);
    nvgStroke(s->vg);

  nvgFontSize(s->vg, 60);
    nvgFontFace(s->vg, "sans-semibold");
    nvgFillColor(s->vg, nvgRGBA(255, 255, 255, 200));
    nvgText(s->vg,rect_x+231,rect_y+55,now,NULL);
}

static void rotate_video() {
  // Overwrite the existing video (if needed)
  elapsed_time = 0;
  stop_capture();
  captureState = CAPTURE_STATE_CAPTURING;
  start_capture();
}

void draw_lock_button(UIState *s) {
  int btn_w = 150;
  int btn_h = 150;
  int btn_x = 1920 - btn_w - 150;
  int btn_y = 1080 - btn_h;
  int imgw, imgh;
  float alpha = 0.3f;

  if (!lock_image) {
    // Load the lock icon
    lock_image = nvgCreateImage(s->vg, "../assets/lock_icon.png", 1);
  }

  if (lock_current_video) {
    alpha = 1.0f;
  }

  nvgBeginPath(s->vg);
  NVGpaint imgPaint = nvgImagePattern(s->vg, btn_x-125, btn_y-45, 150, 150, 0, lock_image, alpha);
  nvgRoundedRect(s->vg, btn_x-125, btn_y-45, 150, 150, 100);
  nvgFillPaint(s->vg, imgPaint);
  nvgFill(s->vg);


  lock_button = (dashcam_element){
    .pos_x = 1500,
    .pos_y = 920,
    .width = 150,
    .height = 150
  };
}

static void screen_draw_button(UIState *s, int touch_x, int touch_y) {
  // Set button to bottom left of screen
//  if (s->vision_connected && s->plus_state == 0) {
  if (s->vision_connected){

    if (captureState == CAPTURE_STATE_CAPTURING) {
      draw_lock_button(s);
    }

    int btn_w = 150;
    int btn_h = 150;
    int btn_x = 1920 - btn_w;
    int btn_y = 1080 - btn_h;
    nvgBeginPath(s->vg);
      nvgRoundedRect(s->vg, btn_x-110, btn_y-45, btn_w, btn_h, 100);
      nvgStrokeColor(s->vg, nvgRGBA(255,255,255,80));
      nvgStrokeWidth(s->vg, 6);
      nvgStroke(s->vg);

      nvgFontSize(s->vg, 70);

      if (captureState == CAPTURE_STATE_CAPTURING) {
        NVGcolor fillColor = nvgRGBA(255,0,0,150);
        nvgFillColor(s->vg, fillColor);
        nvgFill(s->vg);
        nvgFillColor(s->vg, nvgRGBA(255,255,255,200));
      }
      else {
        nvgFillColor(s->vg, nvgRGBA(255, 255, 255, 200));
      }
      nvgText(s->vg,btn_x-88,btn_y+50,"REC",NULL);
  }

  if (captureState == CAPTURE_STATE_CAPTURING) {
    //draw_date_time(s);

    elapsed_time = get_time() - start_time;

    if (elapsed_time >= RECORD_INTERVAL) {
      rotate_video();
    }
  }
}

void screen_toggle_record_state() {
  if (captureState == CAPTURE_STATE_CAPTURING) {
    stop_capture();
    lock_current_video = false;
  }
  else {
    //captureState = CAPTURE_STATE_CAPTURING;
    start_capture();
  }
}

void screen_toggle_lock() {
  if (lock_current_video) {
    lock_current_video = false;
  }
  else {
    lock_current_video = true;
    locked_files[captureNum] = 1;
  }
}

void dashcam( UIState *s, int touch_x, int touch_y ) {
  screen_draw_button(s, touch_x, touch_y);
  if (screen_button_clicked(touch_x,touch_y)) {
    click_elapsed_time = get_time() - click_time;

    if (click_elapsed_time > 0) {
      click_time = get_time() + 1;
      screen_toggle_record_state();
    }
  }

  if (screen_lock_button_clicked(touch_x,touch_y,lock_button)) {
    screen_toggle_lock();
  }
  if (!s->vision_connected) {
    // Assume car is not in drive so stop recording
    stop_capture();
  }
//  if (s->scene.v_ego > 2.1 && captureState == CAPTURE_STATE_NOT_CAPTURING && !s->scene.engaged) {
//    start_capture();
//  } else if (s->scene.v_ego < 1.5 && !s->scene.engaged) {
  if (s->scene.v_ego < 1.5 && !s->scene.engaged) {
    stop_capture();
  }
  s->scene.recording = (captureState != CAPTURE_STATE_NOT_CAPTURING);
}