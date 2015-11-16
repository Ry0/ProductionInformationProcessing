#ifndef _KADAI1B_DEF_ /* _KADAI1B_DEF_ が定義されていなければ以下を読み込む．*/
#define _KADAI1B_DEF_ /* _KADAI1B_DEF_ を定義する＝次回は読み込まれない．*/
#include "kadai1A.h"
#include "Struct.h"

// 関数プロトタイプ宣言
void InputDatFile(POINT p[], char *fname);
int OpenGnuplot();
void OutputDatFile(char *fname, POINT p[]);
void OutputRotatePlt(char *fname);
void CalcRotationMat(POINT input[], POINT output[], double rotation_mat[][VEC_SIZE]);

void rotateXYZ(double r_x, double r_y, double r_z);
void rotateYZX(double r_x, double r_y, double r_z);

AXIS randCoordinateAxis();
AXIS OutputRandomAxis();
void OutPutPlt_kadai2(char *fname);
double GetRandom(double min, double max, int digit);
void CoordinateTransform(AXIS axis);
void OutPutPlt_kadai3(char *fname);
void CoordinateTransformToOrigin(AXIS axis);
void OutPutPlt_kadai4(char *fname);
#endif