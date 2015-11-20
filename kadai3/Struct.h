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

#define VEC_SIZE 4

#define HDIM 4 // 同次座標表現の次数
#define BDIM 3 // ベジエ曲線・曲面の次数

// #define DEBUG // デバッグ用のprintfを出力するか

#endif