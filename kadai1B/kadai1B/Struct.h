#ifndef _STRUCT_DEF_
#define _STRUCT_DEF_

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

typedef struct {
	double x;
	double y;
	double z;
} POINT;

typedef struct {
	POINT x_axis;
	POINT y_axis;
	POINT z_axis;
	POINT origin;
} AXIS;

#define VEC_SIZE 4 // �x�N�g���̃T�C�Y
// #define DEBUG // �f�o�b�O�p��printf���o�͂��邩

#endif