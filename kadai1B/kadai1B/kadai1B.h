#ifndef _KADAI1B_DEF_ /* _KADAI1B_DEF_ ����`����Ă��Ȃ���Έȉ���ǂݍ��ށD*/
#define _KADAI1B_DEF_ /* _KADAI1B_DEF_ ���`���遁����͓ǂݍ��܂�Ȃ��D*/
#include "kadai1A.h"
#include "Struct.h"

// �֐��v���g�^�C�v�錾
// ���}�`�̓_��ǂݍ���
void InputDatFile(POINT p[], char *fname, double loop);
// Gnuplot�ŊJ���iUnix, Linux�p�j
int OpenGnuplot();
// �_�������[�v���ĊO���t�@�C���ɏ�������
void OutputDatFile(char *fname, POINT p[], double loop);

// �ۑ�1B��1�p��plt�t�@�C���쐬
void OutputRotatePlt(char *fname);
// �����ɂƂ����ϊ��s�����}�`�̓_�Ɏ{��
void CalcRotationMat(POINT input[], POINT output[], double rotation_mat[][VEC_SIZE], int loop);
// �ۑ�1B��1(a)�̉𓚍쐬
void rotateXYZ(double r_x, double r_y, double r_z);
// �ۑ�1B��1(b)�̉𓚍쐬
void rotateYZX(double r_x, double r_y, double r_z);

// �C�ӂ̌��_�ʒu�ƔC�ӂ̎����������V���ȍ��W�n�������_���ɍ쐬
AXIS randCoordinateAxis();
// �V���ȍ��W�n���v���b�g���邽�߂̃f�[�^�쐬
AXIS OutputRandomAxis();
// �ۑ�1B��2�p��plt�t�@�C���쐬
void OutPutPlt_kadai2(char *fname);
// �͈͂Ə��]�̏����_�ȉ��̌������w�肵�ė����𓾂�
double GetRandom(double min, double max, int digit);

// ���}�`�̍��W��V���ȍ��W���猩���Ƃ��̒l�𓾂�
void CoordinateTransform(AXIS axis);
// �ۑ�1B��3�p��plt�t�@�C���쐬
void OutPutPlt_kadai3(char *fname);

// �����_���ɍ쐬�������W�n������W�n�Ɉ�v������
void CoordinateTransformToOrigin(AXIS axis);
// �ۑ�1B��4�p��plt�t�@�C���쐬
void OutPutPlt_kadai4(char *fname);

// �ۑ�1B��3�Ɖۑ�1B��4�̌v�Z���ʊm�F
void TransformToOriginVector(AXIS axis);
// �ۑ�1B��5�p��plt�t�@�C���쐬
void OutPutPlt_kadai5(char *fname);
#endif