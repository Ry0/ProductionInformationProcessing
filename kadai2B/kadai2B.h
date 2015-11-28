#ifndef _KADAI2B_DEF_
#define _KADAI2B_DEF_
#include "kadai.h"

// 関数プロトタイプ宣言
// ロボットアームの順運動学計算(各関節角度とリンクのパラメータ指定)
void ForwardKinematics(double joint[], double link[]);
// 各軸での座標系を作成→外部ファイルに保存
void ShowTfAxis(double joint[], double link[]);
// リンク自体の骨格モデルを出力
void ArmOutputdat(double P[][VEC_SIZE]);
// 各軸での座標系を可視化するためのファイル作成補助
void TfAxisOutputdat(double P[][VEC_SIZE], FILE *fpx, FILE *fpy, FILE *fpz);
// リンクのモデルを出力→Gnuplotで可視化
void OutputPlt();
// 各リンクのパーツをSTL形式で出力
void OutputSTL(double part1[][VEC_SIZE], double part2[][VEC_SIZE], double part3[][VEC_SIZE]);
// 与えられた関節角度とリンク長からアームの姿勢を求め、STLで出力
void LinkCreator(double joint[], double link[]);
// リンクの初期姿勢を定義
void set_arm(double Origin[][VEC_SIZE], double P[][VEC_SIZE], double h);
#endif