/******************************************************************************
 *                       Code generated with sympy 1.4                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_872055017041804073);
void inv_err_fun(double *nom_x, double *true_x, double *out_2844492246864994567);
void H_mod_fun(double *state, double *out_3619723129803921531);
void f_fun(double *state, double dt, double *out_1296836878313129334);
void F_fun(double *state, double dt, double *out_5900604665297940072);
void h_3(double *state, double *unused, double *out_1341918834527073852);
void H_3(double *state, double *unused, double *out_3923295115772764531);
void h_4(double *state, double *unused, double *out_553352119909718295);
void H_4(double *state, double *unused, double *out_4404178482434149888);
void h_9(double *state, double *unused, double *out_5220285040225264075);
void H_9(double *state, double *unused, double *out_7099425674030517455);
void h_10(double *state, double *unused, double *out_6588524772605745679);
void H_10(double *state, double *unused, double *out_5946563582132722973);
void h_12(double *state, double *unused, double *out_2167829224528241361);
void H_12(double *state, double *unused, double *out_3312677211493766367);
void h_31(double *state, double *unused, double *out_6196282786613463962);
void H_31(double *state, double *unused, double *out_2543757257586220265);
void h_32(double *state, double *unused, double *out_1472772939099179575);
void H_32(double *state, double *unused, double *out_1757456171194773087);
void h_13(double *state, double *unused, double *out_4626389887167706415);
void H_13(double *state, double *unused, double *out_1032831083681672928);
void h_14(double *state, double *unused, double *out_5220285040225264075);
void H_14(double *state, double *unused, double *out_7099425674030517455);
void h_19(double *state, double *unused, double *out_440169351022142149);
void H_19(double *state, double *unused, double *out_5022551225516909653);
#define DIM 23
#define EDIM 22
#define MEDIM 22
typedef void (*Hfun)(double *, double *, double *);

void predict(double *x, double *P, double *Q, double dt);
const static double MAHA_THRESH_3 = 3.841459;
void update_3(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814728;
void update_4(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_9 = 7.814728;
void update_9(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_10 = 7.814728;
void update_10(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_12 = 7.814728;
void update_12(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_31 = 7.814728;
void update_31(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_32 = 9.487729;
void update_32(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_13 = 7.814728;
void update_13(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_14 = 7.814728;
void update_14(double *, double *, double *, double *, double *);
const static double MAHA_THRESH_19 = 7.814728;
void update_19(double *, double *, double *, double *, double *);