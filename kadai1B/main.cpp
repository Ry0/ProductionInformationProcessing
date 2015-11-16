#include "kadai.h"

int main(){
  // 課題1 (a)
  // rotateXYZ(45, 60, 150);

  // 課題1 (b)
  // rotateYZX(45, 60, 150);

  // 課題2
  // char pltfile[128] = "../plot/plot.plt";
  // OutPutPlt_kadai2(pltfile);

  // 課題3
  // AXIS axis;
  // char pltfile[128] = "../plot/plot.plt";
  // axis = OutputRandomAxis();
  // CoordinateTransform(axis);
  // OutPutPlt_kadai3(pltfile);

  // 課題4
  AXIS axis;
  char pltfile[128] = "../plot/plot.plt";
  axis = OutputRandomAxis();
  CoordinateTransformToOrigin(axis);
  OutPutPlt_kadai4(pltfile);

  // gnuplotで結果を示す
  OpenGnuplot();
  // system("pause");
  return 0;
}