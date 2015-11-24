#ifndef _KADAI1A_DEF_
#define _KADAI1A_DEF_
#include "Struct.h"

// �֐��v���g�^�C�v�錾
/*------------------ �x�N�g���̊�{���Z ---------------------*/
// �x�N�g���̒��g�m�F
void printVec(double v[]);
// �x�N�g���̏�����
void setVec4h(double v[], double x, double y, double z);
//�x�N�g���̑傫��
double length4h(double v[]);
// �P�ʃx�N�g��
bool normalize4h(double u[], double v[]);
// �t�x�N�g��
void negate4h(double u[], double v[]);
// �x�N�g���a
void add4h(double u[], double v[], double p[]);
// �x�N�g����
void sub4h(double u[], double v[], double p[]);
// �x�N�g���̓���
double dot4h(double v0[], double v1[]);
// �x�N�g���̊O��
void cross4h(double u[], double v0[], double v1[]);
// �x�N�g���Ԃ̊p�x
double angle4h(double v0[], double v1[]);
// �����x�N�g����
void asDirVec4h(double v[]);
// �ʒu�x�N�g����
void asDirVec4h(double v[]);
/*------------- 3�����p�������W�s��̊e�퉉�Z ----------------*/
// �s��̉���
void printMat(double m[][VEC_SIZE]);
// ��x�N�g���ɂ��s���`
void setMatCol4h(double a[][VEC_SIZE], double v0[], double v1[], double v2[], double p[]);
// �s��̐�
void mulMM4h(double m01[][VEC_SIZE], double m0[][VEC_SIZE], double m1[][VEC_SIZE]);
// �s��ƃx�N�g���̐�
void mulMV4h(double u[], double m[][VEC_SIZE], double v[]);
// �_��̕ϊ�
void map4h(double us[][VEC_SIZE], double m[][VEC_SIZE], double vs[][VEC_SIZE], int num);
/*-------- 3�����̓������W�ϊ��s�� m �𐶐�����֐� -----------*/
// ���s�ړ�
void translate4h(double m[][VEC_SIZE], double v[]);
// �g��k��
void scale4h(double m[][VEC_SIZE], double a, double b, double c);
// XY ���ʑΏ�
void mirrorXY4h(double m[][VEC_SIZE]);
// YZ ���ʑΏ�
void mirrorYZ4h(double m[][VEC_SIZE]);
// ZX ���ʑΏ�
void mirrorZX4h(double m[][VEC_SIZE]);
// ���_�Ώ�
void mirrorO4h(double m[][VEC_SIZE]);
// X �����S��]
void rotateX4h(double m[][VEC_SIZE], double a); // X ���������ɉE�˂����i�މ�]������ a[rad] ��].
												// Y �����S��]
void rotateY4h(double m[][VEC_SIZE], double a); // Y ���������ɉE�˂����i�މ�]������ a[rad] ��].
												// Z �����S��]
void rotateZ4h(double m[][VEC_SIZE], double a); // Z ���������ɉE�˂����i�މ�]������ a[rad] ��].
												// X �����S��]
void rotateXSC4h(double m[][VEC_SIZE], double sv, double cv);
// Y �����S��]
void rotateYSC4h(double m[][VEC_SIZE], double sv, double cv);
// Z �����S��]
void rotateZSC4h(double m[][VEC_SIZE], double sv, double cv);
// �[���s��
void zeroMat4h(double m[][VEC_SIZE]);
// �P�ʍs��
void unitMat4h(double m[][VEC_SIZE]);
// �t�s��
void invMat4h(double im[][VEC_SIZE], double m[][VEC_SIZE]);
#endif