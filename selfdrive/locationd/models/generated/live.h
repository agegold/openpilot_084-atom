#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_3(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_19(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_2201508260629983479);
void live_err_fun(double *nom_x, double *delta_x, double *out_3850416414583513383);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_1892947755982964602);
void live_H_mod_fun(double *state, double *out_7780851748543260142);
void live_f_fun(double *state, double dt, double *out_3769333781718526477);
void live_F_fun(double *state, double dt, double *out_1729763283674739079);
void live_h_3(double *state, double *unused, double *out_3353047167857299366);
void live_H_3(double *state, double *unused, double *out_7704284618775886181);
void live_h_4(double *state, double *unused, double *out_3731407467059059273);
void live_H_4(double *state, double *unused, double *out_3807016261701761401);
void live_h_9(double *state, double *unused, double *out_3175977904054397406);
void live_H_9(double *state, double *unused, double *out_6129521805572617371);
void live_h_10(double *state, double *unused, double *out_6548272351265629293);
void live_H_10(double *state, double *unused, double *out_1781433089232890635);
void live_h_12(double *state, double *unused, double *out_4943029477807843125);
void live_H_12(double *state, double *unused, double *out_5913571773440970970);
void live_h_31(double *state, double *unused, double *out_6070517376616722132);
void live_H_31(double *state, double *unused, double *out_3238481998297551149);
void live_h_32(double *state, double *unused, double *out_5058031754322652356);
void live_H_32(double *state, double *unused, double *out_1287980276649799502);
void live_h_13(double *state, double *unused, double *out_1127049720547567833);
void live_H_13(double *state, double *unused, double *out_9000465482903538594);
void live_h_14(double *state, double *unused, double *out_3175977904054397406);
void live_H_14(double *state, double *unused, double *out_6129521805572617371);
void live_h_19(double *state, double *unused, double *out_2309558163756555640);
void live_H_19(double *state, double *unused, double *out_7884542417034503064);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}