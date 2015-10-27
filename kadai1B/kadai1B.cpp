#include "kadai1B.h"

#include <iostream>
using namespace std;

void InputDatFile(POINT p[], char *fname){
  FILE *fp;

  fp = fopen( fname, "r" );
  if( fp == NULL ){
    printf( "%sのファイルが開けません\n", fname);
  }else{
    for (int i = 0; i < 8; ++i){
      if(fscanf( fp, "%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z)==-1){
        printf("読み込み失敗");
      }
    }
  }
  fclose(fp);
}


// 参考：http://www-sens.sys.es.osaka-u.ac.jp/wakate/tutorial/group3/gnuplot/
int OpenGnuplot()
{
  FILE *fp = popen("cd ../plot && gnuplot -persist", "w");
  if (fp == NULL) {
    return -1;
  }
  fputs("set mouse\n", fp);
  fputs("load \"plot.plt\"\n", fp);

  fflush(fp);
  cin.get();
  pclose(fp);
  return 0;
}


void OutputDatFile(char *fname, POINT p[]){
  FILE *fp;
  if((fp = fopen(fname, "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    for (int i = 0; i < 8; ++i) {
      fprintf(fp, "%lf %lf %lf\n", p[i].x, p[i].y, p[i].z);
    }
    fclose(fp);
  }
}


void OutputRotatePlt(char *fname){
  FILE *fp;
  if((fp = fopen(fname, "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    fprintf(fp, "set xlabel \'x\'\n");
    fprintf(fp, "set ylabel \'y\'\n");
    fprintf(fp, "set zlabel \'z\'\n");
    fprintf(fp, "set xrange[-2:2]\n");
    fprintf(fp, "set yrange[-2:2]\n");
    fprintf(fp, "set zrange[-2:2]\n");
    fprintf(fp, "set view equal xyz\n");
    fprintf(fp, "set ticslevel 0\n");

    fprintf(fp, "splot \'initial_point.dat\' using 1:2:3 with lines lt 1 lc rgb \'#ff0033\' lw 3 title \'Initial Position\',\\\n");
    fprintf(fp, "\'x.dat\' using 1:2:3 with lines lt 1 lc rgb \'#1723E1\' lw 3 title \'X:   45deg\',\\\n");
    fprintf(fp, "\'y.dat\' using 1:2:3 with lines lt 1 lc rgb \'#37C440\' lw 3 title \'Y:   60deg\',\\\n");
    fprintf(fp, "\'z.dat\' using 1:2:3 with lines lt 1 lc rgb \'#FFCA31\' lw 3 title \'Z: 150deg\'\n");
    fclose(fp);
  }
}


void CalcRotationMat(POINT input[], POINT output[], double rotation_mat[][VEC_SIZE]){
  double input_vec[VEC_SIZE], trans[VEC_SIZE];
  for (int i = 0; i < 8; ++i) {
    input_vec[0] = input[i].x;
    input_vec[1] = input[i].y;
    input_vec[2] = input[i].z;
    input_vec[3] = 1;
    mulMV4h(trans, rotation_mat, input_vec);
    output[i].x = trans[0];
    output[i].y = trans[1];
    output[i].z = trans[2];
  }
}


void rotateXYZ(double r_x, double r_y, double r_z){
  double m_x[VEC_SIZE][VEC_SIZE];
  double m_y[VEC_SIZE][VEC_SIZE];
  double m_z[VEC_SIZE][VEC_SIZE];

  // プロット用のファイル作成（GNUPLOT）
  char pltfile[128] = "../plot/plot.plt";
  OutputRotatePlt(pltfile);

  // 引数でとった角度で各軸まわりの回転行列作成
  // deg→radに変換
  rotateX4h(m_x, r_x/180*M_PI);
  rotateY4h(m_y, r_y/180*M_PI);
  rotateZ4h(m_z, r_z/180*M_PI);

  // 初期姿勢を外部ファイルから取ってくる
  char inputfile[128] = "../plot/initial_point.dat";
  POINT input[8];
  POINT output_x[8], output_y[8], output_z[8];
  InputDatFile(input,inputfile);

  // まずx軸まわりで回転
  CalcRotationMat(input, output_x, m_x);
  // x軸まわりで回転した結果を出力
  char x[128] = "../plot/x.dat";
  OutputDatFile(x, output_x);

  // y軸まわりで回転
  CalcRotationMat(output_x, output_y, m_y);
  // y軸まわりで回転した結果を出力
  char y[128] = "../plot/y.dat";
  OutputDatFile(y, output_y);

  // z軸まわりで回転
  CalcRotationMat(output_y, output_z, m_z);
  // z軸まわりで回転した結果を出力
  char z[128] = "../plot/z.dat";
  OutputDatFile(z, output_z);
}


void rotateYZX(double r_x, double r_y, double r_z){
  double m_x[VEC_SIZE][VEC_SIZE];
  double m_y[VEC_SIZE][VEC_SIZE];
  double m_z[VEC_SIZE][VEC_SIZE];

  // プロット用のファイル作成（GNUPLOT）
  char pltfile[128] = "../plot/plot.plt";
  OutputRotatePlt(pltfile);

  // 引数でとった角度で各軸まわりの回転行列作成
  // deg→radに変換
  rotateX4h(m_x, r_x/180*M_PI);
  rotateY4h(m_y, r_y/180*M_PI);
  rotateZ4h(m_z, r_z/180*M_PI);

  // 初期姿勢を外部ファイルから取ってくる
  char inputfile[128] = "../plot/initial_point.dat";
  POINT input[8];
  POINT output_x[8], output_y[8], output_z[8];
  InputDatFile(input,inputfile);

  // まずy軸まわりで回転
  CalcRotationMat(input, output_y, m_y);
  // y軸まわりで回転した結果を出力
  char y[128] = "../plot/y.dat";
  OutputDatFile(y, output_y);

  // z軸まわりで回転
  CalcRotationMat(output_y, output_z, m_z);
  // z軸まわりで回転した結果を出力
  char z[128] = "../plot/z.dat";
  OutputDatFile(z, output_z);

  // x軸まわりで回転
  CalcRotationMat(output_z, output_x, m_x);
  // x軸まわりで回転した結果を出力
  char x[128] = "../plot/x.dat";
  OutputDatFile(x, output_x);
}


AXIS randCoordinateAxis(){
  AXIS axis;
  double x_axis[VEC_SIZE], y_axis[VEC_SIZE], z_axis[VEC_SIZE], origin[VEC_SIZE];
  double unit_x_axis[VEC_SIZE], unit_y_axis[VEC_SIZE], unit_z_axis[VEC_SIZE];

  srand((unsigned)time(NULL));

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
    origin[i] = GetRandom(0, 3, 10);
  }
  for (int i = 0; i < 3; ++i){
    unit_x_axis[i] = unit_x_axis[i] + origin[i];
    unit_y_axis[i] = unit_y_axis[i] + origin[i];
    unit_z_axis[i] = unit_z_axis[i] + origin[i];
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


double GetRandom(double min,double max, int digit){
  double ten,R;

  ten = pow(10,digit-1);
  R = min*ten + (int)(rand()*((max-min)*ten+1.0)/(1.0+RAND_MAX));
  return R/ten;
}

void OutputAxisPlt(char *fname){
  AXIS axis;
  axis = randCoordinateAxis();

  FILE *fpx;
  if((fpx = fopen("../plot/x.dat", "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    fprintf(fpx, "0 0 0\n");
    fprintf(fpx, " 1 0 0\n\n\n");
    fprintf(fpx, "%lf %lf %lf\n", axis.origin.x, axis.origin.y, axis.origin.z);
    fprintf(fpx, "%lf %lf %lf", axis.x_axis.x, axis.x_axis.y, axis.x_axis.z);
    fclose(fpx);
  }

  FILE *fpy;
  if((fpy = fopen("../plot/y.dat", "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    fprintf(fpx, "0 0 0\n");
    fprintf(fpx, " 0 1 0\n\n\n");
    fprintf(fpy, "%lf %lf %lf\n", axis.origin.x, axis.origin.y, axis.origin.z);
    fprintf(fpy, "%lf %lf %lf", axis.y_axis.x, axis.y_axis.y, axis.y_axis.z);
    fclose(fpy);
  }

  FILE *fpz;
  if((fpz = fopen("../plot/z.dat", "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    fprintf(fpx, "0 0 0\n");
    fprintf(fpx, " 0 0 1\n\n\n");
    fprintf(fpz, "%lf %lf %lf\n", axis.origin.x, axis.origin.y, axis.origin.z);
    fprintf(fpz, "%lf %lf %lf", axis.z_axis.x, axis.z_axis.y, axis.z_axis.z);
    fclose(fpz);
  }

  FILE *fp;
  if((fp = fopen(fname, "w"))==NULL){
    printf("ファイルをオープンできません\n");
  } else {
    fprintf(fp, "reset\n");
    fprintf(fp, "set xlabel \'x\'\n");
    fprintf(fp, "set ylabel \'y\'\n");
    fprintf(fp, "set zlabel \'z\'\n");
    fprintf(fp, "set xrange[-5:5]\n");
    fprintf(fp, "set yrange[-5:5]\n");
    fprintf(fp, "set zrange[-5:5]\n");
    fprintf(fp, "set view equal xyz\n");
    fprintf(fp, "set ticslevel 0\n");

    fprintf(fp, "splot \'x.dat\' using 1:2:3 with lines lt 1 lc rgb \'#1723E1\' lw 3 title \'X axis\',\\\n");
    fprintf(fp, "\'y.dat\' using 1:2:3 with lines  lt 1 lc rgb \'#37C440\' lw 3 title \'Y axis\',\\\n");
    fprintf(fp, "\'z.dat\' using 1:2:3 with lines  lt 1 lc rgb \'#FFCA31\' lw 3 title \'Z axis\'\n");
    fclose(fp);
  }
}
