from cereal import car
from selfdrive.car import make_can_msg


GearShifter = car.CarState.GearShifter
VisualAlert = car.CarControl.HUDControl.VisualAlert

def create_lkas_command(packer, apply_steer, lkas_active, frame):

  values = {
    "LKAS_COMMAND": apply_steer,
    "LKAS_COMMAND_BIT": 1 if lkas_active else 0,
    "COUNTER": frame % 0x10,
  }

  return packer.make_can_msg("LKAS_COMMAND", 0, values)


def create_lkas_hud(packer, enabled, leftLaneVisible, rightLaneVisible):
  # Chrysler came up with this scheme, not me
  if enabled:
    if leftLaneVisible:
      if rightLaneVisible:
        lane_visibility_signal = 0x3  # Both sides white
      else:
        lane_visibility_signal = 0x9  # Left only white (GUESS, trying yellows for fun)
    elif rightLaneVisible:
      lane_visibility_signal = 0xA    # Right only white (GUESS, trying yellows for fun)
    else:
      lane_visibility_signal = 0x4    # Neither lane border shown
  else:
    lane_visibility_signal = 0x4      # Neither lane border shown

  values = {
    "LKAS_LANE_LINES": lane_visibility_signal,
  }

  return packer.make_can_msg("LKAS_HUD", 0, values)


def create_wheel_buttons(packer, frame, cancel=False):

  values = {
    "CANCEL": cancel,
    "COUNTER": frame % 0x10
  }
  return packer.make_can_msg("WHEEL_BUTTONS", 0, values)
