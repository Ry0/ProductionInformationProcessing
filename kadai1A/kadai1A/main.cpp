#include "kadai1A.h"

int main() {
	double mat[VEC_SIZE][VEC_SIZE];
	double dst[VEC_SIZE][VEC_SIZE];

	double m0[VEC_SIZE] = { 1, 2, 3, 0 };
	double m1[VEC_SIZE] = { -2, -2, 4, 0 };
	double m2[VEC_SIZE] = { 3, 4, 5, 0 };
	double p[VEC_SIZE] = { 4, -5, 6, 1 };

	setMatCol4h(mat, m0, m1, m2, p);

	invMat4h(dst, mat);

	system("pause");
	return 0;
}