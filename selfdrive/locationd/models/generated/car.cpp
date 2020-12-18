
extern "C"{

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}

}
extern "C" {
#include <math.h>
/******************************************************************************
 *                      Code generated with sympy 1.6.1                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7524464719748708808) {
   out_7524464719748708808[0] = delta_x[0] + nom_x[0];
   out_7524464719748708808[1] = delta_x[1] + nom_x[1];
   out_7524464719748708808[2] = delta_x[2] + nom_x[2];
   out_7524464719748708808[3] = delta_x[3] + nom_x[3];
   out_7524464719748708808[4] = delta_x[4] + nom_x[4];
   out_7524464719748708808[5] = delta_x[5] + nom_x[5];
   out_7524464719748708808[6] = delta_x[6] + nom_x[6];
   out_7524464719748708808[7] = delta_x[7] + nom_x[7];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1558768042767918504) {
   out_1558768042767918504[0] = -nom_x[0] + true_x[0];
   out_1558768042767918504[1] = -nom_x[1] + true_x[1];
   out_1558768042767918504[2] = -nom_x[2] + true_x[2];
   out_1558768042767918504[3] = -nom_x[3] + true_x[3];
   out_1558768042767918504[4] = -nom_x[4] + true_x[4];
   out_1558768042767918504[5] = -nom_x[5] + true_x[5];
   out_1558768042767918504[6] = -nom_x[6] + true_x[6];
   out_1558768042767918504[7] = -nom_x[7] + true_x[7];
}
void H_mod_fun(double *state, double *out_993377696544324830) {
   out_993377696544324830[0] = 1.0;
   out_993377696544324830[1] = 0.0;
   out_993377696544324830[2] = 0.0;
   out_993377696544324830[3] = 0.0;
   out_993377696544324830[4] = 0.0;
   out_993377696544324830[5] = 0.0;
   out_993377696544324830[6] = 0.0;
   out_993377696544324830[7] = 0.0;
   out_993377696544324830[8] = 0.0;
   out_993377696544324830[9] = 1.0;
   out_993377696544324830[10] = 0.0;
   out_993377696544324830[11] = 0.0;
   out_993377696544324830[12] = 0.0;
   out_993377696544324830[13] = 0.0;
   out_993377696544324830[14] = 0.0;
   out_993377696544324830[15] = 0.0;
   out_993377696544324830[16] = 0.0;
   out_993377696544324830[17] = 0.0;
   out_993377696544324830[18] = 1.0;
   out_993377696544324830[19] = 0.0;
   out_993377696544324830[20] = 0.0;
   out_993377696544324830[21] = 0.0;
   out_993377696544324830[22] = 0.0;
   out_993377696544324830[23] = 0.0;
   out_993377696544324830[24] = 0.0;
   out_993377696544324830[25] = 0.0;
   out_993377696544324830[26] = 0.0;
   out_993377696544324830[27] = 1.0;
   out_993377696544324830[28] = 0.0;
   out_993377696544324830[29] = 0.0;
   out_993377696544324830[30] = 0.0;
   out_993377696544324830[31] = 0.0;
   out_993377696544324830[32] = 0.0;
   out_993377696544324830[33] = 0.0;
   out_993377696544324830[34] = 0.0;
   out_993377696544324830[35] = 0.0;
   out_993377696544324830[36] = 1.0;
   out_993377696544324830[37] = 0.0;
   out_993377696544324830[38] = 0.0;
   out_993377696544324830[39] = 0.0;
   out_993377696544324830[40] = 0.0;
   out_993377696544324830[41] = 0.0;
   out_993377696544324830[42] = 0.0;
   out_993377696544324830[43] = 0.0;
   out_993377696544324830[44] = 0.0;
   out_993377696544324830[45] = 1.0;
   out_993377696544324830[46] = 0.0;
   out_993377696544324830[47] = 0.0;
   out_993377696544324830[48] = 0.0;
   out_993377696544324830[49] = 0.0;
   out_993377696544324830[50] = 0.0;
   out_993377696544324830[51] = 0.0;
   out_993377696544324830[52] = 0.0;
   out_993377696544324830[53] = 0.0;
   out_993377696544324830[54] = 1.0;
   out_993377696544324830[55] = 0.0;
   out_993377696544324830[56] = 0.0;
   out_993377696544324830[57] = 0.0;
   out_993377696544324830[58] = 0.0;
   out_993377696544324830[59] = 0.0;
   out_993377696544324830[60] = 0.0;
   out_993377696544324830[61] = 0.0;
   out_993377696544324830[62] = 0.0;
   out_993377696544324830[63] = 1.0;
}
void f_fun(double *state, double dt, double *out_3609951793038521014) {
   out_3609951793038521014[0] = state[0];
   out_3609951793038521014[1] = state[1];
   out_3609951793038521014[2] = state[2];
   out_3609951793038521014[3] = state[3];
   out_3609951793038521014[4] = state[4];
   out_3609951793038521014[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3609951793038521014[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3609951793038521014[7] = state[7];
}
void F_fun(double *state, double dt, double *out_484525123358720524) {
   out_484525123358720524[0] = 1;
   out_484525123358720524[1] = 0;
   out_484525123358720524[2] = 0;
   out_484525123358720524[3] = 0;
   out_484525123358720524[4] = 0;
   out_484525123358720524[5] = 0;
   out_484525123358720524[6] = 0;
   out_484525123358720524[7] = 0;
   out_484525123358720524[8] = 0;
   out_484525123358720524[9] = 1;
   out_484525123358720524[10] = 0;
   out_484525123358720524[11] = 0;
   out_484525123358720524[12] = 0;
   out_484525123358720524[13] = 0;
   out_484525123358720524[14] = 0;
   out_484525123358720524[15] = 0;
   out_484525123358720524[16] = 0;
   out_484525123358720524[17] = 0;
   out_484525123358720524[18] = 1;
   out_484525123358720524[19] = 0;
   out_484525123358720524[20] = 0;
   out_484525123358720524[21] = 0;
   out_484525123358720524[22] = 0;
   out_484525123358720524[23] = 0;
   out_484525123358720524[24] = 0;
   out_484525123358720524[25] = 0;
   out_484525123358720524[26] = 0;
   out_484525123358720524[27] = 1;
   out_484525123358720524[28] = 0;
   out_484525123358720524[29] = 0;
   out_484525123358720524[30] = 0;
   out_484525123358720524[31] = 0;
   out_484525123358720524[32] = 0;
   out_484525123358720524[33] = 0;
   out_484525123358720524[34] = 0;
   out_484525123358720524[35] = 0;
   out_484525123358720524[36] = 1;
   out_484525123358720524[37] = 0;
   out_484525123358720524[38] = 0;
   out_484525123358720524[39] = 0;
   out_484525123358720524[40] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_484525123358720524[41] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_484525123358720524[42] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_484525123358720524[43] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_484525123358720524[44] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_484525123358720524[45] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_484525123358720524[46] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_484525123358720524[47] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_484525123358720524[48] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_484525123358720524[49] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_484525123358720524[50] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_484525123358720524[51] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_484525123358720524[52] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_484525123358720524[53] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_484525123358720524[54] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_484525123358720524[55] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_484525123358720524[56] = 0;
   out_484525123358720524[57] = 0;
   out_484525123358720524[58] = 0;
   out_484525123358720524[59] = 0;
   out_484525123358720524[60] = 0;
   out_484525123358720524[61] = 0;
   out_484525123358720524[62] = 0;
   out_484525123358720524[63] = 1;
}
void h_25(double *state, double *unused, double *out_7728221392612537098) {
   out_7728221392612537098[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4563146508729378763) {
   out_4563146508729378763[0] = 0;
   out_4563146508729378763[1] = 0;
   out_4563146508729378763[2] = 0;
   out_4563146508729378763[3] = 0;
   out_4563146508729378763[4] = 0;
   out_4563146508729378763[5] = 0;
   out_4563146508729378763[6] = 1;
   out_4563146508729378763[7] = 0;
}
void h_24(double *state, double *unused, double *out_7303276734898634321) {
   out_7303276734898634321[0] = state[4];
   out_7303276734898634321[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3112606582906491158) {
   out_3112606582906491158[0] = 0;
   out_3112606582906491158[1] = 0;
   out_3112606582906491158[2] = 0;
   out_3112606582906491158[3] = 0;
   out_3112606582906491158[4] = 1;
   out_3112606582906491158[5] = 0;
   out_3112606582906491158[6] = 0;
   out_3112606582906491158[7] = 0;
   out_3112606582906491158[8] = 0;
   out_3112606582906491158[9] = 0;
   out_3112606582906491158[10] = 0;
   out_3112606582906491158[11] = 0;
   out_3112606582906491158[12] = 0;
   out_3112606582906491158[13] = 1;
   out_3112606582906491158[14] = 0;
   out_3112606582906491158[15] = 0;
}
void h_30(double *state, double *unused, double *out_3947687454746663582) {
   out_3947687454746663582[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5050752402219804517) {
   out_5050752402219804517[0] = 0;
   out_5050752402219804517[1] = 0;
   out_5050752402219804517[2] = 0;
   out_5050752402219804517[3] = 0;
   out_5050752402219804517[4] = 1;
   out_5050752402219804517[5] = 0;
   out_5050752402219804517[6] = 0;
   out_5050752402219804517[7] = 0;
}
void h_26(double *state, double *unused, double *out_1967943298987198754) {
   out_1967943298987198754[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8179004410040963580) {
   out_8179004410040963580[0] = 0;
   out_8179004410040963580[1] = 0;
   out_8179004410040963580[2] = 0;
   out_8179004410040963580[3] = 0;
   out_8179004410040963580[4] = 0;
   out_8179004410040963580[5] = 0;
   out_8179004410040963580[6] = 0;
   out_8179004410040963580[7] = 1;
}
void h_27(double *state, double *unused, double *out_2312865861452787865) {
   out_2312865861452787865[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6338334390056429829) {
   out_6338334390056429829[0] = 0;
   out_6338334390056429829[1] = 0;
   out_6338334390056429829[2] = 0;
   out_6338334390056429829[3] = 1;
   out_6338334390056429829[4] = 0;
   out_6338334390056429829[5] = 0;
   out_6338334390056429829[6] = 0;
   out_6338334390056429829[7] = 0;
}
void h_29(double *state, double *unused, double *out_910901403302330897) {
   out_910901403302330897[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2569835500270588483) {
   out_2569835500270588483[0] = 0;
   out_2569835500270588483[1] = 1;
   out_2569835500270588483[2] = 0;
   out_2569835500270588483[3] = 0;
   out_2569835500270588483[4] = 0;
   out_2569835500270588483[5] = 0;
   out_2569835500270588483[6] = 0;
   out_2569835500270588483[7] = 0;
}
void h_28(double *state, double *unused, double *out_6337450355621233509) {
   out_6337450355621233509[0] = state[5];
   out_6337450355621233509[1] = state[6];
}
void H_28(double *state, double *unused, double *out_8316305012566565592) {
   out_8316305012566565592[0] = 0;
   out_8316305012566565592[1] = 0;
   out_8316305012566565592[2] = 0;
   out_8316305012566565592[3] = 0;
   out_8316305012566565592[4] = 0;
   out_8316305012566565592[5] = 1;
   out_8316305012566565592[6] = 0;
   out_8316305012566565592[7] = 0;
   out_8316305012566565592[8] = 0;
   out_8316305012566565592[9] = 0;
   out_8316305012566565592[10] = 0;
   out_8316305012566565592[11] = 0;
   out_8316305012566565592[12] = 0;
   out_8316305012566565592[13] = 0;
   out_8316305012566565592[14] = 1;
   out_8316305012566565592[15] = 0;
}
}

extern "C"{
#define DIM 8
#define EDIM 8
#define MEDIM 8
typedef void (*Hfun)(double *, double *, double *);

void predict(double *x, double *P, double *Q, double dt);
const static double MAHA_THRESH_25 = 3.841459;
void update_25(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_24 = 5.991465;
void update_24(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_30 = 3.841459;
void update_30(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_26 = 3.841459;
void update_26(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_27 = 3.841459;
void update_27(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_29 = 3.841459;
void update_29(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_28 = 5.991465;
void update_28(double *, double *, double *, double *, double *);
}

#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}



extern "C"{

      void update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<1,3,0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
      }
    
      void update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<2,3,0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
      }
    
      void update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<1,3,0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
      }
    
      void update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<1,3,0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
      }
    
      void update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<1,3,0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
      }
    
      void update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<1,3,0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
      }
    
      void update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
        update<2,3,0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
      }
    
}
