#ifndef _KADAI2B_DEF_
#define _KADAI2B_DEF_
#include "kadai1A.h"
#include "kadai2A.h"
#include "Struct.h"

// 関数プロトタイプ宣言
void ForwardKinematics(double joint[], double link[]);
void ShowTfAxis(double joint[], double link[]);
void ArmOutputdat(double P[][VEC_SIZE]);
void TfAxisOutputdat(double P[][VEC_SIZE], FILE *fpx, FILE *fpy, FILE *fpz);
void OutputPlt();
void OutputSTL(double part1[][VEC_SIZE], double part2[][VEC_SIZE], double part3[][VEC_SIZE]);
void LinkCreator(double joint[], double link[]);
void set_arm(double Origin[][VEC_SIZE], double P[][VEC_SIZE], double h);
#endif