#include "kadai.h"

#include <iostream>
using namespace std;

int main(){
  // 3次ベジエ曲線テスト
  // draw_bezier3();

  // double input[BDIM+1][BDIM+1][HDIM];
  // InputDatFile(input, (char*)"../plot/InputPoint.dat");

  // double m[HDIM][BDIM+1] = {{1,-3,3,-1}, {0,3,-6,3}, {0,0,3,-3}, {0,0,0,1}};
  // double output[BDIM+1][BDIM+1][HDIM];

  // calc_M_tPM(output, input, m);
  draw_bezier3_surface();
  OpenGnuplot();

  return 0;
}