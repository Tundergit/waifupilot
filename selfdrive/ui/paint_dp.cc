#include "paint_dp.hpp"
#include <math.h>

void ui_draw_df_button(UIState *s) {
  nvgBeginPath(s->vg);
  nvgRoundedRect(s->vg, df_btn_x, df_btn_y, df_btn_w, df_btn_h, 20);
  nvgStrokeColor(s->vg, COLOR_WHITE_ALPHA(80));
  nvgStrokeWidth(s->vg, 6);
  nvgStroke(s->vg);

  nvgFontFaceId(s->vg,  s->font_sans_regular);
  nvgFillColor(s->vg, COLOR_WHITE_ALPHA(200));
  nvgFontSize(s->vg, (s->scene.dpLocale == "zh-TW"? 96 : s->scene.dpLocale == "zh-CN"? 96 : 48));
  nvgTextAlign(s->vg, NVG_ALIGN_CENTER);

  nvgText(s->vg, df_btn_x + df_btn_w / 2, df_btn_y + df_btn_h / 2,
  s->scene.dpDynamicFollow == 4? (s->scene.dpLocale == "zh-TW"? "自動" : s->scene.dpLocale == "zh-CN"? "自动" : "AUTO") :
  s->scene.dpDynamicFollow == 3? (s->scene.dpLocale == "zh-TW"? "長距" : s->scene.dpLocale == "zh-CN"? "长距" : "LONG") :
  s->scene.dpDynamicFollow == 2? (s->scene.dpLocale == "zh-TW"? "正常" : s->scene.dpLocale == "zh-CN"? "正常" : "NORMAL") :
  (s->scene.dpLocale == "zh-TW"? "短距" : s->scene.dpLocale == "zh-CN"? "短距" : "SHORT"),
  NULL);

  nvgFontFaceId(s->vg,  s->font_sans_regular);
  nvgFillColor(s->vg, COLOR_WHITE_ALPHA(200));
  nvgFontSize(s->vg, 37.5);
  nvgTextAlign(s->vg, NVG_ALIGN_CENTER);
  nvgText(s->vg, df_btn_x + df_btn_w / 2, df_btn_y + df_btn_h - 10,
  (s->scene.dpLocale == "zh-TW"? "車距" : s->scene.dpLocale == "zh-CN"? "车距" : "FOLLOW"),
  NULL);
}

void ui_draw_ap_button(UIState *s) {
  nvgBeginPath(s->vg);
  nvgRoundedRect(s->vg, ap_btn_x, ap_btn_y, ap_btn_w, ap_btn_h, 20);
  nvgStrokeColor(s->vg, COLOR_WHITE_ALPHA(80));
  nvgStrokeWidth(s->vg, 6);
  nvgStroke(s->vg);

  nvgFontFaceId(s->vg,  s->font_sans_regular);
  nvgFillColor(s->vg, COLOR_WHITE_ALPHA(200));
  nvgFontSize(s->vg, (s->scene.dpLocale == "zh-TW"? 96 : s->scene.dpLocale == "zh-CN"? 96 : 48));
  nvgTextAlign(s->vg, NVG_ALIGN_CENTER);

  nvgText(s->vg, ap_btn_x + ap_btn_w / 2, ap_btn_y + ap_btn_h / 2,
  s->scene.dpAccelProfile == 3? (s->scene.dpLocale == "zh-TW"? "運動" : s->scene.dpLocale == "zh-CN"? "运动" : "SPORT") :
  s->scene.dpAccelProfile == 2? (s->scene.dpLocale == "zh-TW"? "正常" : s->scene.dpLocale == "zh-CN"? "正常" : "NORMAL") :
  (s->scene.dpLocale == "zh-TW"? "節能" : s->scene.dpLocale == "zh-CN"? "节能" : "ECO"),
  NULL);

  nvgFontFaceId(s->vg,  s->font_sans_regular);
  nvgFillColor(s->vg, COLOR_WHITE_ALPHA(200));
  nvgFontSize(s->vg, 37.5);
  nvgTextAlign(s->vg, NVG_ALIGN_CENTER);

  nvgText(s->vg, ap_btn_x + ap_btn_w / 2, ap_btn_y + ap_btn_h - 10,
  (s->scene.dpLocale == "zh-TW"? "加速" : s->scene.dpLocale == "zh-CN"? "加速" : "ACCEL"),
  NULL);
}

