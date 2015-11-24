#ifndef _KADAI1A_DEF_
#define _KADAI1A_DEF_
#include "Struct.h"

// 関数プロトタイプ宣言
/*------------------ ベクトルの基本演算 ---------------------*/
// ベクトルの中身確認
void printVec(double v[]);
// ベクトルの初期化
void setVec4h(double v[], double x, double y, double z);
//ベクトルの大きさ
double length4h(double v[]);
// 単位ベクトル
bool normalize4h(double u[], double v[]);
// 逆ベクトル
void negate4h(double u[], double v[]);
// ベクトル和
void add4h(double u[], double v[], double p[]);
// ベクトル差
void sub4h(double u[], double v[], double p[]);
// ベクトルの内積
double dot4h(double v0[], double v1[]);
// ベクトルの外積
void cross4h(double u[], double v0[], double v1[]);
// ベクトル間の角度
double angle4h(double v0[], double v1[]);
// 方向ベクトル化
void asDirVec4h(double v[]);
// 位置ベクトル化
void asDirVec4h(double v[]);
/*------------- 3次元用同次座標行列の各種演算 ----------------*/
// 行列の可視化
void printMat(double m[][VEC_SIZE]);
// 列ベクトルによる行列定義
void setMatCol4h(double a[][VEC_SIZE], double v0[], double v1[], double v2[], double p[]);
// 行列の積
void mulMM4h(double m01[][VEC_SIZE], double m0[][VEC_SIZE], double m1[][VEC_SIZE]);
// 行列とベクトルの積
void mulMV4h(double u[], double m[][VEC_SIZE], double v[]);
// 点列の変換
void map4h(double us[][VEC_SIZE], double m[][VEC_SIZE], double vs[][VEC_SIZE], int num);
/*-------- 3次元の同次座標変換行列 m を生成する関数 -----------*/
// 平行移動
void translate4h(double m[][VEC_SIZE], double v[]);
// 拡大縮小
void scale4h(double m[][VEC_SIZE], double a, double b, double c);
// XY 平面対称
void mirrorXY4h(double m[][VEC_SIZE]);
// YZ 平面対称
void mirrorYZ4h(double m[][VEC_SIZE]);
// ZX 平面対称
void mirrorZX4h(double m[][VEC_SIZE]);
// 原点対称
void mirrorO4h(double m[][VEC_SIZE]);
// X 軸中心回転
void rotateX4h(double m[][VEC_SIZE], double a); // X 軸正方向に右ねじが進む回転方向に a[rad] 回転.
												// Y 軸中心回転
void rotateY4h(double m[][VEC_SIZE], double a); // Y 軸正方向に右ねじが進む回転方向に a[rad] 回転.
												// Z 軸中心回転
void rotateZ4h(double m[][VEC_SIZE], double a); // Z 軸正方向に右ねじが進む回転方向に a[rad] 回転.
												// X 軸中心回転
void rotateXSC4h(double m[][VEC_SIZE], double sv, double cv);
// Y 軸中心回転
void rotateYSC4h(double m[][VEC_SIZE], double sv, double cv);
// Z 軸中心回転
void rotateZSC4h(double m[][VEC_SIZE], double sv, double cv);
// ゼロ行列
void zeroMat4h(double m[][VEC_SIZE]);
// 単位行列
void unitMat4h(double m[][VEC_SIZE]);
// 逆行列
void invMat4h(double im[][VEC_SIZE], double m[][VEC_SIZE]);
#endif