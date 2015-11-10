#include "kadai.h"

int main(){
  // 課題1 (a)
  // rotateXYZ(45, 60, 150);

  // 課題1 (b)
  // rotateYZX(45, 60, 150);

  // 課題2
  char pltfile[128] = "../plot/plot.plt";
  OutputAxisPlt(pltfile);

  // gnuplotで結果を示す
  OpenGnuplot();
  // system("pause");
  return 0;
}