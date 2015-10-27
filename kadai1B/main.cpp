#include "kadai.h"

int main(){
  char pltfile[128] = "../plot/plot.plt";
  OutputAxisPlt(pltfile);
  // rotateXYZ(45, 60, 150);
  // rotateYZX(45, 60, 150);
  OpenGnuplot();
  // system("pause");
  return 0;
}