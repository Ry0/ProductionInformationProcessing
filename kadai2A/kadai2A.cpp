#include "kadai2A.h"

void InputDatFile(POINT p[], char *fname, double loop){
  FILE *fp;

  fp = fopen( fname, "r" );
  if( fp == NULL ){
    printf( "%sのファイルが開けません\n", fname);
  }else{
    for (int i = 0; i < loop; ++i){
      if(fscanf( fp, "%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z)==-1){
        printf("読み込み失敗");
      }
    }
  }
  fclose(fp);
}

void set_tetra(double vs[][VEC_SIZE]){

  char inputfile[128] = "../plot/tetra_point.dat";
  POINT input[TETRA_V_NUM];
  InputDatFile(input,inputfile, TETRA_V_NUM);

  for (int i = 0; i < TETRA_V_NUM; ++i){
    setVec4h(vs[i], input[i].x, input[i].y, input[i].z);
  }
}


