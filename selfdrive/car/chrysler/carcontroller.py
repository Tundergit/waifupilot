from selfdrive.car import apply_std_steer_torque_limits
from selfdrive.car.chrysler.chryslercan import create_lkas_command, create_lkas_hud_command, create_wheel_buttons
from selfdrive.car.chrysler.values import CAR, DBC, CarControllerParams
from opendbc.can.packer import CANPacker

class CarController():
  def __init__(self, dbc_name, CP, VM):
    self.braking = False
    self.hud_count = 0
    self.car_fingerprint = CP.carFingerprint
    self.alert_active = False
    self.gone_fast_yet = False
    self.apply_steer_last = 0
    self.steer_rate_limited = False

    self.packer = CANPacker(DBC[CP.carFingerprint]['pt'])


  def update(self, enabled, CS, frame, actuators, pcm_cancel_cmd, left_lane_visble, right_lane_visible): #TODO hud_alert
    P = CarControllerParams

    # *** compute control surfaces ***

    moving_fast = CS.out.vEgo > CS.CP.minSteerSpeed  # for status message

    if moving_fast:
      new_steer = int(round(actuators.steer * P.STEER_MAX))
    else:
      new_steer = 0

    apply_steer = apply_std_steer_torque_limits(new_steer, self.apply_steer_last, CS.out.steeringTorque, P)
    self.steer_rate_limited = new_steer != apply_steer
    self.apply_steer_last = apply_steer

    #*** control msgs ***

    can_sends = []

    if frame % P.STEER_STEP == 0:
      can_sends.append(create_lkas_command(self.packer, int(apply_steer), moving_fast, frame))

    if frame % P.HUD_STEP == 0:
      can_sends.append(create_lkas_hud_command(self.packer, enabled, left_lane_visble, right_lane_visible))

    # FIXME: restore cruise control button spam cancellation after we're further along in development
    # if pcm_cancel_cmd:
    #   new_msg = create_wheel_buttons(CS.frame_23b)
    #   can_sends.append(new_msg)

    return can_sends
