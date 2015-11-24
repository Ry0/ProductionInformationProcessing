#include "kadai.h"

#include <iostream>
using namespace std;

int main(){
  // 3次ベジエ曲線テスト
  // draw_bezier3();

  // ベジエ曲面を描く
  draw_bezier3_surface();

  OpenGnuplot();

  return 0;
}