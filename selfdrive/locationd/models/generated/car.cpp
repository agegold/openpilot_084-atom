#include "car.h"

namespace {
#define DIM 8
#define EDIM 8
#define MEDIM 8
typedef void (*Hfun)(double *, double *, double *);

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
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 5.991464547107981;

/******************************************************************************
 *                      Code generated with sympy 1.7.1                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_6794414375964694935) {
   out_6794414375964694935[0] = delta_x[0] + nom_x[0];
   out_6794414375964694935[1] = delta_x[1] + nom_x[1];
   out_6794414375964694935[2] = delta_x[2] + nom_x[2];
   out_6794414375964694935[3] = delta_x[3] + nom_x[3];
   out_6794414375964694935[4] = delta_x[4] + nom_x[4];
   out_6794414375964694935[5] = delta_x[5] + nom_x[5];
   out_6794414375964694935[6] = delta_x[6] + nom_x[6];
   out_6794414375964694935[7] = delta_x[7] + nom_x[7];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4965874880230950163) {
   out_4965874880230950163[0] = -nom_x[0] + true_x[0];
   out_4965874880230950163[1] = -nom_x[1] + true_x[1];
   out_4965874880230950163[2] = -nom_x[2] + true_x[2];
   out_4965874880230950163[3] = -nom_x[3] + true_x[3];
   out_4965874880230950163[4] = -nom_x[4] + true_x[4];
   out_4965874880230950163[5] = -nom_x[5] + true_x[5];
   out_4965874880230950163[6] = -nom_x[6] + true_x[6];
   out_4965874880230950163[7] = -nom_x[7] + true_x[7];
}
void H_mod_fun(double *state, double *out_115105067992891312) {
   out_115105067992891312[0] = 1.0;
   out_115105067992891312[1] = 0.0;
   out_115105067992891312[2] = 0.0;
   out_115105067992891312[3] = 0.0;
   out_115105067992891312[4] = 0.0;
   out_115105067992891312[5] = 0.0;
   out_115105067992891312[6] = 0.0;
   out_115105067992891312[7] = 0.0;
   out_115105067992891312[8] = 0.0;
   out_115105067992891312[9] = 1.0;
   out_115105067992891312[10] = 0.0;
   out_115105067992891312[11] = 0.0;
   out_115105067992891312[12] = 0.0;
   out_115105067992891312[13] = 0.0;
   out_115105067992891312[14] = 0.0;
   out_115105067992891312[15] = 0.0;
   out_115105067992891312[16] = 0.0;
   out_115105067992891312[17] = 0.0;
   out_115105067992891312[18] = 1.0;
   out_115105067992891312[19] = 0.0;
   out_115105067992891312[20] = 0.0;
   out_115105067992891312[21] = 0.0;
   out_115105067992891312[22] = 0.0;
   out_115105067992891312[23] = 0.0;
   out_115105067992891312[24] = 0.0;
   out_115105067992891312[25] = 0.0;
   out_115105067992891312[26] = 0.0;
   out_115105067992891312[27] = 1.0;
   out_115105067992891312[28] = 0.0;
   out_115105067992891312[29] = 0.0;
   out_115105067992891312[30] = 0.0;
   out_115105067992891312[31] = 0.0;
   out_115105067992891312[32] = 0.0;
   out_115105067992891312[33] = 0.0;
   out_115105067992891312[34] = 0.0;
   out_115105067992891312[35] = 0.0;
   out_115105067992891312[36] = 1.0;
   out_115105067992891312[37] = 0.0;
   out_115105067992891312[38] = 0.0;
   out_115105067992891312[39] = 0.0;
   out_115105067992891312[40] = 0.0;
   out_115105067992891312[41] = 0.0;
   out_115105067992891312[42] = 0.0;
   out_115105067992891312[43] = 0.0;
   out_115105067992891312[44] = 0.0;
   out_115105067992891312[45] = 1.0;
   out_115105067992891312[46] = 0.0;
   out_115105067992891312[47] = 0.0;
   out_115105067992891312[48] = 0.0;
   out_115105067992891312[49] = 0.0;
   out_115105067992891312[50] = 0.0;
   out_115105067992891312[51] = 0.0;
   out_115105067992891312[52] = 0.0;
   out_115105067992891312[53] = 0.0;
   out_115105067992891312[54] = 1.0;
   out_115105067992891312[55] = 0.0;
   out_115105067992891312[56] = 0.0;
   out_115105067992891312[57] = 0.0;
   out_115105067992891312[58] = 0.0;
   out_115105067992891312[59] = 0.0;
   out_115105067992891312[60] = 0.0;
   out_115105067992891312[61] = 0.0;
   out_115105067992891312[62] = 0.0;
   out_115105067992891312[63] = 1.0;
}
void f_fun(double *state, double dt, double *out_145699177934463875) {
   out_145699177934463875[0] = state[0];
   out_145699177934463875[1] = state[1];
   out_145699177934463875[2] = state[2];
   out_145699177934463875[3] = state[3];
   out_145699177934463875[4] = state[4];
   out_145699177934463875[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_145699177934463875[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_145699177934463875[7] = state[7];
}
void F_fun(double *state, double dt, double *out_7199420307757486723) {
   out_7199420307757486723[0] = 1;
   out_7199420307757486723[1] = 0;
   out_7199420307757486723[2] = 0;
   out_7199420307757486723[3] = 0;
   out_7199420307757486723[4] = 0;
   out_7199420307757486723[5] = 0;
   out_7199420307757486723[6] = 0;
   out_7199420307757486723[7] = 0;
   out_7199420307757486723[8] = 0;
   out_7199420307757486723[9] = 1;
   out_7199420307757486723[10] = 0;
   out_7199420307757486723[11] = 0;
   out_7199420307757486723[12] = 0;
   out_7199420307757486723[13] = 0;
   out_7199420307757486723[14] = 0;
   out_7199420307757486723[15] = 0;
   out_7199420307757486723[16] = 0;
   out_7199420307757486723[17] = 0;
   out_7199420307757486723[18] = 1;
   out_7199420307757486723[19] = 0;
   out_7199420307757486723[20] = 0;
   out_7199420307757486723[21] = 0;
   out_7199420307757486723[22] = 0;
   out_7199420307757486723[23] = 0;
   out_7199420307757486723[24] = 0;
   out_7199420307757486723[25] = 0;
   out_7199420307757486723[26] = 0;
   out_7199420307757486723[27] = 1;
   out_7199420307757486723[28] = 0;
   out_7199420307757486723[29] = 0;
   out_7199420307757486723[30] = 0;
   out_7199420307757486723[31] = 0;
   out_7199420307757486723[32] = 0;
   out_7199420307757486723[33] = 0;
   out_7199420307757486723[34] = 0;
   out_7199420307757486723[35] = 0;
   out_7199420307757486723[36] = 1;
   out_7199420307757486723[37] = 0;
   out_7199420307757486723[38] = 0;
   out_7199420307757486723[39] = 0;
   out_7199420307757486723[40] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7199420307757486723[41] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7199420307757486723[42] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7199420307757486723[43] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7199420307757486723[44] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7199420307757486723[45] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7199420307757486723[46] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7199420307757486723[47] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7199420307757486723[48] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7199420307757486723[49] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7199420307757486723[50] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7199420307757486723[51] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7199420307757486723[52] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7199420307757486723[53] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7199420307757486723[54] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7199420307757486723[55] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7199420307757486723[56] = 0;
   out_7199420307757486723[57] = 0;
   out_7199420307757486723[58] = 0;
   out_7199420307757486723[59] = 0;
   out_7199420307757486723[60] = 0;
   out_7199420307757486723[61] = 0;
   out_7199420307757486723[62] = 0;
   out_7199420307757486723[63] = 1;
}
void h_25(double *state, double *unused, double *out_1175039779966115340) {
   out_1175039779966115340[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6461952481212246671) {
   out_6461952481212246671[0] = 0;
   out_6461952481212246671[1] = 0;
   out_6461952481212246671[2] = 0;
   out_6461952481212246671[3] = 0;
   out_6461952481212246671[4] = 0;
   out_6461952481212246671[5] = 0;
   out_6461952481212246671[6] = 1;
   out_6461952481212246671[7] = 0;
}
void h_24(double *state, double *unused, double *out_7784659497477428053) {
   out_7784659497477428053[0] = state[4];
   out_7784659497477428053[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5150481817446977335) {
   out_5150481817446977335[0] = 0;
   out_5150481817446977335[1] = 0;
   out_5150481817446977335[2] = 0;
   out_5150481817446977335[3] = 0;
   out_5150481817446977335[4] = 1;
   out_5150481817446977335[5] = 0;
   out_5150481817446977335[6] = 0;
   out_5150481817446977335[7] = 0;
   out_5150481817446977335[8] = 0;
   out_5150481817446977335[9] = 0;
   out_5150481817446977335[10] = 0;
   out_5150481817446977335[11] = 0;
   out_5150481817446977335[12] = 0;
   out_5150481817446977335[13] = 1;
   out_5150481817446977335[14] = 0;
   out_5150481817446977335[15] = 0;
}
void h_30(double *state, double *unused, double *out_5045337402880898629) {
   out_5045337402880898629[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3151946429736936609) {
   out_3151946429736936609[0] = 0;
   out_3151946429736936609[1] = 0;
   out_3151946429736936609[2] = 0;
   out_3151946429736936609[3] = 0;
   out_3151946429736936609[4] = 1;
   out_3151946429736936609[5] = 0;
   out_3151946429736936609[6] = 0;
   out_3151946429736936609[7] = 0;
}
void h_26(double *state, double *unused, double *out_7649742723689596280) {
   out_7649742723689596280[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6280198437558095672) {
   out_6280198437558095672[0] = 0;
   out_6280198437558095672[1] = 0;
   out_6280198437558095672[2] = 0;
   out_6280198437558095672[3] = 0;
   out_6280198437558095672[4] = 0;
   out_6280198437558095672[5] = 0;
   out_6280198437558095672[6] = 0;
   out_6280198437558095672[7] = 1;
}
void h_27(double *state, double *unused, double *out_3826633487694730305) {
   out_3826633487694730305[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4439528417573561921) {
   out_4439528417573561921[0] = 0;
   out_4439528417573561921[1] = 0;
   out_4439528417573561921[2] = 0;
   out_4439528417573561921[3] = 1;
   out_4439528417573561921[4] = 0;
   out_4439528417573561921[5] = 0;
   out_4439528417573561921[6] = 0;
   out_4439528417573561921[7] = 0;
}
void h_29(double *state, double *unused, double *out_3936631769125942136) {
   out_3936631769125942136[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2577387815881400434) {
   out_2577387815881400434[0] = 0;
   out_2577387815881400434[1] = 1;
   out_2577387815881400434[2] = 0;
   out_2577387815881400434[3] = 0;
   out_2577387815881400434[4] = 0;
   out_2577387815881400434[5] = 0;
   out_2577387815881400434[6] = 0;
   out_2577387815881400434[7] = 0;
}
void h_28(double *state, double *unused, double *out_3852180941182248080) {
   out_3852180941182248080[0] = state[5];
   out_3852180941182248080[1] = state[6];
}
void H_28(double *state, double *unused, double *out_6278429778026079415) {
   out_6278429778026079415[0] = 0;
   out_6278429778026079415[1] = 0;
   out_6278429778026079415[2] = 0;
   out_6278429778026079415[3] = 0;
   out_6278429778026079415[4] = 0;
   out_6278429778026079415[5] = 1;
   out_6278429778026079415[6] = 0;
   out_6278429778026079415[7] = 0;
   out_6278429778026079415[8] = 0;
   out_6278429778026079415[9] = 0;
   out_6278429778026079415[10] = 0;
   out_6278429778026079415[11] = 0;
   out_6278429778026079415[12] = 0;
   out_6278429778026079415[13] = 0;
   out_6278429778026079415[14] = 1;
   out_6278429778026079415[15] = 0;
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




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_6794414375964694935) {
  err_fun(nom_x, delta_x, out_6794414375964694935);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4965874880230950163) {
  inv_err_fun(nom_x, true_x, out_4965874880230950163);
}
void car_H_mod_fun(double *state, double *out_115105067992891312) {
  H_mod_fun(state, out_115105067992891312);
}
void car_f_fun(double *state, double dt, double *out_145699177934463875) {
  f_fun(state,  dt, out_145699177934463875);
}
void car_F_fun(double *state, double dt, double *out_7199420307757486723) {
  F_fun(state,  dt, out_7199420307757486723);
}
void car_h_25(double *state, double *unused, double *out_1175039779966115340) {
  h_25(state, unused, out_1175039779966115340);
}
void car_H_25(double *state, double *unused, double *out_6461952481212246671) {
  H_25(state, unused, out_6461952481212246671);
}
void car_h_24(double *state, double *unused, double *out_7784659497477428053) {
  h_24(state, unused, out_7784659497477428053);
}
void car_H_24(double *state, double *unused, double *out_5150481817446977335) {
  H_24(state, unused, out_5150481817446977335);
}
void car_h_30(double *state, double *unused, double *out_5045337402880898629) {
  h_30(state, unused, out_5045337402880898629);
}
void car_H_30(double *state, double *unused, double *out_3151946429736936609) {
  H_30(state, unused, out_3151946429736936609);
}
void car_h_26(double *state, double *unused, double *out_7649742723689596280) {
  h_26(state, unused, out_7649742723689596280);
}
void car_H_26(double *state, double *unused, double *out_6280198437558095672) {
  H_26(state, unused, out_6280198437558095672);
}
void car_h_27(double *state, double *unused, double *out_3826633487694730305) {
  h_27(state, unused, out_3826633487694730305);
}
void car_H_27(double *state, double *unused, double *out_4439528417573561921) {
  H_27(state, unused, out_4439528417573561921);
}
void car_h_29(double *state, double *unused, double *out_3936631769125942136) {
  h_29(state, unused, out_3936631769125942136);
}
void car_H_29(double *state, double *unused, double *out_2577387815881400434) {
  H_29(state, unused, out_2577387815881400434);
}
void car_h_28(double *state, double *unused, double *out_3852180941182248080) {
  h_28(state, unused, out_3852180941182248080);
}
void car_H_28(double *state, double *unused, double *out_6278429778026079415) {
  H_28(state, unused, out_6278429778026079415);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
