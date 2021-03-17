from selfdrive.car import apply_std_steer_torque_limits
from selfdrive.car.chrysler.chryslercan import create_lkas_hud, create_lkas_command, \
  create_wheel_buttons
from selfdrive.car.chrysler.values import CAR, CarControllerParams
from opendbc.can.packer import CANPacker


class CarController():
  def __init__(self, dbc_name, CP, VM):
    self.apply_steer_last = 0
    self.braking = False
    self.alert_active = False
    self.hud_count = 0
    self.car_fingerprint = CP.carFingerprint
    self.steer_rate_limited = False
    self.prev_frame = -1
    self.steer_command_bit = 0

    self.packer = CANPacker(dbc_name)

  def update(self, enabled, CS, frame, actuators, pcm_cancel_cmd, leftLaneVisible,
             rightLaneVisible):  # TODO hud_alert
    P = CarControllerParams
    
    frame = CS.lkas_counter
    if self.prev_frame == frame:
      return []

    steer_ready = CS.out.vEgo > CS.CP.minSteerSpeed + 0.5
    
#    if CS.out.vEgo > CS.CP.minSteerSpeed:
#      self.steer_command_bit = 1
#    if CS.out.vEgo < CS.CP.minSteerSpeed:
#      self.steer_command_bit = 0
    bad_to_bone = enabled and steer_ready

    if bad_to_bone:
      new_steer = int(round(actuators.steer * P.STEER_MAX))
    else:
      new_steer = 0

    apply_steer = apply_std_steer_torque_limits(new_steer, self.apply_steer_last, CS.out.steeringTorque, P)
    self.steer_rate_limited = new_steer != apply_steer
    self.apply_steer_last = apply_steer

    # *** control msgs ***

    can_sends = []

    # *** control msgs ***

    #    if pcm_cancel_cmd:  # TODO: ENABLE ONCE STEERING WORKS
    #      new_msg = create_wheel_buttons(self.packer, self.frame, cancel=True)
    #      can_sends.append(new_msg)

    if frame % P.STEER_STEP == 0:
      can_sends.append(create_lkas_command(self.packer, int(apply_steer), frame))

    if frame % P.HUD_STEP == 0:
      can_sends.append(create_lkas_hud(self.packer, enabled, leftLaneVisible, rightLaneVisible))
    
#    self.prev_frame = frame 

    return can_sends
