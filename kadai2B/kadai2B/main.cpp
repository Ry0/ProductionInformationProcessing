#include "kadai.h"

int main() {
	// �ۑ�2B��3�ł̗^����ꂽ�p�����[�^
	double Theta[5] = { 45.0 / 180.0*M_PI, 30.0 / 180.0*M_PI, 135.0 / 180.0*M_PI, -30.0 / 180.0*M_PI, 60.0 / 180.0*M_PI };
	// �X�P���g���}�ʂ�̃����N���Œ�`����ꍇ
	double Link_length_full[6] = { 3.0 / 2.0, 3.0 / 2.0, 2.0 / 2.0, 2.0 / 2.0, 1.0 / 2.0, 1.0 / 2.0 };
	// �A�[�����Ԃŕ������Ȃ��ꍇ
	double Link_length_short[6] = { 0.0, 3.0, 0.0, 2.0, 0.0, 1.0 };

	// GNUPLOT�Ń��{�b�g�̎p���Ɗe���̍��W�n����
	ForwardKinematics(Theta, Link_length_full);
	ShowTfAxis(Theta, Link_length_full);

	// ���ŗ^����ꂽ�p����STL�ŏo��
	LinkCreator(Theta, Link_length_short);

	OpenGnuplot();
	system("pause");
	return 0;
}