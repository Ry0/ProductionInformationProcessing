#ifndef _KADAI2A_DEF_
#define _KADAI2A_DEF_
#include "kadai1A.h"
#include "Struct.h"

// 関数プロトタイプ宣言
void InputDatFile(POINT p[], char *fname, double loop);
void set_tetra(double vs[][VEC_SIZE]);
void set_triprism(double vs[][VEC_SIZE], double h);
void norm_triangle(double n[VEC_SIZE], double v0[VEC_SIZE], double v1[VEC_SIZE], double v2[VEC_SIZE]);
void prStlProlog(char *label, FILE *fp);
void prStlEpilog(char *label, FILE *fp);
void prStlFacet(double n[VEC_SIZE], double v0[VEC_SIZE], double v1[VEC_SIZE], double v2[VEC_SIZE], FILE *fp);
void prStlTetra(double vs[][VEC_SIZE], char *label);
void prStlTriprism(double vs[][VEC_SIZE], char *label);
void stlb_k01(double tt[TETRA_V_NUM][VEC_SIZE], double tp[TRIPRISM_V_NUM][VEC_SIZE]);

#endif