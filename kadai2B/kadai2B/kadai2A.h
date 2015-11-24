
#ifndef _KADAI2A_DEF_
#define _KADAI2A_DEF_
#include "kadai.h"

// 関数プロトタイプ宣言
// 立体用データを外部ファイルから読み込む
void InputDatFile(POINT p[], char *fname, double loop);
// データから立体を表す座標を２次元配列に格納(四面体用)
void set_tetra(double vs[][VEC_SIZE]);
// データから立体を表す座標を２次元配列に格納(三角柱用)
void set_triprism(double vs[][VEC_SIZE], double h);
// 外向き法線ベクトル作成
void norm_triangle(double n[VEC_SIZE], double v0[VEC_SIZE], double v1[VEC_SIZE], double v2[VEC_SIZE]);
// STL形式の開始行を作成
void prStlProlog(char *label, FILE *fp);
// STL形式の終了行を作成
void prStlEpilog(char *label, FILE *fp);
// STL形式の三角形パッチを作成
void prStlFacet(double n[VEC_SIZE], double v0[VEC_SIZE], double v1[VEC_SIZE], double v2[VEC_SIZE], FILE *fp);
// 外向き法線方向に右ねじが進む方向の点の組み合わせ作成(四面体用)
void CombinationTetra(double vs[][VEC_SIZE], FILE *fp);
// STL形式の四面体作成
void prStlTetra(double vs[][VEC_SIZE], char *label);
// 外向き法線方向に右ねじが進む方向の点の組み合わせ作成(三角柱用)
void CombinationTriprism(double vs[][VEC_SIZE], FILE *fp);
// STL形式の三角柱作成
void prStlTriprism(double vs[][VEC_SIZE], char *label);
// 四面体と三角柱をSTL形式でそれぞれ作成 (課題2Aの1)
void stlb_k01(double tt[TETRA_V_NUM][VEC_SIZE], double tp[TRIPRISM_V_NUM][VEC_SIZE]);

// 範囲と所望の小数点以下の桁数を指定して乱数を得る
double GetRandom(double min, double max, int digit);
// 任意の原点位置と任意の軸方向を持つ新たな座標系をランダムに作成
AXIS randCoordinateAxis();
// 引数にとった変換行列を立体を表現している座標群に施す
void CalcRotationMat(POINT input[], POINT output[], double rotation_mat[][VEC_SIZE], int loop);
// 取る引数(label)によって欲しい立体(四面体か三角柱用)をランダムな座標系で作成
void TransformPosition(char *label, FILE *fp);
// 課題2Aの2を実行する
void TransformPositionAll(char *label);
#endif