void ui_draw_infobar(UIState *s) {
  const int x = s->scene.viz_rect.x;
  const int y = s->scene.viz_rect.bottom() - info_bar_h;
  const int w = s->scene.viz_rect.w;
  const int text_x = w / 2 + x;
  const int text_y = y + 55;

  char infobar[100];
  // create time string
  char date_time[20];
  time_t rawtime = time(NULL);
  struct tm timeinfo;
  localtime_r(&rawtime, &timeinfo);
  strftime(date_time, sizeof(date_time),"%D %T", &timeinfo);

  // Create temp string
  char temp[6];
  snprintf(temp, sizeof(temp), "%02d°C", (int)s->scene.thermal.getAmbient());

  // create battery percentage string
  char battery[5];
  snprintf(battery, sizeof(battery), "%02d%%", s->scene.thermal.getBatteryPercent());

  if (!s->scene.dpUiDev) {
    char rel_steer[9];
    snprintf(rel_steer, sizeof(rel_steer), "%s%05.1f°", s->scene.controls_state.getAngleSteers() < 0? "-" : "+", fabs(s->scene.angleSteers));

    char des_steer[9];
    if (s->scene.controls_state.getEnabled()) {
      snprintf(des_steer, sizeof(des_steer), "%s%05.1f°", s->scene.controls_state.getAngleSteersDes() < 0? "-" : "+", fabs(s->scene.angleSteersDes));
    } else {
      snprintf(des_steer, sizeof(des_steer), "%7s", "-");
    }

    char lead_dist[8];
    if (s->scene.lead_data[0].getStatus()) {
      snprintf(lead_dist, sizeof(lead_dist), "%06.2fm", s->scene.lead_data[0].getDRel());
    } else {
      snprintf(lead_dist, sizeof(lead_dist), "%7s", "-");
    }

    snprintf(
      infobar,
      sizeof(infobar),
      "%s /TMP: %s /BAT: %s /REL: %s /DES: %s /DIS: %s",
      date_time,
      temp,
      battery,
      rel_steer,
      des_steer,
      lead_dist
    );
  } else {
    snprintf(
      infobar,
      sizeof(infobar),
      "%s /TMP: %s /BAT: %s",
      date_time,
      temp,
      battery
    );
  }

  nvgBeginPath(s->vg);
  nvgRect(s->vg, x, y, w, info_bar_h);
  nvgFillColor(s->vg, (s->scene.brakeLights? COLOR_RED_ALPHA(200) : COLOR_BLACK_ALPHA(s->scene.dpFullScreenApp? 150 : 100)));
  nvgFill(s->vg);

  nvgFontSize(s->vg, !s->scene.uilayout_sidebarcollapsed? 35:42);
  nvgFontFaceId(s->vg, s->font_courbd);
  nvgFillColor(s->vg, COLOR_WHITE_ALPHA(200));
  nvgTextAlign(s->vg, NVG_ALIGN_CENTER);
  nvgText(s->vg, text_x, text_y, infobar, NULL);
}

void ui_draw_blindspots(UIState *s, bool hasInfobar) {
  const int width = 100;
  const int infobar_h = hasInfobar? info_bar_h : 0;
  const int y = s->scene.viz_rect.bottom() - infobar_h - 100;

  if (s->scene.leftBlindspot) {
    const int left_x = s->scene.viz_rect.x;
    nvgBeginPath(s->vg);
    nvgMoveTo(s->vg, left_x, y);
    nvgLineTo(s->vg, left_x, y+width);
    nvgLineTo(s->vg, left_x+width, y+width);
    nvgClosePath(s->vg);
    nvgFillColor(s->vg, COLOR_RED_ALPHA(200));
    nvgFill(s->vg);
  }
  if (s->scene.rightBlindspot) {
    const int right_x = s->scene.viz_rect.right();
    nvgBeginPath(s->vg);
    nvgMoveTo(s->vg, right_x, y);
    nvgLineTo(s->vg, right_x, y+width);
    nvgLineTo(s->vg, right_x-100, y+width);
    nvgClosePath(s->vg);
    nvgFillColor(s->vg, COLOR_RED_ALPHA(200));
    nvgFill(s->vg);
  }
}

