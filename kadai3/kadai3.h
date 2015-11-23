#ifndef _KADAI3_DEF_ /* _KADAI3_DEF_ が定義されていなければ以下を読み込む．*/
#define _KADAI3_DEF_ /* _KADAI3_DEF_ を定義する＝次回は読み込まれない．*/
#include "kadai.h"

// 関数プロトタイプ宣言
void set_param_vector(double pv[BDIM+1], double t);
void mulMVb(double u[BDIM+1], double mb[BDIM+1][BDIM+1], double v[BDIM+1]);
void mulLCpVb(double u[HDIM], double cps[HDIM][BDIM+1], double v[BDIM+1]);
void on_bezier3_curve(double q[HDIM], double mb[BDIM+1][BDIM+1], double cps[BDIM+1][HDIM], double t);
void draw_bezier3();

void mulMCpVb(double lcp[BDIM+1][HDIM], double mcp[BDIM+1][BDIM+1][HDIM], double v[BDIM+1]);
void InputDatFile(double p[BDIM+1][BDIM+1][HDIM], char *fname);
void on_bezier3_surface(double q[HDIM], double mb[BDIM+1][BDIM+1], double cps[BDIM+1][BDIM+1][HDIM], double u, double v);
void calc_M_tPM(double output[BDIM+1][BDIM+1][HDIM], double input[BDIM+1][BDIM+1][HDIM], double M[BDIM+1][BDIM+1]);
void draw_bezier3_surface();

int OpenGnuplot();
#endif