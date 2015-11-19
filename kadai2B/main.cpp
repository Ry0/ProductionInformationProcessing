#include "kadai.h"

#include <iostream>
using namespace std;

int main(){
  double Theta[5] = {45.0/180.0*M_PI, 30.0/180.0*M_PI, 135.0/180.0*M_PI, -30.0/180.0*M_PI, 60.0/180.0*M_PI};

  double Link_length_full[6] = {3.0/2.0, 3.0/2.0, 2.0/2.0, 2.0/2.0, 1.0/2.0, 1.0/2.0};
  double Link_length_short[6] = {0.0, 3.0, 0.0, 2.0, 0.0, 1.0};


  ForwardKinematics(Theta, Link_length_full);
  ShowTfAxis(Theta, Link_length_full);
  LinkCreator(Theta, Link_length_short);

  return 0;
}