//BB START: functions added for the display of various items
int bb_ui_draw_measure(UIState *s,  const char* bb_value, const char* bb_uom, const char* bb_label,
    int bb_x, int bb_y, int bb_uom_dx,
    NVGcolor bb_valueColor, NVGcolor bb_labelColor, NVGcolor bb_uomColor,
    int bb_valueFontSize, int bb_labelFontSize, int bb_uomFontSize ) {

  nvgTextAlign(s->vg, NVG_ALIGN_CENTER | NVG_ALIGN_BASELINE);
  int dx = 0;
  if (strlen(bb_uom) > 0) {
    dx = (int)(bb_uomFontSize*2.5/2);
  }
  //print value
  nvgFontFaceId(s->vg, s->font_sans_bold);
  nvgFontSize(s->vg, bb_valueFontSize*2.5);
  nvgFillColor(s->vg, bb_valueColor);
  nvgText(s->vg, bb_x-dx/2, bb_y+ (int)(bb_valueFontSize*2.5)+5, bb_value, NULL);
  //print label
  nvgFontFaceId(s->vg, s->font_sans_regular);
  nvgFontSize(s->vg, bb_labelFontSize*2.5);
  nvgFillColor(s->vg, bb_labelColor);
  nvgText(s->vg, bb_x, bb_y + (int)(bb_valueFontSize*2.5)+5 + (int)(bb_labelFontSize*2.5)+5, bb_label, NULL);
  //print uom
  if (strlen(bb_uom) > 0) {
    nvgSave(s->vg);
    int rx =bb_x + bb_uom_dx + bb_valueFontSize -3;
    int ry = bb_y + (int)(bb_valueFontSize*2.5/2)+25;
    nvgTranslate(s->vg,rx,ry);
    nvgRotate(s->vg, -1.5708); //-90deg in radians
    nvgFontFaceId(s->vg, s->font_sans_regular);
    nvgFontSize(s->vg, (int)(bb_uomFontSize*2.5));
    nvgFillColor(s->vg, bb_uomColor);
    nvgText(s->vg, 0, 0, bb_uom, NULL);
    nvgRestore(s->vg);
  }
  return (int)((bb_valueFontSize + bb_labelFontSize)*2.5) + 5;
}

void bb_ui_draw_measures_left(UIState *s, int bb_x, int bb_y, int bb_w ) {
  int bb_rx = bb_x + (int)(bb_w/2);
  int bb_ry = bb_y;
  int bb_h = 5;
  NVGcolor lab_color = COLOR_WHITE_ALPHA(200);
  NVGcolor uom_color = COLOR_WHITE_ALPHA(200);
  int value_fontSize=30;
  int label_fontSize=15;
  int uom_fontSize = 15;
  int bb_uom_dx =  (int)(bb_w /2 - uom_fontSize*2.5) ;
  float d_rel = s->scene.lead_data[0].getDRel();
  float v_rel = s->scene.lead_data[0].getVRel();

  //add visual radar relative distance
  if (true) {
    char val_str[16];
    char uom_str[6];
    NVGcolor val_color = COLOR_WHITE_ALPHA(200);
    if (s->scene.lead_data[0].getStatus()) {
      //show RED if less than 5 meters
      //show orange if less than 15 meters
      if((int)(d_rel) < 15) {
        val_color = nvgRGBA(255, 188, 3, 200);
      }
      if((int)(d_rel) < 5) {
        val_color = nvgRGBA(255, 0, 0, 200);
      }
      // lead car relative distance is always in meters
      snprintf(val_str, sizeof(val_str), "%d", (int)d_rel);
    } else {
       snprintf(val_str, sizeof(val_str), "-");
    }
    snprintf(uom_str, sizeof(uom_str), "m   ");
    bb_h +=bb_ui_draw_measure(s,  val_str, uom_str,
       (s->scene.dpLocale == "zh-TW"? "真實車距" : s->scene.dpLocale == "zh-CN"? "真实车距" : "REL DIST"),
        bb_rx, bb_ry, bb_uom_dx,
        val_color, lab_color, uom_color,
        value_fontSize, label_fontSize, uom_fontSize );
    bb_ry = bb_y + bb_h;
  }

  //add visual radar relative speed
  if (true) {
    char val_str[16];
    char uom_str[6];
    NVGcolor val_color = COLOR_WHITE_ALPHA(200);
    if (s->scene.lead_data[0].getStatus()) {
      //show Orange if negative speed (approaching)
      //show Orange if negative speed faster than 5mph (approaching fast)
      if((int)(v_rel) < 0) {
        val_color = nvgRGBA(255, 188, 3, 200);
      }
      if((int)(v_rel) < -5) {
        val_color = nvgRGBA(255, 0, 0, 200);
      }
      // lead car relative speed is always in meters
      if (s->is_metric) {
         snprintf(val_str, sizeof(val_str), "%d", (int)(v_rel * 3.6 + 0.5));
      } else {
         snprintf(val_str, sizeof(val_str), "%d", (int)(v_rel * 2.2374144 + 0.5));
      }
    } else {
       snprintf(val_str, sizeof(val_str), "-");
    }
    if (s->is_metric) {
      snprintf(uom_str, sizeof(uom_str), "km/h");;
    } else {
      snprintf(uom_str, sizeof(uom_str), "mph");
    }
    bb_h +=bb_ui_draw_measure(s,  val_str, uom_str,
        (s->scene.dpLocale == "zh-TW"? "相對速度" : s->scene.dpLocale == "zh-CN"? "相对速度" : "REAL SPEED"),
        bb_rx, bb_ry, bb_uom_dx,
        val_color, lab_color, uom_color,
        value_fontSize, label_fontSize, uom_fontSize );
    bb_ry = bb_y + bb_h;
  }

  //finally draw the frame
  bb_h += 20;
  nvgBeginPath(s->vg);
    nvgRoundedRect(s->vg, bb_x, bb_y, bb_w, bb_h, 20);
    nvgStrokeColor(s->vg, COLOR_WHITE_ALPHA(80));
    nvgStrokeWidth(s->vg, 6);
    nvgStroke(s->vg);
}

