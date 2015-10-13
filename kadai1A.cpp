#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define VEC_SIZE 4 // ベクトルのサイズ

// 関数プロトタイプ宣言
// ベクトルの中身確認
void printVec(double v[]);
// ベクトルの初期化
void setVec4h(double v[], double x, double y, double z);
//ベクトルの大きさ
double length4h(double v[]);
// 単位ベクトル
bool normalize4h(double u[], double v[]);
// 逆ベクトル
void negate4h(double u[], double v[]);
// ベクトル和
void add4h(double u[], double v[], double p[]);
// ベクトル差
void sub4h(double u[], double v[], double p[]);
// ベクトルの内積
double dot4h(double v0[], double v1[]);
// ベクトルの外積
void cross4h(double u[], double v0[], double v1[]);
// ベクトル間の角度
double angle4h(double v0[], double v1[]);
// 方向ベクトル化
void asDirVec4h(double v[]);
// 位置ベクトル化
void asDirVec4h(double v[]);

void printVec(double v[]){
	printf("v = [ ");
	for (int i = 0; i < VEC_SIZE; i++){
		printf("%lf ", v[i]);
	}
	printf("]\n");
}

void setVec4h(double v[], double x, double y, double z){
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = 1;
}

double length4h(double v[]){
	double norm;
	norm = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	// printf("|v| = %lf\n", norm);
	return norm;
}

bool normalize4h(double u[], double v[]){
	double norm_v = length4h(v);
	if (norm_v == 0){
		printf("ベクトルの大きさが0です。\n");
		return false;
	}else{
		for (int i = 0; i < VEC_SIZE-1; ++i){
			u[i] = v[i] / norm_v;
		}
		u[VEC_SIZE-1] = 1;
		return true;
	}
}

void negate4h(double u[], double v[]){
	for (int i = 0; i < VEC_SIZE-1; ++i){
		u[i] = - v[i];
	}
	u[VEC_SIZE-1] = 1;
}

void scaleVec4h(double u[], double k, double v[]){
	for (int i = 0; i < VEC_SIZE-1; ++i){
		u[i] = k * v[i];
	}
	u[VEC_SIZE-1] = 1;
}

void add4h(double u[], double v[], double p[]){
	for (int i = 0; i < VEC_SIZE-1; ++i){
		u[i] = v[i] + v[i];
	}
	u[VEC_SIZE-1] = 1;
}

void sub4h(double u[], double v[], double p[]){
	for (int i = 0; i < VEC_SIZE-1; ++i){
		u[i] = v[i] - v[i];
	}
	u[VEC_SIZE-1] = 1;
}

double dot4h(double v0[], double v1[]){
	double dot;
	double sum = 0.0;
	for (int i = 0; i < VEC_SIZE-1; ++i){
		dot = v0[i] * v1[i];
		sum += dot;
	}
	// printf("内積: %lf\n", sum);
	return sum;
}

void cross4h(double u[], double v0[], double v1[]){
	u[0] = v0[1]*v1[2] - v0[2]*v1[1];
	u[1] = v0[2]*v1[0] - v0[0]*v1[2];
	u[2] = v0[0]*v1[1] - v0[1]*v1[0];
	printf("外積:");
	printVec(u);
}

double angle4h(double v0[], double v1[]){
	double cos_theta = (dot4h(v0, v1))/(length4h(v0)*length4h(v1));
	double theta;
	theta = acos(cos_theta)*180/M_PI;
	printf("角度: %lf\n", theta);
	return theta;
}

void asDirVec4h(double v[]){
	v[VEC_SIZE-1] = 0;
}

void asPosVec4h(double v[]){
	v[VEC_SIZE-1] = 1;
}

void initMat(double m[][VEC_SIZE]){
	for (int i = 0; i < VEC_SIZE; i++){
		for (int j = 0; j < VEC_SIZE; ++j){
			m[i][j] = 0.0;
		}
	}
}

void printMat(double m[][VEC_SIZE]){
	printf("Mat = \n");
	for (int i = 0; i < VEC_SIZE; i++){
		for (int j = 0; j < VEC_SIZE; ++j){
			printf("%lf ", m[i][j]);
		}
		printf("\n");
	}
}

void setMatCol4h(double a[][VEC_SIZE], double v0[], double v1[], double v2[], double p[]){
	initMat(a);
	for (int i = 0; i < VEC_SIZE; ++i){
		a[i][0] = v0[i];
		a[i][1] = v1[i];
		a[i][2] = v2[i];
		a[i][3] = p[i];
	}
	printMat(a);
}

void mulMM4h(double m01[][VEC_SIZE], double m0[][VEC_SIZE], double m1[][VEC_SIZE]){
	initMat(m01);
	for(int i = 0; i< VEC_SIZE; ++i) {
		for(int j = 0; j < VEC_SIZE; ++j) {
			for(int k = 0; k < VEC_SIZE; ++k) {
				m01[i][j] += m0[i][k] * m1[k][j];
			}
		}
	}
	printMat(m01);
}

void mulMV4h(double u[], double m[][VEC_SIZE], double v[]){
	for (int i = 0; i < VEC_SIZE; ++i){
		u[i] = 0.0;
	}
	for(int i = 0; i< VEC_SIZE; ++i) {
		for(int j = 0; j < VEC_SIZE; ++j) {
			u[i] += m[j][i] * v[j];
		}
	}
	printf("Mat = \n");
	for(int i = 0; i < VEC_SIZE; ++i) {
		printf("%lf\n",u[i]);
	}
}


int main(){
	double mat1[VEC_SIZE][VEC_SIZE] = {0.0};
	double mat2[VEC_SIZE][VEC_SIZE] = {0.0};
	double dst[VEC_SIZE][VEC_SIZE] = {0.0};

	double m0[VEC_SIZE] = {1,2,3,4};
	double m1[VEC_SIZE] = {2,3,4,5};
	double m2[VEC_SIZE] = {3,4,5,6};
	double p[VEC_SIZE] = {4,5,6,7};

	setMatCol4h(mat1, m0, m1, m2, p);
	// setMatCol4h(mat2, m1, m2, m2, p);
	// mulMM4h(dst, mat1, mat2);

	mulMV4h(m1, mat1, m0);

	return 0;
}