#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define VEC_SIZE 4 // ベクトルのサイズ

// 関数プロトタイプ宣言
/*------------------ ベクトルの基本演算 ---------------------*/
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
/*------------- 3次元用同次座標行列の各種演算 ----------------*/
// 行列の可視化
void printMat(double m[][VEC_SIZE]);
// 列ベクトルによる行列定義
void setMatCol4h(double a[][VEC_SIZE], double v0[], double v1[], double v2[], double p[]);
// 行列の積
void mulMM4h(double m01[][VEC_SIZE], double m0[][VEC_SIZE], double m1[][VEC_SIZE]);
// 行列とベクトルの積
void mulMV4h(double u[], double m[][VEC_SIZE], double v[]);
/*-------- 3次元の同次座標変換行列 m を生成する関数 -----------*/
// 平行移動
void translate4h(double m[][VEC_SIZE], double v[]);
// 拡大縮小
void scale4h(double m[][VEC_SIZE], double a, double b, double c);
// XY 平面対称
void mirrorXY4h(double m[][VEC_SIZE]);
// YZ 平面対称
void mirrorYZ4h(double m[][VEC_SIZE]);
// ZX 平面対称
void mirrorZX4h(double m[][VEC_SIZE]);
// 原点対称
void mirrorO4h(double m[][VEC_SIZE]);
// X 軸中心回転
void rotateX4h(double m[][VEC_SIZE], double a); // X 軸正方向に右ねじが進む回転方向に a[rad] 回転.
// Y 軸中心回転
void rotateY4h(double m[][VEC_SIZE], double a); // Y 軸正方向に右ねじが進む回転方向に a[rad] 回転.
// Z 軸中心回転
void rotateZ4h(double m[][VEC_SIZE], double a); // Z 軸正方向に右ねじが進む回転方向に a[rad] 回転.
// X 軸中心回転
void rotateXSC4h(double m[][VEC_SIZE], double sv, double cv);
// Y 軸中心回転
void rotateYSC4h(double m[][VEC_SIZE], double sv, double cv);
// Z 軸中心回転
void rotateZSC4h(double m[][VEC_SIZE], double sv, double cv);
// ゼロ行列
void zeroMat4h(double m[][VEC_SIZE]);
// 単位行列
void unitMat4h(double m[][VEC_SIZE]);
// 逆行列
void invMat4h(double im[][VEC_SIZE], double m[][VEC_SIZE]);

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
	zeroMat4h(a);
	for (int i = 0; i < VEC_SIZE; ++i){
		a[i][0] = v0[i];
		a[i][1] = v1[i];
		a[i][2] = v2[i];
		a[i][3] = p[i];
	}
	printMat(a);
}

void mulMM4h(double m01[][VEC_SIZE], double m0[][VEC_SIZE], double m1[][VEC_SIZE]){
	zeroMat4h(m01);
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
			u[i] += m[i][j] * v[j];
		}
	}
	printf("Vec = \n");
	for(int i = 0; i < VEC_SIZE; ++i) {
		printf("%lf\n",u[i]);
	}
}

void translate4h(double m[][VEC_SIZE], double v[]){
	zeroMat4h(m);
	for(int i = 0; i< VEC_SIZE; ++i) {
			m[i][3] = v[i];
			m[i][i] = 1;
	}
	printMat(m);
}

void scale4h(double m[][VEC_SIZE], double a, double b, double c){
	zeroMat4h(m);
	m[0][0] = a;
	m[1][1] = b;
	m[2][2] = c;
	m[3][3] = 1;

	printMat(m);
}

void mirrorXY4h(double m[][VEC_SIZE]){
	zeroMat4h(m);
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = -1;
	m[3][3] = 1;

	printMat(m);
}

void mirrorYZ4h(double m[][VEC_SIZE]){
	zeroMat4h(m);
	m[0][0] = -1;
	m[1][1] = 1;
	m[2][2] = 1;
	m[3][3] = 1;

	printMat(m);
}

void mirrorZX4h(double m[][VEC_SIZE]){
	zeroMat4h(m);
	m[0][0] = 1;
	m[1][1] = -1;
	m[2][2] = 1;
	m[3][3] = 1;

	printMat(m);
}

void mirrorO4h(double m[][VEC_SIZE]){
	zeroMat4h(m);
	m[0][0] = -1;
	m[1][1] = -1;
	m[2][2] = -1;
	m[3][3] = 1;

	printMat(m);
}

void rotateX4h(double m[][VEC_SIZE], double a){
	zeroMat4h(m);
	m[1][1] = cos(a);
	m[1][2] = -sin(a);
	m[2][1] = sin(a);
	m[2][2] = cos(a);
	m[0][0] = 1;
	printMat(m);
}

