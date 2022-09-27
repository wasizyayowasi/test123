#include "DxLib.h"
#include "game.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//window���[�h�̐ݒ�
	ChangeWindowMode(Game::kWindowMode);
	//window���ݒ�
	SetMainWindowText(Game::kTitleText);
	//��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWidth,Game::kScreenHeight, Game::kScreenDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�

	//�_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0) {

		LONGLONG time = GetNowHiPerformanceCount();
		//��ʂ̃N���A
		ClearDrawScreen();

		DrawString(225,Game::kScreenHeight / 2,"git�̃e�X�g  �����������������������������������ĂƂȂɂʂ˂̂͂Ђӂւق܂݂ނ߂��������������",GetColor(255,255,255));
		DrawString(Game::kScreenWidth / 3, Game::kScreenHeight / 2 + 50, " ��A�ƁB�ł��B���d�s�v�c�ˁA����s�v�c�ˁB", GetColor(255, 255, 255));
		DrawString(Game::kScreenWidth / 2, Game::kScreenHeight / 2 + 100, "�������g�ݍ��킹", GetColor(255, 255, 255));

		//����ʂ�\��ʂɐ؂�ւ���
		ScreenFlip();

		//esc����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))break;

		//fps��60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667) {

		}

	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}