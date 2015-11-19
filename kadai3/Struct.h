#ifndef _STRUCT_DEF_
#define _STRUCT_DEF_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct{
  double x;
  double y;
  double z;
} POINT;

typedef struct{
  POINT x_axis;
  POINT y_axis;
  POINT z_axis;
  POINT origin;
} AXIS;

#define HDIM 4 // 同次座標表現の次数
#define BDIM 3 // ベジエ曲線・曲面の次数

// #define DEBUG // デバッグ用のprintfを出力するか

void set_param_vector(double pv[BDIM+1], double t);
void mulMVb(double u[BDIM+1], double mb[BDIM+1][BDIM+1], double v[BDIM+1]);
void mulLCpVb(double u[HDIM], double cps[BDIM+1][HDIM], double v[BDIM+1]);
void on_bezier3_curve(double q[HDIM], double mb[BDIM+1][BDIM+1], double cps[BDIM+1][HDIM],
double t);
void mulMCpVb(double lcp[BDIM+1][HDIM], double mcp[BDIM+1][BDIM+1][HDIM], double v[BDIM+1]);
void on_bezier3_surface(double q[HDIM], double mb[BDIM+1][BDIM+1], double cps[BDIM+1][BDIM+1][HDIM], double u, double v);
#endif