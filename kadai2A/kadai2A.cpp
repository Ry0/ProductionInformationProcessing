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


void set_tetra(double vs[][VEC_SIZE])
{
  char inputfile[128] = "../plot/tetra_point.dat";
  POINT input[TETRA_V_NUM];
  InputDatFile(input, inputfile, TETRA_V_NUM);

  for (int i = 0; i < TETRA_V_NUM; ++i){
    setVec4h(vs[i], input[i].x, input[i].y, input[i].z);
  }
}


void set_triprism(double vs[][VEC_SIZE], double h)
{
  char inputfile[128] = "../plot/tetra_point.dat";
  POINT input[TRIPRISM_V_NUM ];
  InputDatFile(input,inputfile, 3);

  for (int i = 0; i < 3; ++i){
    input[i+3].x = input[i].x;
    input[i+3].y = input[i].y;
    input[i+3].z = input[i].z + h;
  }

  for (int i = 0; i < TRIPRISM_V_NUM ; ++i){
    setVec4h(vs[i], input[i].x, input[i].y, input[i].z);
    // printf("%lf %lf %lf", input[i].x, input[i].y, input[i].z);
  }
}


void norm_triangle(double n[VEC_SIZE], double v0[VEC_SIZE], double v1[VEC_SIZE], double v2[VEC_SIZE])
{
  double v01[VEC_SIZE], v02[VEC_SIZE], norm_tri[VEC_SIZE];
  setVec4h(v01, v0[0] - v1[0], v0[1] - v1[1], v0[2] - v1[2]);
  setVec4h(v02, v0[0] - v2[0], v0[1] - v2[1], v0[2] - v2[2]);
  cross4h(norm_tri, v01, v02);
  normalize4h(n, norm_tri);
}


void prStlProlog(char *label, FILE *fp)
{
  fprintf(fp, "solid %s\n", label);
}


void prStlEpilog(char *label, FILE *fp)
{
  fprintf(fp, "endsolid %s\n", label);
}


void prStlFacet(double n[VEC_SIZE], double v0[VEC_SIZE], double v1[VEC_SIZE], double v2[VEC_SIZE], FILE *fp)
{
  fprintf(fp, "  facet normal %3.6e %3.6e %3.6e\n", n[0], n[1], n[2]);
  fprintf(fp, "    outer loop\n");
  fprintf(fp, "      vertex %15.6e %15.6e %15.6e\n", v0[0], v0[1], v0[2]);
  fprintf(fp, "      vertex %15.6e %15.6e %15.6e\n", v1[0], v1[1], v1[2]);
  fprintf(fp, "      vertex %15.6e %15.6e %15.6e\n", v2[0], v2[1], v2[2]);
  fprintf(fp, "    endloop\n");
  fprintf(fp, "  endfacet\n");
}


void prStlTetra(double vs[][VEC_SIZE], char *label)
{
  double n[VEC_SIZE];
  int i, j, s = (TETRA_V_NUM - 1);
  FILE *fp;
  if((fp = fopen("../plot/Tetra01.stl", "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    prStlProlog(label, fp);
    for (i = 0; i < s; i++) {
      j = (i + 1) % s;
      norm_triangle(n, vs[s], vs[i], vs[j]);
      prStlFacet(n, vs[s], vs[i], vs[j], fp);
    }
    norm_triangle(n, vs[2], vs[1], vs[0]);
    prStlFacet(n, vs[2], vs[1], vs[0], fp);
    prStlEpilog(label, fp);
    fclose(fp);
  }
}


void prStlTriprism(double vs[][VEC_SIZE], char *label)
{
  double n[VEC_SIZE];
  FILE *fp;
  if((fp = fopen("../plot/Triprism01.stl", "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    prStlProlog(label, fp);

    norm_triangle(n, vs[0], vs[1], vs[4]);
    prStlFacet(n, vs[0], vs[1], vs[4], fp);

    norm_triangle(n, vs[0], vs[4], vs[3]);
    prStlFacet(n, vs[0], vs[4], vs[3], fp);

    norm_triangle(n, vs[1], vs[5], vs[4]);
    prStlFacet(n, vs[1], vs[5], vs[4], fp);

    norm_triangle(n, vs[1], vs[2], vs[5]);
    prStlFacet(n, vs[1], vs[2], vs[5], fp);

    norm_triangle(n, vs[0], vs[3], vs[5]);
    prStlFacet(n, vs[0], vs[3], vs[5], fp);

    norm_triangle(n, vs[0], vs[5], vs[2]);
    prStlFacet(n, vs[0], vs[5], vs[2], fp);

    norm_triangle(n, vs[3], vs[4], vs[5]);
    prStlFacet(n, vs[3], vs[4], vs[5], fp);

    norm_triangle(n, vs[0], vs[2], vs[1]);
    prStlFacet(n, vs[0], vs[2], vs[1], fp);

    prStlEpilog(label, fp);
    fclose(fp);
  }
}


void stlb_k01(double tt[TETRA_V_NUM][VEC_SIZE], double tp[TRIPRISM_V_NUM][VEC_SIZE])
{
  set_tetra(tt);
  prStlTetra(tt, (char*)"Tetra01");

  set_triprism(tp, 2.0);
  prStlTriprism(tp, (char*)"Triprism01");
}
