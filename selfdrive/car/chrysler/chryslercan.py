from cereal import car
from selfdrive.car import make_can_msg


GearShifter = car.CarState.GearShifter
VisualAlert = car.CarControl.HUDControl.VisualAlert

def calc_checksum(data):

  checksum = 0xFF
  for curr in data[:-1]:
    shift = 0x80
    for i in range(0, 8):
      bit_sum = curr & shift
      temp_chk = checksum & 0x80
      if (bit_sum != 0):
        bit_sum = 0x1C
        if (temp_chk != 0):
          bit_sum = 1
        checksum = checksum << 1
        temp_chk = checksum | 1
        bit_sum ^= temp_chk
      else:
        if (temp_chk != 0):
          bit_sum = 0x1D
        checksum = checksum << 1
        bit_sum ^= checksum
      checksum = bit_sum
      shift = shift >> 1
  return ~checksum & 0xFF


def create_lkas_command(packer, apply_steer, steer_command_bit, frame):
  
  values = {
    "LKAS_COMMAND": apply_steer,
    "LKAS_COMMAND_BIT": int(steer_command_bit),
    "COUNTER": frame % 0x10,
  }

  dat = packer.make_can_msg("FORWARD_CAMERA_LKAS", 0, values)[2]
  checksum = calc_checksum(dat)

  values["CHECKSUM"] = checksum
  return packer.make_can_msg("FORWARD_CAMERA_LKAS", 0, values)

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
    "LKAS_HUD": lane_visibility_signal,
  }

  return packer.make_can_msg("FORWARD_CAMERA_HUD", 0, values)


def create_wheel_buttons(packer, frame, cancel=False):

  values = {
    "CANCEL": cancel,
    "COUNTER": frame % 0x10
  }
  return packer.make_can_msg("WHEEL_BUTTONS_CRUISE_CONTROL", 0, values)
