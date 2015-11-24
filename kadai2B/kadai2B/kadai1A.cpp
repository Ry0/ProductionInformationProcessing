#include "kadai1A.h"

void printVec(double v[]) {
	printf("v = [ ");
	for (int i = 0; i < VEC_SIZE; i++) {
		printf("%lf ", v[i]);
	}
	printf("]\n");
}

void setVec4h(double v[], double x, double y, double z) {
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = 1;
}

double length4h(double v[]) {
	double norm;
	norm = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
#ifdef DEBUG
	printf("|v| = %lf\n", norm);
#endif
	return norm;
}

bool normalize4h(double u[], double v[]) {
	double norm_v = length4h(v);
	if (norm_v == 0) {
		printf("ベクトルの大きさが0です。\n");
		return false;
	}
	else {
		for (int i = 0; i < VEC_SIZE - 1; ++i) {
			u[i] = v[i] / norm_v;
		}
		u[VEC_SIZE - 1] = 1;
		return true;
	}
}

void negate4h(double u[], double v[]) {
	for (int i = 0; i < VEC_SIZE - 1; ++i) {
		u[i] = -v[i];
	}
	u[VEC_SIZE - 1] = 1;
}

void scaleVec4h(double u[], double k, double v[]) {
	for (int i = 0; i < VEC_SIZE - 1; ++i) {
		u[i] = k * v[i];
	}
	u[VEC_SIZE - 1] = 1;
}

void add4h(double u[], double v[], double p[]) {
	for (int i = 0; i < VEC_SIZE - 1; ++i) {
		u[i] = v[i] + p[i];
	}
	u[VEC_SIZE - 1] = 1;
}

void sub4h(double u[], double v[], double p[]) {
	for (int i = 0; i < VEC_SIZE - 1; ++i) {
		u[i] = v[i] - p[i];
	}
	u[VEC_SIZE - 1] = 1;
}

double dot4h(double v0[], double v1[]) {
	double dot;
	double sum = 0.0;
	for (int i = 0; i < VEC_SIZE - 1; ++i) {
		dot = v0[i] * v1[i];
		sum += dot;
	}
#ifdef DEBUG
	printf("内積: %lf\n", sum);
#endif
	return sum;
}

void cross4h(double u[], double v0[], double v1[]) {
	u[0] = v0[1] * v1[2] - v0[2] * v1[1];
	u[1] = v0[2] * v1[0] - v0[0] * v1[2];
	u[2] = v0[0] * v1[1] - v0[1] * v1[0];
#ifdef DEBUG
	printf("外積:");
	printVec(u);
#endif
}

double angle4h(double v0[], double v1[]) {
	double cos_theta = (dot4h(v0, v1)) / (length4h(v0)*length4h(v1));
	double theta;
	// theta = acos(cos_theta) * 180 / M_PI;
	theta = acos(cos_theta);

#ifdef DEBUG
	printf("角度: %lf\n", theta);
#endif
	return theta;
}

void asDirVec4h(double v[]) {
	v[VEC_SIZE - 1] = 0;
}

void asPosVec4h(double v[]) {
	v[VEC_SIZE - 1] = 1;
}

void printMat(double m[][VEC_SIZE]) {
	printf("Mat = \n");
	for (int i = 0; i < VEC_SIZE; i++) {
		for (int j = 0; j < VEC_SIZE; ++j) {
			printf("%lf ", m[i][j]);
		}
		printf("\n");
	}
}

void setMatCol4h(double a[][VEC_SIZE], double v0[], double v1[], double v2[], double p[]) {
	zeroMat4h(a);
	for (int i = 0; i < VEC_SIZE; ++i) {
		a[i][0] = v0[i];
		a[i][1] = v1[i];
		a[i][2] = v2[i];
		a[i][3] = p[i];
	}
#ifdef DEBUG
	printMat(a);
#endif
}

void mulMM4h(double m01[][VEC_SIZE], double m0[][VEC_SIZE], double m1[][VEC_SIZE]) {
	zeroMat4h(m01);
	for (int i = 0; i< VEC_SIZE; ++i) {
		for (int j = 0; j < VEC_SIZE; ++j) {
			for (int k = 0; k < VEC_SIZE; ++k) {
				m01[i][j] += m0[i][k] * m1[k][j];
			}
		}
	}
#ifdef DEBUG
	printMat(m01);
#endif
}

