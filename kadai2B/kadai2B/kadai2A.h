
#ifndef _KADAI2A_DEF_
#define _KADAI2A_DEF_
#include "kadai.h"

// �֐��v���g�^�C�v�錾
// ���̗p�f�[�^���O���t�@�C������ǂݍ���
void InputDatFile(POINT p[], char *fname, double loop);
// �f�[�^���痧�̂�\�����W���Q�����z��Ɋi�[(�l�ʑ̗p)
void set_tetra(double vs[][VEC_SIZE]);
// �f�[�^���痧�̂�\�����W���Q�����z��Ɋi�[(�O�p���p)
void set_triprism(double vs[][VEC_SIZE], double h);
// �O�����@���x�N�g���쐬
void norm_triangle(double n[VEC_SIZE], double v0[VEC_SIZE], double v1[VEC_SIZE], double v2[VEC_SIZE]);
// STL�`���̊J�n�s���쐬
void prStlProlog(char *label, FILE *fp);
// STL�`���̏I���s���쐬
void prStlEpilog(char *label, FILE *fp);
// STL�`���̎O�p�`�p�b�`���쐬
void prStlFacet(double n[VEC_SIZE], double v0[VEC_SIZE], double v1[VEC_SIZE], double v2[VEC_SIZE], FILE *fp);
// �O�����@�������ɉE�˂����i�ޕ����̓_�̑g�ݍ��킹�쐬(�l�ʑ̗p)
void CombinationTetra(double vs[][VEC_SIZE], FILE *fp);
// STL�`���̎l�ʑ̍쐬
void prStlTetra(double vs[][VEC_SIZE], char *label);
// �O�����@�������ɉE�˂����i�ޕ����̓_�̑g�ݍ��킹�쐬(�O�p���p)
void CombinationTriprism(double vs[][VEC_SIZE], FILE *fp);
// STL�`���̎O�p���쐬
void prStlTriprism(double vs[][VEC_SIZE], char *label);
// �l�ʑ̂ƎO�p����STL�`���ł��ꂼ��쐬 (�ۑ�2A��1)
void stlb_k01(double tt[TETRA_V_NUM][VEC_SIZE], double tp[TRIPRISM_V_NUM][VEC_SIZE]);

// �͈͂Ə��]�̏����_�ȉ��̌������w�肵�ė����𓾂�
double GetRandom(double min, double max, int digit);
// �C�ӂ̌��_�ʒu�ƔC�ӂ̎����������V���ȍ��W�n�������_���ɍ쐬
AXIS randCoordinateAxis();
// �����ɂƂ����ϊ��s��𗧑̂�\�����Ă�����W�Q�Ɏ{��
void CalcRotationMat(POINT input[], POINT output[], double rotation_mat[][VEC_SIZE], int loop);
// ������(label)�ɂ���ė~��������(�l�ʑ̂��O�p���p)�������_���ȍ��W�n�ō쐬
void TransformPosition(char *label, FILE *fp);
// �ۑ�2A��2�����s����
void TransformPositionAll(char *label);
#endif