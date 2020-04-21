from cereal import car
from selfdrive.car import make_can_msg


GearShifter = car.CarState.GearShifter
VisualAlert = car.CarControl.HUDControl.VisualAlert

def calc_checksum(data):
  """This function does not want the checksum byte in the input data.

  jeep chrysler canbus checksum from http://illmatics.com/Remote%20Car%20Hacking.pdf
  """
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


def create_lkas_command(packer, apply_steer, lkas_active, frame):
  # LKAS_COMMAND 0x1f6 (502) Lane-keeping signal to turn the wheel.
  values = {
    "LKAS_STEERING_TORQUE": apply_steer,
    "LKAS_STATE": 2 if lkas_active else 0,
    "COUNTER": frame % 0x10,
  }

  dat = packer.make_can_msg("LKAS_COMMAND", 0, values)[2]
  checksum = calc_checksum(dat)

  values["CHECKSUM"] = checksum
  return packer.make_can_msg("LKAS_COMMAND", 0, values)


def create_lkas_hud_command(packer, enabled, left_lane_visible, right_lane_visible):
  # Chrysler came up with this scheme, not me
  if enabled:
    if left_lane_visible:
      if right_lane_visible:
        lane_visibility_signal = 0x6  # Both sides white
      else:
        lane_visibility_signal = 0x2  # Left only white
    elif right_lane_visible:
      lane_visibility_signal = 0x3    # Right only white
    else:
      lane_visibility_signal = 0x1    # Neither lane border shown
  else:
    lane_visibility_signal = 0x1      # Neither lane border shown

  values = {
    "SET_ME_0XAC": 0xAC,
    "LKAS_ICON_COLOR": 2 if enabled else 1,
    "LKAS_LANE_LINES": lane_visibility_signal,
  }

  return packer.make_can_msg("LKAS_HUD", 0, values)


def create_wheel_buttons(frame):
  # WHEEL_BUTTONS (762) Message sent to cancel ACC.
  start = b"\x01"  # acc cancel set
  counter = (frame % 10) << 4
  dat = start + counter.to_bytes(1, 'little') + b"\x00"
  dat = dat[:-1] + calc_checksum(dat).to_bytes(1, 'little')
  return make_can_msg(0x2fa, dat, 0)