void rotateY4h(double m[][VEC_SIZE], double a){
	zeroMat4h(m);
	m[0][0] = cos(a);
	m[0][2] = sin(a);
	m[2][0] = -sin(a);
	m[2][2] = cos(a);
	m[1][1] = 1;
	printMat(m);
}

void rotateZ4h(double m[][VEC_SIZE], double a){
	zeroMat4h(m);
	m[0][0] = cos(a);
	m[0][1] = -sin(a);
	m[1][0] = sin(a);
	m[1][1] = cos(a);
	m[2][2] = 1;
	printMat(m);
}

void rotateXSC4h(double m[][VEC_SIZE], double sv, double cv){
	zeroMat4h(m);
	m[1][1] = cv;
	m[1][2] = -sv;
	m[2][1] = sv;
	m[2][2] = cv;
        m[0][0] = 1;
        printMat(m);
}

void rotateYSC4h(double m[][VEC_SIZE], double sv, double cv)
{
  zeroMat4h(m);
  m[0][0] = cv;
  m[0][2] = sv;
  m[2][0] = -sv;
  m[2][2] = cv;
  m[1][1] = 1;
  printMat(m);
}

void rotateZSC4h(double m[][VEC_SIZE], double sv, double cv)
{
  zeroMat4h(m);
  m[0][0] = cv;
  m[0][1] = -sv;
  m[1][0] = sv;
  m[1][1] = cv;
  m[2][2] = 1;
  printMat(m);
}

void zeroMat4h(double m[][VEC_SIZE])
{
	for (int i = 0; i < VEC_SIZE; i++) {
		for (int j = 0; j < VEC_SIZE; ++j){
			m[i][j] = 0.0;
		}
	}
}

void unitMat4h(double m[][VEC_SIZE]){
	zeroMat4h(m);
	for (int i = 0; i < VEC_SIZE; ++i){
		m[i][i] = 1;
	}
}

void invMat4h(double im[][VEC_SIZE], double m[][VEC_SIZE]){
	double det;
	double u[VEC_SIZE], v[VEC_SIZE];
	det = m[0][0]*m[1][1]*m[2][2] + m[1][0]*m[2][1]*m[0][2] + m[2][0]*m[0][1]*m[1][2]
			- m[0][0]*m[2][1]*m[1][2] - m[2][0]*m[1][1]*m[0][2] - m[1][0]*m[0][1]*m[2][2];
	if(det == 0){
		printf("逆行列は存在しません\n");
	}else{
		im[0][0] = m[1][1]*m[2][2] - m[1][2]*m[2][1];
		im[0][1] = m[0][2]*m[2][1] - m[0][1]*m[2][2];
		im[0][2] = m[0][1]*m[1][2] - m[0][2]*m[1][1];

		im[1][0] = m[1][2]*m[2][0] - m[1][0]*m[2][2];
		im[1][1] = m[0][0]*m[2][2] - m[0][2]*m[2][0];
		im[1][2] = m[0][2]*m[1][0] - m[0][0]*m[1][2];

		im[2][0] = m[1][0]*m[2][1] - m[1][1]*m[2][0];
		im[2][1] = m[0][1]*m[2][0] - m[0][0]*m[2][1];
		im[2][2] = m[0][0]*m[1][1] - m[0][1]*m[1][0];

		for (int i = 0; i < VEC_SIZE; ++i){
			for (int j = 0; j < VEC_SIZE; ++j){
				im[i][j] = im[i][j] / det;
			}
		}

		for (int i = 0; i < VEC_SIZE; ++i){
			u[i] = 0.0;
			v[i] = m[i][VEC_SIZE-1];
		}
		u[VEC_SIZE-1] = 1.0;

		for(int i = 0; i< VEC_SIZE-1; ++i) {
			for(int j = 0; j < VEC_SIZE-1; ++j) {
				u[i] += im[i][j] * v[j];
			}
			im[i][VEC_SIZE-1] = -u[i];
		}
		im[VEC_SIZE-1][VEC_SIZE-1] = 1;
		printMat(im);
	}
}


int main(){
	double mat[VEC_SIZE][VEC_SIZE];
	double dst[VEC_SIZE][VEC_SIZE];

	double m0[VEC_SIZE] = {1,2,3,0};
	double m1[VEC_SIZE] = {-2,-10,4,0};
	double m2[VEC_SIZE] = {3,4,5,0};
	double p[VEC_SIZE] = {4,-5,6,1};

	setMatCol4h(mat, m0, m1, m2, p);

	invMat4h(dst, mat);

	return 0;
}