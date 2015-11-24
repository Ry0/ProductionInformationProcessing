#ifndef _KADAI2B_DEF_
#define _KADAI2B_DEF_
#include "kadai.h"

// �֐��v���g�^�C�v�錾
// ���{�b�g�A�[���̋t�^���w�v�Z(�e�֐ߊp�x�ƃ����N�̃p�����[�^�w��)
void ForwardKinematics(double joint[], double link[]);
// �e���ł̍��W�n���쐬���O���t�@�C���ɕۑ�
void ShowTfAxis(double joint[], double link[]);
// �����N���̂̍��i���f�����o��
void ArmOutputdat(double P[][VEC_SIZE]);
// �e���ł̍��W�n���������邽�߂̃t�@�C���쐬�⏕
void TfAxisOutputdat(double P[][VEC_SIZE], FILE *fpx, FILE *fpy, FILE *fpz);
// �����N�̃��f�����o�́�Gnuplot�ŉ���
void OutputPlt();
// �e�����N�̃p�[�c��STL�`���ŏo��
void OutputSTL(double part1[][VEC_SIZE], double part2[][VEC_SIZE], double part3[][VEC_SIZE]);
// �^����ꂽ�֐ߊp�x�ƃ����N������A�[���̎p�������߁ASTL�ŏo��
void LinkCreator(double joint[], double link[]);
// �����N�̏����p�����`
void set_arm(double Origin[][VEC_SIZE], double P[][VEC_SIZE], double h);
// �����N�̎p���Ɗe���̍��W�n����
int OpenGnuplot();
#endif