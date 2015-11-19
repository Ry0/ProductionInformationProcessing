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


void CombinationTetra(double vs[][VEC_SIZE], FILE *fp){
  double n[VEC_SIZE];
  int i, j, s = (TETRA_V_NUM - 1);

  for (i = 0; i < s; i++) {
    j = (i + 1) % s;
    norm_triangle(n, vs[s], vs[i], vs[j]);
    prStlFacet(n, vs[s], vs[i], vs[j], fp);
  }
  norm_triangle(n, vs[2], vs[1], vs[0]);
  prStlFacet(n, vs[2], vs[1], vs[0], fp);
}


void prStlTetra(double vs[][VEC_SIZE], char *label)
{
  FILE *fp;
  if((fp = fopen("../plot/Tetra01.stl", "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    prStlProlog(label, fp);
    CombinationTetra(vs, fp);
    prStlEpilog(label, fp);
    fclose(fp);
  }
}


void CombinationTriprism(double vs[][VEC_SIZE], FILE *fp){
  double n[VEC_SIZE];

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
}

void prStlTriprism(double vs[][VEC_SIZE], char *label)
{
  FILE *fp;
  if((fp = fopen("../plot/Triprism01.stl", "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    prStlProlog(label, fp);
    CombinationTriprism(vs, fp);
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


double GetRandom(double min,double max, int digit){
  double ten,R;

  ten = pow(10,digit-1);
  R = min*ten + (int)(rand()*((max-min)*ten+1.0)/(1.0+RAND_MAX));
  return R/ten;
}


AXIS randCoordinateAxis(){
  AXIS axis;
  double x_axis[VEC_SIZE], y_axis[VEC_SIZE], z_axis[VEC_SIZE], origin[VEC_SIZE];
  double unit_x_axis[VEC_SIZE], unit_y_axis[VEC_SIZE], unit_z_axis[VEC_SIZE];

  for (int i = 0; i < 3; ++i){
    x_axis[i] = (double)rand()/RAND_MAX;
  }
  x_axis[3] = 0.0;

  normalize4h(unit_x_axis, x_axis);

  for (int i = 0; i < 2; ++i){
    y_axis[i] = (double)rand()/RAND_MAX;
  }
  y_axis[2] = -(unit_x_axis[0]*y_axis[0]+unit_x_axis[1]*y_axis[1])/unit_x_axis[2];
  y_axis[3] = 0.0;

  normalize4h(unit_y_axis, y_axis);

  cross4h(z_axis, unit_x_axis, unit_y_axis);
  normalize4h(unit_z_axis, z_axis);

  for (int i = 0; i < 3; ++i){
    origin[i] = GetRandom(-6, 6, 10);
  }

  axis.x_axis.x = unit_x_axis[0];
  axis.x_axis.y = unit_x_axis[1];
  axis.x_axis.z = unit_x_axis[2];

  axis.y_axis.x = unit_y_axis[0];
  axis.y_axis.y = unit_y_axis[1];
  axis.y_axis.z = unit_y_axis[2];

  axis.z_axis.x = unit_z_axis[0];
  axis.z_axis.y = unit_z_axis[1];
  axis.z_axis.z = unit_z_axis[2];

  axis.origin.x = origin[0];
  axis.origin.y = origin[1];
  axis.origin.z = origin[2];
  return axis;
}


void TransformPosition(char *label, FILE *fp){
  double trMat[VEC_SIZE][VEC_SIZE];
  double v0[VEC_SIZE], v1[VEC_SIZE], v2[VEC_SIZE], p[VEC_SIZE];

  AXIS axis = randCoordinateAxis();

  v0[0] = axis.x_axis.x;
  v0[1] = axis.x_axis.y;
  v0[2] = axis.x_axis.z;
  v0[3] = 0.0;
  v1[0] = axis.y_axis.x;
  v1[1] = axis.y_axis.y;
  v1[2] = axis.y_axis.z;
  v1[3] = 0.0;
  v2[0] = axis.z_axis.x;
  v2[1] = axis.z_axis.y;
  v2[2] = axis.z_axis.z;
  v2[3] = 0.0;
  p[0]  = axis.origin.x;
  p[1]  = axis.origin.y;
  p[2]  = axis.origin.z;
  p[3]  = 1.0;

  setMatCol4h(trMat, v0, v1, v2, p);

  if(strcmp(label, "Tetra") == 0){
    printf("四面体作ります\n");
    double tt[TETRA_V_NUM][VEC_SIZE], tranformedtt[TETRA_V_NUM][VEC_SIZE];
    set_tetra(tt);
    for (int i = 0; i < TETRA_V_NUM; ++i){
      mulMV4h(tranformedtt[i], trMat, tt[i]);
    }
    CombinationTetra(tranformedtt, fp);
  } else if(strcmp(label, "Triprism") == 0){
    printf("三角柱作ります\n");
    double tp[TRIPRISM_V_NUM][VEC_SIZE], tranformedtp[TRIPRISM_V_NUM][VEC_SIZE];
    set_triprism(tp, 2.0);
    for (int i = 0; i < TRIPRISM_V_NUM; ++i){
      mulMV4h(tranformedtp[i], trMat, tp[i]);
    }
    CombinationTriprism(tranformedtp, fp);
  }else{
    printf("ラベルが間違っている\n");
  }

}


void TransformPositionAll(char *label){
  FILE *fp;

  if((fp = fopen("../plot/Tetra-Triprism.stl", "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    srand((unsigned)time(NULL));
    prStlProlog(label, fp);
    TransformPosition((char*)"Tetra", fp);
    TransformPosition((char*)"Triprism", fp);
    TransformPosition((char*)"Tetra", fp);
    TransformPosition((char*)"Triprism", fp);
    TransformPosition((char*)"Tetra", fp);
    TransformPosition((char*)"Triprism", fp);
    TransformPosition((char*)"Tetra", fp);
    TransformPosition((char*)"Triprism", fp);
    prStlEpilog(label, fp);
    fclose(fp);
  }

}