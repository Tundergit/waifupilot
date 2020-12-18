/******************************************************************************
 *                      Code generated with sympy 1.6.1                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7524464719748708808);
void inv_err_fun(double *nom_x, double *true_x, double *out_1558768042767918504);
void H_mod_fun(double *state, double *out_993377696544324830);
void f_fun(double *state, double dt, double *out_3609951793038521014);
void F_fun(double *state, double dt, double *out_484525123358720524);
void h_25(double *state, double *unused, double *out_7728221392612537098);
void H_25(double *state, double *unused, double *out_4563146508729378763);
void h_24(double *state, double *unused, double *out_7303276734898634321);
void H_24(double *state, double *unused, double *out_3112606582906491158);
void h_30(double *state, double *unused, double *out_3947687454746663582);
void H_30(double *state, double *unused, double *out_5050752402219804517);
void h_26(double *state, double *unused, double *out_1967943298987198754);
void H_26(double *state, double *unused, double *out_8179004410040963580);
void h_27(double *state, double *unused, double *out_2312865861452787865);
void H_27(double *state, double *unused, double *out_6338334390056429829);
void h_29(double *state, double *unused, double *out_910901403302330897);
void H_29(double *state, double *unused, double *out_2569835500270588483);
void h_28(double *state, double *unused, double *out_6337450355621233509);
void H_28(double *state, double *unused, double *out_8316305012566565592);
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
