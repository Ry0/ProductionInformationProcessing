#ifndef _STRUCT_DEF_
#define _STRUCT_DEF_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

#define VEC_SIZE 4 // ベクトルのサイズ
#define TETRA_V_NUM 4
#define TRIPRISM_V_NUM 6

// #define DEBUG // デバッグ用のprintfを出力するか

#endif