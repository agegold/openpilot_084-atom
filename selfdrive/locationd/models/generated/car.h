#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_6794414375964694935);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4965874880230950163);
void car_H_mod_fun(double *state, double *out_115105067992891312);
void car_f_fun(double *state, double dt, double *out_145699177934463875);
void car_F_fun(double *state, double dt, double *out_7199420307757486723);
void car_h_25(double *state, double *unused, double *out_1175039779966115340);
void car_H_25(double *state, double *unused, double *out_6461952481212246671);
void car_h_24(double *state, double *unused, double *out_7784659497477428053);
void car_H_24(double *state, double *unused, double *out_5150481817446977335);
void car_h_30(double *state, double *unused, double *out_5045337402880898629);
void car_H_30(double *state, double *unused, double *out_3151946429736936609);
void car_h_26(double *state, double *unused, double *out_7649742723689596280);
void car_H_26(double *state, double *unused, double *out_6280198437558095672);
void car_h_27(double *state, double *unused, double *out_3826633487694730305);
void car_H_27(double *state, double *unused, double *out_4439528417573561921);
void car_h_29(double *state, double *unused, double *out_3936631769125942136);
void car_H_29(double *state, double *unused, double *out_2577387815881400434);
void car_h_28(double *state, double *unused, double *out_3852180941182248080);
void car_H_28(double *state, double *unused, double *out_6278429778026079415);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}