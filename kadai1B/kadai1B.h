#ifndef _KADAI1B_DEF_ /* _KADAI1B_DEF_ が定義されていなければ以下を読み込む．*/
#define _KADAI1B_DEF_ /* _KADAI1B_DEF_ を定義する＝次回は読み込まれない．*/
#include "kadai1A.h"
#include "Struct.h"

// 関数プロトタイプ宣言
// 矢印図形の点を読み込む
void InputDatFile(POINT p[], char *fname, double loop);
// Gnuplotで開く（Unix, Linux用）
int OpenGnuplot();
// 点数分ループして外部ファイルに書き込む
void OutputDatFile(char *fname, POINT p[], double loop);

// 課題1Bの1用のpltファイル作成
void OutputRotatePlt(char *fname);
// 引数にとった変換行列を矢印図形の点に施す
void CalcRotationMat(POINT input[], POINT output[], double rotation_mat[][VEC_SIZE], int loop);
// 課題1Bの1(a)の解答作成
void rotateXYZ(double r_x, double r_y, double r_z);
// 課題1Bの1(b)の解答作成
void rotateYZX(double r_x, double r_y, double r_z);

// 任意の原点位置と任意の軸方向を持つ新たな座標系をランダムに作成
AXIS randCoordinateAxis();
// 新たな座標系をプロットするためのデータ作成
AXIS OutputRandomAxis();
// 課題1Bの2用のpltファイル作成
void OutPutPlt_kadai2(char *fname);
// 範囲と所望の小数点以下の桁数を指定して乱数を得る
double GetRandom(double min, double max, int digit);

// 矢印図形の座標を新たな座標から見たときの値を得る
void CoordinateTransform(AXIS axis);
// 課題1Bの3用のpltファイル作成
void OutPutPlt_kadai3(char *fname);

// ランダムに作成した座標系を基準座標系に一致させる
void CoordinateTransformToOrigin(AXIS axis);
// 課題1Bの4用のpltファイル作成
void OutPutPlt_kadai4(char *fname);

// 課題1Bの3と課題1Bの4の計算結果確認
void TransformToOriginVector(AXIS axis);
// 課題1Bの5用のpltファイル作成
void OutPutPlt_kadai5(char *fname);
#endif