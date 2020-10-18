
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
 *                       Code generated with sympy 1.4                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2809217384291272992) {
   out_2809217384291272992[0] = delta_x[0] + nom_x[0];
   out_2809217384291272992[1] = delta_x[1] + nom_x[1];
   out_2809217384291272992[2] = delta_x[2] + nom_x[2];
   out_2809217384291272992[3] = delta_x[3] + nom_x[3];
   out_2809217384291272992[4] = delta_x[4] + nom_x[4];
   out_2809217384291272992[5] = delta_x[5] + nom_x[5];
   out_2809217384291272992[6] = delta_x[6] + nom_x[6];
   out_2809217384291272992[7] = delta_x[7] + nom_x[7];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2981736501010019884) {
   out_2981736501010019884[0] = -nom_x[0] + true_x[0];
   out_2981736501010019884[1] = -nom_x[1] + true_x[1];
   out_2981736501010019884[2] = -nom_x[2] + true_x[2];
   out_2981736501010019884[3] = -nom_x[3] + true_x[3];
   out_2981736501010019884[4] = -nom_x[4] + true_x[4];
   out_2981736501010019884[5] = -nom_x[5] + true_x[5];
   out_2981736501010019884[6] = -nom_x[6] + true_x[6];
   out_2981736501010019884[7] = -nom_x[7] + true_x[7];
}
void H_mod_fun(double *state, double *out_8072095683805606583) {
   out_8072095683805606583[0] = 1.0;
   out_8072095683805606583[1] = 0.0;
   out_8072095683805606583[2] = 0.0;
   out_8072095683805606583[3] = 0.0;
   out_8072095683805606583[4] = 0.0;
   out_8072095683805606583[5] = 0.0;
   out_8072095683805606583[6] = 0.0;
   out_8072095683805606583[7] = 0.0;
   out_8072095683805606583[8] = 0.0;
   out_8072095683805606583[9] = 1.0;
   out_8072095683805606583[10] = 0.0;
   out_8072095683805606583[11] = 0.0;
   out_8072095683805606583[12] = 0.0;
   out_8072095683805606583[13] = 0.0;
   out_8072095683805606583[14] = 0.0;
   out_8072095683805606583[15] = 0.0;
   out_8072095683805606583[16] = 0.0;
   out_8072095683805606583[17] = 0.0;
   out_8072095683805606583[18] = 1.0;
   out_8072095683805606583[19] = 0.0;
   out_8072095683805606583[20] = 0.0;
   out_8072095683805606583[21] = 0.0;
   out_8072095683805606583[22] = 0.0;
   out_8072095683805606583[23] = 0.0;
   out_8072095683805606583[24] = 0.0;
   out_8072095683805606583[25] = 0.0;
   out_8072095683805606583[26] = 0.0;
   out_8072095683805606583[27] = 1.0;
   out_8072095683805606583[28] = 0.0;
   out_8072095683805606583[29] = 0.0;
   out_8072095683805606583[30] = 0.0;
   out_8072095683805606583[31] = 0.0;
   out_8072095683805606583[32] = 0.0;
   out_8072095683805606583[33] = 0.0;
   out_8072095683805606583[34] = 0.0;
   out_8072095683805606583[35] = 0.0;
   out_8072095683805606583[36] = 1.0;
   out_8072095683805606583[37] = 0.0;
   out_8072095683805606583[38] = 0.0;
   out_8072095683805606583[39] = 0.0;
   out_8072095683805606583[40] = 0.0;
   out_8072095683805606583[41] = 0.0;
   out_8072095683805606583[42] = 0.0;
   out_8072095683805606583[43] = 0.0;
   out_8072095683805606583[44] = 0.0;
   out_8072095683805606583[45] = 1.0;
   out_8072095683805606583[46] = 0.0;
   out_8072095683805606583[47] = 0.0;
   out_8072095683805606583[48] = 0.0;
   out_8072095683805606583[49] = 0.0;
   out_8072095683805606583[50] = 0.0;
   out_8072095683805606583[51] = 0.0;
   out_8072095683805606583[52] = 0.0;
   out_8072095683805606583[53] = 0.0;
   out_8072095683805606583[54] = 1.0;
   out_8072095683805606583[55] = 0.0;
   out_8072095683805606583[56] = 0.0;
   out_8072095683805606583[57] = 0.0;
   out_8072095683805606583[58] = 0.0;
   out_8072095683805606583[59] = 0.0;
   out_8072095683805606583[60] = 0.0;
   out_8072095683805606583[61] = 0.0;
   out_8072095683805606583[62] = 0.0;
   out_8072095683805606583[63] = 1.0;
}
void f_fun(double *state, double dt, double *out_4156636253923627282) {
   out_4156636253923627282[0] = state[0];
   out_4156636253923627282[1] = state[1];
   out_4156636253923627282[2] = state[2];
   out_4156636253923627282[3] = state[3];
   out_4156636253923627282[4] = state[4];
   out_4156636253923627282[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4156636253923627282[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4156636253923627282[7] = state[7];
}
void F_fun(double *state, double dt, double *out_3231416446681736674) {
   out_3231416446681736674[0] = 1;
   out_3231416446681736674[1] = 0;
   out_3231416446681736674[2] = 0;
   out_3231416446681736674[3] = 0;
   out_3231416446681736674[4] = 0;
   out_3231416446681736674[5] = 0;
   out_3231416446681736674[6] = 0;
   out_3231416446681736674[7] = 0;
   out_3231416446681736674[8] = 0;
   out_3231416446681736674[9] = 1;
   out_3231416446681736674[10] = 0;
   out_3231416446681736674[11] = 0;
   out_3231416446681736674[12] = 0;
   out_3231416446681736674[13] = 0;
   out_3231416446681736674[14] = 0;
   out_3231416446681736674[15] = 0;
   out_3231416446681736674[16] = 0;
   out_3231416446681736674[17] = 0;
   out_3231416446681736674[18] = 1;
   out_3231416446681736674[19] = 0;
   out_3231416446681736674[20] = 0;
   out_3231416446681736674[21] = 0;
   out_3231416446681736674[22] = 0;
   out_3231416446681736674[23] = 0;
   out_3231416446681736674[24] = 0;
   out_3231416446681736674[25] = 0;
   out_3231416446681736674[26] = 0;
   out_3231416446681736674[27] = 1;
   out_3231416446681736674[28] = 0;
   out_3231416446681736674[29] = 0;
   out_3231416446681736674[30] = 0;
   out_3231416446681736674[31] = 0;
   out_3231416446681736674[32] = 0;
   out_3231416446681736674[33] = 0;
   out_3231416446681736674[34] = 0;
   out_3231416446681736674[35] = 0;
   out_3231416446681736674[36] = 1;
   out_3231416446681736674[37] = 0;
   out_3231416446681736674[38] = 0;
   out_3231416446681736674[39] = 0;
   out_3231416446681736674[40] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3231416446681736674[41] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3231416446681736674[42] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3231416446681736674[43] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3231416446681736674[44] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3231416446681736674[45] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3231416446681736674[46] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3231416446681736674[47] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3231416446681736674[48] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3231416446681736674[49] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3231416446681736674[50] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3231416446681736674[51] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3231416446681736674[52] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3231416446681736674[53] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3231416446681736674[54] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3231416446681736674[55] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3231416446681736674[56] = 0;
   out_3231416446681736674[57] = 0;
   out_3231416446681736674[58] = 0;
   out_3231416446681736674[59] = 0;
   out_3231416446681736674[60] = 0;
   out_3231416446681736674[61] = 0;
   out_3231416446681736674[62] = 0;
   out_3231416446681736674[63] = 1;
}
void h_25(double *state, double *unused, double *out_1759326584237918919) {
   out_1759326584237918919[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7863579586782473303) {
   out_7863579586782473303[0] = 0;
   out_7863579586782473303[1] = 0;
   out_7863579586782473303[2] = 0;
   out_7863579586782473303[3] = 0;
   out_7863579586782473303[4] = 0;
   out_7863579586782473303[5] = 0;
   out_7863579586782473303[6] = 1;
   out_7863579586782473303[7] = 0;
}
void h_24(double *state, double *unused, double *out_4445684052584453825) {
   out_4445684052584453825[0] = state[4];
   out_4445684052584453825[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6918178916859259661) {
   out_6918178916859259661[0] = 0;
   out_6918178916859259661[1] = 0;
   out_6918178916859259661[2] = 0;
   out_6918178916859259661[3] = 0;
   out_6918178916859259661[4] = 1;
   out_6918178916859259661[5] = 0;
   out_6918178916859259661[6] = 0;
   out_6918178916859259661[7] = 0;
   out_6918178916859259661[8] = 0;
   out_6918178916859259661[9] = 0;
   out_6918178916859259661[10] = 0;
   out_6918178916859259661[11] = 0;
   out_6918178916859259661[12] = 0;
   out_6918178916859259661[13] = 1;
   out_6918178916859259661[14] = 0;
   out_6918178916859259661[15] = 0;
}
void h_30(double *state, double *unused, double *out_385015536119413093) {
   out_385015536119413093[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4002921020342718675) {
   out_4002921020342718675[0] = 0;
   out_4002921020342718675[1] = 0;
   out_4002921020342718675[2] = 0;
   out_4002921020342718675[3] = 0;
   out_4002921020342718675[4] = 1;
   out_4002921020342718675[5] = 0;
   out_4002921020342718675[6] = 0;
   out_4002921020342718675[7] = 0;
}
void h_26(double *state, double *unused, double *out_5415222148889480958) {
   out_5415222148889480958[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5290590580464996913) {
   out_5290590580464996913[0] = 0;
   out_5290590580464996913[1] = 0;
   out_5290590580464996913[2] = 0;
   out_5290590580464996913[3] = 0;
   out_5290590580464996913[4] = 0;
   out_5290590580464996913[5] = 0;
   out_5290590580464996913[6] = 0;
   out_5290590580464996913[7] = 1;
}
void h_27(double *state, double *unused, double *out_2644360634393622154) {
   out_2644360634393622154[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2363788311988709773) {
   out_2363788311988709773[0] = 0;
   out_2363788311988709773[1] = 0;
   out_2363788311988709773[2] = 0;
   out_2363788311988709773[3] = 1;
   out_2363788311988709773[4] = 0;
   out_2363788311988709773[5] = 0;
   out_2363788311988709773[6] = 0;
   out_2363788311988709773[7] = 0;
}
void h_29(double *state, double *unused, double *out_4082005415037866792) {
   out_4082005415037866792[0] = state[1];
}
void H_29(double *state, double *unused, double *out_91811548013215321) {
   out_91811548013215321[0] = 0;
   out_91811548013215321[1] = 1;
   out_91811548013215321[2] = 0;
   out_91811548013215321[3] = 0;
   out_91811548013215321[4] = 0;
   out_91811548013215321[5] = 0;
   out_91811548013215321[6] = 0;
   out_91811548013215321[7] = 0;
}
void h_28(double *state, double *unused, double *out_7428015859060285921) {
   out_7428015859060285921[0] = state[5];
   out_7428015859060285921[1] = state[6];
}
void H_28(double *state, double *unused, double *out_2579750413018912057) {
   out_2579750413018912057[0] = 0;
   out_2579750413018912057[1] = 0;
   out_2579750413018912057[2] = 0;
   out_2579750413018912057[3] = 0;
   out_2579750413018912057[4] = 0;
   out_2579750413018912057[5] = 1;
   out_2579750413018912057[6] = 0;
   out_2579750413018912057[7] = 0;
   out_2579750413018912057[8] = 0;
   out_2579750413018912057[9] = 0;
   out_2579750413018912057[10] = 0;
   out_2579750413018912057[11] = 0;
   out_2579750413018912057[12] = 0;
   out_2579750413018912057[13] = 0;
   out_2579750413018912057[14] = 1;
   out_2579750413018912057[15] = 0;
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
