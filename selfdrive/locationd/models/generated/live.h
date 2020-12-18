/******************************************************************************
 *                      Code generated with sympy 1.6.1                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8680723169111583427);
void inv_err_fun(double *nom_x, double *true_x, double *out_8030541474345762116);
void H_mod_fun(double *state, double *out_831903554494119469);
void f_fun(double *state, double dt, double *out_8652852597943887247);
void F_fun(double *state, double dt, double *out_8715965156717236270);
void h_3(double *state, double *unused, double *out_3247619132161614652);
void H_3(double *state, double *unused, double *out_4653057169336529389);
void h_4(double *state, double *unused, double *out_622269861216751591);
void H_4(double *state, double *unused, double *out_6317692102257916586);
void h_9(double *state, double *unused, double *out_5764346910103385082);
void H_9(double *state, double *unused, double *out_2760517138945922235);
void h_10(double *state, double *unused, double *out_7573994800501577430);
void H_10(double *state, double *unused, double *out_7458504513183532270);
void h_12(double *state, double *unused, double *out_7104002267080192327);
void H_12(double *state, double *unused, double *out_2976467171077568636);
void h_31(double *state, double *unused, double *out_539676067371629330);
void H_31(double *state, double *unused, double *out_5651556946220988457);
void h_32(double *state, double *unused, double *out_6397132823198346148);
void H_32(double *state, double *unused, double *out_1224796389244945219);
void h_13(double *state, double *unused, double *out_2518028625548635807);
void H_13(double *state, double *unused, double *out_2754467763905958774);
void h_14(double *state, double *unused, double *out_5764346910103385082);
void H_14(double *state, double *unused, double *out_2760517138945922235);
void h_19(double *state, double *unused, double *out_7587316989505843337);
void H_19(double *state, double *unused, double *out_1672162712156508946);
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