void mulMV4h(double u[], double m[][VEC_SIZE], double v[]) {
	for (int i = 0; i < VEC_SIZE; ++i) {
		u[i] = 0.0;
	}
	for (int i = 0; i< VEC_SIZE; ++i) {
		for (int j = 0; j < VEC_SIZE; ++j) {
			u[i] += m[i][j] * v[j];
		}
	}

#ifdef DEBUG
	printf("Vec = \n");
	for (int i = 0; i < VEC_SIZE; ++i) {
		printf("%lf\n", u[i]);
	}
#endif
}

void map4h(double us[][VEC_SIZE], double m[][VEC_SIZE], double vs[][VEC_SIZE], int num) {

	for (int i = 0; i < num; ++i) {
		mulMV4h(us[i], m, vs[i]);
	}

#ifdef DEBUG
	printf("点列 = \n");
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < VEC_SIZE; ++j) {
			printf("%lf ", us[i][j]);
		}
		printf("\n");
	}
#endif
}

void translate4h(double m[][VEC_SIZE], double v[]) {
	zeroMat4h(m);
	for (int i = 0; i< VEC_SIZE; ++i) {
		m[i][3] = v[i];
		m[i][i] = 1;
	}
#ifdef DEBUG
	printMat(m);
#endif
}

void translate4hnotInit(double m[][VEC_SIZE], double v[]) {
	for (int i = 0; i< VEC_SIZE; ++i) {
		m[i][3] = v[i];
	}
#ifdef DEBUG
	printMat(m);
#endif
}

void scale4h(double m[][VEC_SIZE], double a, double b, double c) {
	zeroMat4h(m);
	m[0][0] = a;
	m[1][1] = b;
	m[2][2] = c;
	m[3][3] = 1;

#ifdef DEBUG
	printMat(m);
#endif
}

void mirrorXY4h(double m[][VEC_SIZE]) {
	zeroMat4h(m);
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = -1;
	m[3][3] = 1;

#ifdef DEBUG
	printMat(m);
#endif
}

void mirrorYZ4h(double m[][VEC_SIZE]) {
	zeroMat4h(m);
	m[0][0] = -1;
	m[1][1] = 1;
	m[2][2] = 1;
	m[3][3] = 1;

#ifdef DEBUG
	printMat(m);
#endif
}

void mirrorZX4h(double m[][VEC_SIZE]) {
	zeroMat4h(m);
	m[0][0] = 1;
	m[1][1] = -1;
	m[2][2] = 1;
	m[3][3] = 1;

#ifdef DEBUG
	printMat(m);
#endif
}

void mirrorO4h(double m[][VEC_SIZE]) {
	zeroMat4h(m);
	m[0][0] = -1;
	m[1][1] = -1;
	m[2][2] = -1;
	m[3][3] = 1;

#ifdef DEBUG
	printMat(m);
#endif
}

void rotateX4h(double m[][VEC_SIZE], double a) {
	zeroMat4h(m);
	m[1][1] = cos(a);
	m[1][2] = -sin(a);
	m[2][1] = sin(a);
	m[2][2] = cos(a);
	m[0][0] = m[3][3] = 1;

#ifdef DEBUG
	printMat(m);
#endif
}

void rotateY4h(double m[][VEC_SIZE], double a) {
	zeroMat4h(m);
	m[0][0] = cos(a);
	m[0][2] = sin(a);
	m[2][0] = -sin(a);
	m[2][2] = cos(a);
	m[1][1] = m[3][3] = 1;

#ifdef DEBUG
	printMat(m);
#endif
}

void rotateZ4h(double m[][VEC_SIZE], double a) {
	zeroMat4h(m);
	m[0][0] = cos(a);
	m[0][1] = -sin(a);
	m[1][0] = sin(a);
	m[1][1] = cos(a);
	m[2][2] = m[3][3] = 1;

#ifdef DEBUG
	printMat(m);
#endif
}

