#ifndef _KADAI1B_DEF_ /* _KADAI1B_DEF_ が定義されていなければ以下を読み込む．*/
#define _KADAI1B_DEF_ /* _KADAI1B_DEF_ を定義する＝次回は読み込まれない．*/
#include "kadai1A.h"
#include "Struct.h"

// 関数プロトタイプ宣言
void InputDatFile(POINT p[], char *fname, double loop);
int OpenGnuplot();
void OutputDatFile(char *fname, POINT p[], double loop);
void OutputRotatePlt(char *fname);
void CalcRotationMat(POINT input[], POINT output[], double rotation_mat[][VEC_SIZE], int loop);

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
void TransformToOriginVector(AXIS axis);
void OutPutPlt_kadai5(char *fname);
#endif