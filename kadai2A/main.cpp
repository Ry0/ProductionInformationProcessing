#include "kadai.h"

#include <iostream>
using namespace std;

int main(){
  double tetra_pos[TETRA_V_NUM][VEC_SIZE];
  double triprism_pos[TRIPRISM_V_NUM][VEC_SIZE];
  stlb_k01(tetra_pos, triprism_pos);

  return 0;
}