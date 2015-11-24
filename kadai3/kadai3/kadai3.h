#ifndef _KADAI3_DEF_ /* _KADAI3_DEF_ が定義されていなければ以下を読み込む．*/
#define _KADAI3_DEF_ /* _KADAI3_DEF_ を定義する＝次回は読み込まれない．*/
#include "kadai.h"

// 関数プロトタイプ宣言
// パラメータベクトル(t0, t1, t2, t3)
void set_param_vector(double pv[BDIM + 1], double t);
// 行列×ベクトルの演算
void mulMVb(double u[BDIM + 1], double mb[BDIM + 1][BDIM + 1], double v[BDIM + 1]);
// 制御点リスト×ベクトルの積
void mulLCpVb(double u[HDIM], double cps[HDIM][BDIM + 1], double v[BDIM + 1]);
// パラメータtのときのベジエ曲線上の点を求める
void on_bezier3_curve(double q[HDIM], double mb[BDIM + 1][BDIM + 1], double cps[BDIM + 1][HDIM], double t);
// ベジエ曲線を求める
void draw_bezier3();

// 制御点行列とベクトルの積を求める
void mulMCpVb(double lcp[BDIM + 1][HDIM], double mcp[BDIM + 1][BDIM + 1][HDIM], double v[BDIM + 1]);
// 制御点を外部ファイルから読み込む
void InputDatFile(double p[BDIM + 1][BDIM + 1][HDIM], char *fname);
// パラメータ(u,v)のときのベジエ曲面上の点を求める
void on_bezier3_surface(double q[HDIM], double mb[BDIM + 1][BDIM + 1], double cps[BDIM + 1][BDIM + 1][HDIM], double u, double v);
// M_B^T P M_B の行列を求める
void calc_M_tPM(double output[BDIM + 1][BDIM + 1][HDIM], double input[BDIM + 1][BDIM + 1][HDIM], double M[BDIM + 1][BDIM + 1]);
// パラメータを0から1に変化させて、曲面を求める
void draw_bezier3_surface();
// 結果をGnuplotで出力
int OpenGnuplot();
#endif