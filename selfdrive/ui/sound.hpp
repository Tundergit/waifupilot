#pragma once
#include <map>
#include "cereal/gen/cpp/log.capnp.h"

typedef cereal::CarControl::HUDControl::AudibleAlert AudibleAlert;

static std::map<AudibleAlert, std::pair<const char *, int>> sound_map {
  // AudibleAlert, (file path, loop count)
  {AudibleAlert::CHIME_DISENGAGE, {"../assets/sounds/disengaged.wav", 1}},
  {AudibleAlert::CHIME_ENGAGE, {"../assets/sounds/engaged.wav", 1}},
  {AudibleAlert::CHIME_WARNING1, {"../assets/sounds/warning_1.wav", 1}},
  {AudibleAlert::CHIME_WARNING2, {"../assets/sounds/warning_2.wav", 1}},
  {AudibleAlert::CHIME_WARNING2_REPEAT, {"../assets/sounds/warning_2.wav", 3}},
  {AudibleAlert::CHIME_WARNING_REPEAT, {"../assets/sounds/warning_repeat.wav", -1}},
  {AudibleAlert::CHIME_ERROR, {"../assets/sounds/error.wav", 1}},
  {AudibleAlert::CHIME_PROMPT, {"../assets/sounds/error.wav", 1}}
};

class Sound {
public:
  virtual bool play(AudibleAlert alert) = 0;
  virtual void stop() = 0;
  virtual void setVolume(int volume) = 0;
};