void bb_ui_draw_measures_right(UIState *s, int bb_x, int bb_y, int bb_w ) {
  int bb_rx = bb_x + (int)(bb_w/2);
  int bb_ry = bb_y;
  int bb_h = 5;
  NVGcolor lab_color = COLOR_WHITE_ALPHA(200);
  NVGcolor uom_color = COLOR_WHITE_ALPHA(200);
  int value_fontSize=30;
  int label_fontSize=15;
  int uom_fontSize = 15;
  int bb_uom_dx =  (int)(bb_w /2 - uom_fontSize*2.5) ;

  //add  steering angle
  if (true) {
    char val_str[16];
    char uom_str[6];
    NVGcolor val_color = COLOR_WHITE_ALPHA(200);
      //show Orange if more than 6 degrees
      //show red if  more than 12 degrees
      if(((int)(s->scene.angleSteers) < -6) || ((int)(s->scene.angleSteers) > 6)) {
        val_color = nvgRGBA(255, 188, 3, 200);
      }
      if(((int)(s->scene.angleSteers) < -12) || ((int)(s->scene.angleSteers) > 12)) {
        val_color = nvgRGBA(255, 0, 0, 200);
      }
      // steering is in degrees
      snprintf(val_str, sizeof(val_str), "%.1f°",(s->scene.angleSteers));

      snprintf(uom_str, sizeof(uom_str), "");
    bb_h +=bb_ui_draw_measure(s,  val_str, uom_str,
      (s->scene.dpLocale == "zh-TW"? "實際轉角" : s->scene.dpLocale == "zh-CN"? "实际转角" : "REAL STEER"),
      bb_rx, bb_ry, bb_uom_dx,
      val_color, lab_color, uom_color,
      value_fontSize, label_fontSize, uom_fontSize );
    bb_ry = bb_y + bb_h;
  }

  //add  desired steering angle
  if (true) {
    char val_str[16];
    char uom_str[6];
    NVGcolor val_color = COLOR_WHITE_ALPHA(200);
    //show Orange if more than 6 degrees
    //show red if  more than 12 degrees
    if(((int)(s->scene.angleSteersDes) < -6) || ((int)(s->scene.angleSteersDes) > 6)) {
      val_color = nvgRGBA(255, 188, 3, 200);
    }
    if(((int)(s->scene.angleSteersDes) < -12) || ((int)(s->scene.angleSteersDes) > 12)) {
      val_color = nvgRGBA(255, 0, 0, 200);
    }
    // steering is in degrees
    snprintf(val_str, sizeof(val_str), "%.1f°",(s->scene.angleSteersDes));

    snprintf(uom_str, sizeof(uom_str), "");
    bb_h +=bb_ui_draw_measure(s,  val_str, uom_str,
      (s->scene.dpLocale == "zh-TW"? "預測轉角" : s->scene.dpLocale == "zh-CN"? "预测转角" : "DESIR STEER"),
      bb_rx, bb_ry, bb_uom_dx,
      val_color, lab_color, uom_color,
      value_fontSize, label_fontSize, uom_fontSize );
    bb_ry = bb_y + bb_h;
  }

  //finally draw the frame
  bb_h += 20;
  nvgBeginPath(s->vg);
    nvgRoundedRect(s->vg, bb_x, bb_y, bb_w, bb_h, 20);
    nvgStrokeColor(s->vg, COLOR_WHITE_ALPHA(80));
    nvgStrokeWidth(s->vg, 6);
    nvgStroke(s->vg);
}

void ui_draw_bbui(UIState *s) {
    const int bb_dml_w = 184;
    const int bb_dml_x = s->scene.viz_rect.x + (bdr_s*2);
    const int bb_dml_y = s->scene.viz_rect.y + (bdr_s*1.5) + 220;
    const int bb_dmr_w = 184;
    const int bb_dmr_x =s->scene.viz_rect.x + s->scene.viz_rect.w - bb_dmr_w - (bdr_s * 2);
    const int bb_dmr_y = s->scene.viz_rect.y + (bdr_s*1.5) + 220;

    bb_ui_draw_measures_right(s, bb_dml_x, bb_dml_y, bb_dml_w);
    bb_ui_draw_measures_left(s, bb_dmr_x, bb_dmr_y, bb_dmr_w);
}