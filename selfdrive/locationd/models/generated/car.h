/******************************************************************************
 *                       Code generated with sympy 1.4                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2809217384291272992);
void inv_err_fun(double *nom_x, double *true_x, double *out_2981736501010019884);
void H_mod_fun(double *state, double *out_8072095683805606583);
void f_fun(double *state, double dt, double *out_4156636253923627282);
void F_fun(double *state, double dt, double *out_3231416446681736674);
void h_25(double *state, double *unused, double *out_1759326584237918919);
void H_25(double *state, double *unused, double *out_7863579586782473303);
void h_24(double *state, double *unused, double *out_4445684052584453825);
void H_24(double *state, double *unused, double *out_6918178916859259661);
void h_30(double *state, double *unused, double *out_385015536119413093);
void H_30(double *state, double *unused, double *out_4002921020342718675);
void h_26(double *state, double *unused, double *out_5415222148889480958);
void H_26(double *state, double *unused, double *out_5290590580464996913);
void h_27(double *state, double *unused, double *out_2644360634393622154);
void H_27(double *state, double *unused, double *out_2363788311988709773);
void h_29(double *state, double *unused, double *out_4082005415037866792);
void H_29(double *state, double *unused, double *out_91811548013215321);
void h_28(double *state, double *unused, double *out_7428015859060285921);
void H_28(double *state, double *unused, double *out_2579750413018912057);
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
void set_mass(double x);

void set_rotational_inertia(double x);

void set_center_to_front(double x);

void set_center_to_rear(double x);

void set_stiffness_front(double x);

void set_stiffness_rear(double x);
