#include "kadai2B.h"

#include <iostream>
using namespace std;

void ForwardKinematics(double joint[], double link[]){
  double LinkParam[6][4];
  double T0[VEC_SIZE][VEC_SIZE], T1[VEC_SIZE][VEC_SIZE], T2[VEC_SIZE][VEC_SIZE], T3[VEC_SIZE][VEC_SIZE], T4[VEC_SIZE][VEC_SIZE], T5[VEC_SIZE][VEC_SIZE];

  for (int i = 0; i < 2; ++i){
    setVec4h(LinkParam[i], 0, 0, link[i]);
    // cout << LinkParam[i][0] << ", " << LinkParam[i][1] << ", " << LinkParam[i][2] << ", " << LinkParam[i][3] << endl;
  }
  for (int i = 2; i < 6; ++i){
    setVec4h(LinkParam[i], 0, link[i], 0);
    // cout << LinkParam[i][0] << ", " << LinkParam[i][1] << ", " << LinkParam[i][2] << ", " << LinkParam[i][3] << endl;
  }

  rotateZ4h(T0, joint[0]);
  rotateX4h(T1, joint[1]);
  rotateY4h(T2, joint[2]);
  rotateX4h(T3, joint[3]);
  rotateY4h(T4, joint[4]);
  unitMat4h(T5);

  double T01[VEC_SIZE][VEC_SIZE], T012[VEC_SIZE][VEC_SIZE], T0123[VEC_SIZE][VEC_SIZE], T01234[VEC_SIZE][VEC_SIZE], T012345[VEC_SIZE][VEC_SIZE];

  translate4hnotInit(T0, LinkParam[0]);
  translate4hnotInit(T1, LinkParam[1]);
  translate4hnotInit(T2, LinkParam[2]);
  translate4hnotInit(T3, LinkParam[3]);
  translate4hnotInit(T4, LinkParam[4]);
  translate4hnotInit(T5, LinkParam[5]);

  mulMM4h(T01, T0, T1);
  mulMM4h(T012, T01, T2);
  mulMM4h(T0123, T012, T3);
  mulMM4h(T01234, T0123, T4);
  mulMM4h(T012345, T01234, T5);

  double P[7][VEC_SIZE] = {{0.0}};
  P[0][3] = 1.0;

  mulMV4h(P[1], T0, P[0]);
  mulMV4h(P[2], T01, P[0]);
  mulMV4h(P[3], T012, P[0]);
  mulMV4h(P[4], T0123, P[0]);
  mulMV4h(P[5], T01234, P[0]);
  mulMV4h(P[6], T012345, P[0]);

  ArmOutputdat(P);
}