void rotateXSC4h(double m[][VEC_SIZE], double sv, double cv) {
	zeroMat4h(m);
	m[1][1] = cv;
	m[1][2] = -sv;
	m[2][1] = sv;
	m[2][2] = cv;
	m[0][0] = m[3][3] = 1;

#ifdef DEBUG
	printMat(m);
#endif
}

void rotateYSC4h(double m[][VEC_SIZE], double sv, double cv)
{
	zeroMat4h(m);
	m[0][0] = cv;
	m[0][2] = sv;
	m[2][0] = -sv;
	m[2][2] = cv;
	m[1][1] = m[3][3] = 1;

#ifdef DEBUG
	printMat(m);
#endif
}

void rotateZSC4h(double m[][VEC_SIZE], double sv, double cv)
{
	zeroMat4h(m);
	m[0][0] = cv;
	m[0][1] = -sv;
	m[1][0] = sv;
	m[1][1] = cv;
	m[2][2] = m[3][3] = 1;

#ifdef DEBUG
	printMat(m);
#endif
}

void zeroMat4h(double m[][VEC_SIZE])
{
	for (int i = 0; i < VEC_SIZE; i++) {
		for (int j = 0; j < VEC_SIZE; ++j) {
			m[i][j] = 0.0;
		}
	}
}

void unitMat4h(double m[][VEC_SIZE]) {
	zeroMat4h(m);
	for (int i = 0; i < VEC_SIZE; ++i) {
		m[i][i] = 1;
	}
}

// 参考サイト: http://www.mech.tohoku-gakuin.ac.jp/rde/contents/course/robotics/coordtrans.html
void invMat4h(double im[][VEC_SIZE], double m[][VEC_SIZE]) {
	double det;
	double u[VEC_SIZE], v[VEC_SIZE];

	det = m[0][0] * m[1][1] * m[2][2] + m[1][0] * m[2][1] * m[0][2] + m[2][0] * m[0][1] * m[1][2]
		- m[0][0] * m[2][1] * m[1][2] - m[2][0] * m[1][1] * m[0][2] - m[1][0] * m[0][1] * m[2][2];
	if (det == 0) {
		printf("逆行列は存在しません\n");
	}
	else {
		// 一応初期化
		zeroMat4h(im);

		// 逆行列計算
		// 回転要素の計算
		im[0][0] = m[1][1] * m[2][2] - m[1][2] * m[2][1];
		im[0][1] = m[0][2] * m[2][1] - m[0][1] * m[2][2];
		im[0][2] = m[0][1] * m[1][2] - m[0][2] * m[1][1];

		im[1][0] = m[1][2] * m[2][0] - m[1][0] * m[2][2];
		im[1][1] = m[0][0] * m[2][2] - m[0][2] * m[2][0];
		im[1][2] = m[0][2] * m[1][0] - m[0][0] * m[1][2];

		im[2][0] = m[1][0] * m[2][1] - m[1][1] * m[2][0];
		im[2][1] = m[0][1] * m[2][0] - m[0][0] * m[2][1];
		im[2][2] = m[0][0] * m[1][1] - m[0][1] * m[1][0];

		for (int i = 0; i < VEC_SIZE; ++i) {
			for (int j = 0; j < VEC_SIZE; ++j) {
				im[i][j] = im[i][j] / det;
			}
		}

		// 平行移動要素初期化
		for (int i = 0; i < VEC_SIZE; ++i) {
			u[i] = 0.0;
			v[i] = m[i][VEC_SIZE - 1];
		}
		u[VEC_SIZE - 1] = 1.0;

		// 平行移動要素計算
		for (int i = 0; i< VEC_SIZE - 1; ++i) {
			for (int j = 0; j < VEC_SIZE - 1; ++j) {
				u[i] += im[i][j] * v[j];
			}
			im[i][VEC_SIZE - 1] = -u[i];
		}
		im[VEC_SIZE - 1][VEC_SIZE - 1] = 1;

#ifdef DEBUG
		// 結果の出力
		printf("Inverse ");
		printMat(im);
#endif
	}
}