#include "kadai.h"

int main() {
	// �ۑ�1 (a)
	//rotateXYZ(45, 60, 150);

	// �ۑ�1 (b)
	// rotateYZX(45, 60, 150);

	// �ۑ�2
	// char pltfile[128] = "../plot/plot.plt";
	 //OutPutPlt_kadai2(pltfile);

	// �ۑ�3
	AXIS axis;
	char pltfile[128] = "../plot/plot.plt";
	axis = OutputRandomAxis();
	CoordinateTransform(axis);
	OutPutPlt_kadai3(pltfile);

	// �ۑ�4
	// AXIS axis;
	// char pltfile[128] = "../plot/plot.plt";
	// axis = OutputRandomAxis();
	// CoordinateTransformToOrigin(axis);
	// OutPutPlt_kadai4(pltfile);

	// �ۑ�5 (�ۑ�3�̃R�����g�A�E�g���O��)
	TransformToOriginVector(axis);
	OutPutPlt_kadai5(pltfile);

	// gnuplot�Ō��ʂ�����
	OpenGnuplot();

	system("pause");
	return 0;
}