void ShowTfAxis(double joint[], double link[]){
  double LinkParam[6][VEC_SIZE];
  double T0[VEC_SIZE][VEC_SIZE], T1[VEC_SIZE][VEC_SIZE], T2[VEC_SIZE][VEC_SIZE], T3[VEC_SIZE][VEC_SIZE], T4[VEC_SIZE][VEC_SIZE], T5[VEC_SIZE][VEC_SIZE];

  for (int i = 0; i < 2; ++i){
    setVec4h(LinkParam[i], 0, 0, link[i]);
    // cout << LinkParam[i][0] << ", " << LinkParam[i][1] << ", " << LinkParam[i][2] << ", " << LinkParam[i][3] << endl;
  }
  for (int i = 2; i < 6; ++i){
    setVec4h(LinkParam[i], 0, link[i], 0);
    // cout << LinkParam[i][0] << ", " << LinkParam[i][1] << ", " << LinkParam[i][2] << ", " << LinkParam[i][3] << endl;
  }

  rotateZ4h(T0, joint[0]);
  rotateX4h(T1, joint[1]);
  rotateY4h(T2, joint[2]);
  rotateX4h(T3, joint[3]);
  rotateY4h(T4, joint[4]);
  unitMat4h(T5);

  double T01[VEC_SIZE][VEC_SIZE], T012[VEC_SIZE][VEC_SIZE], T0123[VEC_SIZE][VEC_SIZE], T01234[VEC_SIZE][VEC_SIZE], T012345[VEC_SIZE][VEC_SIZE];

  translate4hnotInit(T0, LinkParam[0]);
  translate4hnotInit(T1, LinkParam[1]);
  translate4hnotInit(T2, LinkParam[2]);
  translate4hnotInit(T3, LinkParam[3]);
  translate4hnotInit(T4, LinkParam[4]);
  translate4hnotInit(T5, LinkParam[5]);

  mulMM4h(T01, T0, T1);
  mulMM4h(T012, T01, T2);
  mulMM4h(T0123, T012, T3);
  mulMM4h(T01234, T0123, T4);
  mulMM4h(T012345, T01234, T5);

  double P0[4][VEC_SIZE] = {{0.0, 0.0, 0.0, 1.0}, {0.3, 0.0, 0.0, 1.0}, {0.0, 0.3, 0.0, 1.0}, {0.0, 0.0, 0.3, 1.0}};
  double P1[4][VEC_SIZE], P2[5][VEC_SIZE], P3[5][VEC_SIZE], P4[5][VEC_SIZE], P5[5][VEC_SIZE], P6[5][VEC_SIZE];

  FILE *fpx, *fpy, *fpz;
  if((fpx = fopen("../plot/x.dat", "w"))==NULL ||
   (fpy = fopen("../plot/y.dat", "w"))==NULL ||
   (fpz = fopen("../plot/z.dat", "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    for (int i = 0; i < 4; ++i){
      mulMV4h(P1[i], T0, P0[i]);
      mulMV4h(P2[i], T01, P0[i]);
      mulMV4h(P3[i], T012, P0[i]);
      mulMV4h(P4[i], T0123, P0[i]);
      mulMV4h(P5[i], T01234, P0[i]);
      mulMV4h(P6[i], T012345, P0[i]);
    }
    TfAxisOutputdat(P0, fpx, fpy, fpz);
    TfAxisOutputdat(P1, fpx, fpy, fpz);
    TfAxisOutputdat(P2, fpx, fpy, fpz);
    TfAxisOutputdat(P3, fpx, fpy, fpz);
    TfAxisOutputdat(P4, fpx, fpy, fpz);
    TfAxisOutputdat(P5, fpx, fpy, fpz);
    TfAxisOutputdat(P6, fpx, fpy, fpz);
    fclose(fpx);fclose(fpy);fclose(fpz);
    OutputPlt();
  }
}

void ArmOutputdat(double P[][VEC_SIZE]){
  FILE *fp;
  if((fp = fopen("../plot/arm.dat", "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    for (int i = 0; i < 7; i++){
      fprintf(fp, "%lf %lf %lf\n", P[i][0], P[i][1], P[i][2]);
    }
  }
}


void TfAxisOutputdat(double P[][VEC_SIZE], FILE *fpx, FILE *fpy, FILE *fpz){

  fprintf(fpx, "%lf %lf %lf\n",      P[0][0], P[0][1], P[0][2]);
  fprintf(fpx, "%lf %lf %lf\n\n\n",  P[1][0],
                                     P[1][1],
                                     P[1][2]);

  fprintf(fpy, "%lf %lf %lf\n",      P[0][0], P[0][1], P[0][2]);
  fprintf(fpy, "%lf %lf %lf\n\n\n",  P[2][0],
                                     P[2][1],
                                     P[2][2]);

  fprintf(fpz, "%lf %lf %lf\n",      P[0][0], P[0][1], P[0][2]);
  fprintf(fpz, "%lf %lf %lf\n\n\n",  P[3][0],
                                     P[3][1],
                                     P[3][2]);
}


void OutputPlt(){
  FILE *fp;
  if((fp = fopen("../plot/plot.plt", "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    fprintf(fp, "reset\n");
    fprintf(fp, "set xlabel \'x\'\n");
    fprintf(fp, "set ylabel \'y\'\n");
    fprintf(fp, "set zlabel \'z\'\n");
    fprintf(fp, "set xrange[-5:5]\n");
    fprintf(fp, "set yrange[-5:5]\n");
    fprintf(fp, "set zrange[0:5]\n");
    fprintf(fp, "set view equal xyz\n");
    fprintf(fp, "set ticslevel 0\n");

    fprintf(fp, "splot \'arm.dat\' using 1:2:3 with lines lt 1 lc rgb \'#000000\' lw 3 title \'Arm\',\\\n");
    fprintf(fp, "\'x.dat\' using 1:2:3 with lines lt 1 lc rgb \'#FF412B\' lw 3 title \'X axis\',\\\n");
    fprintf(fp, "\'y.dat\' using 1:2:3 with lines lt 1 lc rgb \'#22BF2C\' lw 3 title \'Y axis\',\\\n");
    fprintf(fp, "\'z.dat\' using 1:2:3 with lines lt 1 lc rgb \'#4971E7\' lw 3 title \'Z axis\'\n");
    fclose(fp);
  }
}
