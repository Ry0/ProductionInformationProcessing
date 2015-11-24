#ifndef _KADAI3_DEF_ /* _KADAI3_DEF_ ����`����Ă��Ȃ���Έȉ���ǂݍ��ށD*/
#define _KADAI3_DEF_ /* _KADAI3_DEF_ ���`���遁����͓ǂݍ��܂�Ȃ��D*/
#include "kadai.h"

// �֐��v���g�^�C�v�錾
// �p�����[�^�x�N�g��(t0, t1, t2, t3)
void set_param_vector(double pv[BDIM + 1], double t);
// �s��~�x�N�g���̉��Z
void mulMVb(double u[BDIM + 1], double mb[BDIM + 1][BDIM + 1], double v[BDIM + 1]);
// ����_���X�g�~�x�N�g���̐�
void mulLCpVb(double u[HDIM], double cps[HDIM][BDIM + 1], double v[BDIM + 1]);
// �p�����[�^t�̂Ƃ��̃x�W�G�Ȑ���̓_�����߂�
void on_bezier3_curve(double q[HDIM], double mb[BDIM + 1][BDIM + 1], double cps[BDIM + 1][HDIM], double t);
// �x�W�G�Ȑ������߂�
void draw_bezier3();

// ����_�s��ƃx�N�g���̐ς����߂�
void mulMCpVb(double lcp[BDIM + 1][HDIM], double mcp[BDIM + 1][BDIM + 1][HDIM], double v[BDIM + 1]);
// ����_���O���t�@�C������ǂݍ���
void InputDatFile(double p[BDIM + 1][BDIM + 1][HDIM], char *fname);
// �p�����[�^(u,v)�̂Ƃ��̃x�W�G�Ȗʏ�̓_�����߂�
void on_bezier3_surface(double q[HDIM], double mb[BDIM + 1][BDIM + 1], double cps[BDIM + 1][BDIM + 1][HDIM], double u, double v);
// M_B^T P M_B �̍s������߂�
void calc_M_tPM(double output[BDIM + 1][BDIM + 1][HDIM], double input[BDIM + 1][BDIM + 1][HDIM], double M[BDIM + 1][BDIM + 1]);
// �p�����[�^��0����1�ɕω������āA�Ȗʂ����߂�
void draw_bezier3_surface();
// ���ʂ�Gnuplot�ŏo��
int OpenGnuplot();
#endif