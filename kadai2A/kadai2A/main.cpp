#include "kadai.h"

int main() {

	// ‰Û‘è1
	 double tetra_pos[TETRA_V_NUM][VEC_SIZE];
	 double triprism_pos[TRIPRISM_V_NUM][VEC_SIZE];
	 stlb_k01(tetra_pos, triprism_pos);

	// ‰Û‘è2
	TransformPositionAll((char*)"Tetra-Triprism");

	system("pause");
	return 0;
}