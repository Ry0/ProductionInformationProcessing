#include "kadai.h"

int main(){
  // 課題2Bの3での与えられたパラメータ
  double Theta[5] = {45.0/180.0*M_PI, 30.0/180.0*M_PI, 135.0/180.0*M_PI, -30.0/180.0*M_PI, 60.0/180.0*M_PI};
  // スケルトン図通りのリンク長で定義する場合
  double Link_length_full[6] = {3.0/2.0, 3.0/2.0, 2.0/2.0, 2.0/2.0, 1.0/2.0, 1.0/2.0};
  // アーム中間で分割しない場合
  double Link_length_short[6] = {0.0, 3.0, 0.0, 2.0, 0.0, 1.0};

  // GNUPLOTでロボットの姿勢と各軸の座標系可視化
  ForwardKinematics(Theta, Link_length_full);
  ShowTfAxis(Theta, Link_length_full);

  // 問題で与えられた姿勢をSTLで出力
  LinkCreator(Theta, Link_length_short);

  return 0;
}
