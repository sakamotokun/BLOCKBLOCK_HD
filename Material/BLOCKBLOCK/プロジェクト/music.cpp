// �C���N���[�h==========================
#include "music.h"

//=======================================

// �ϐ�==================================
static int nMP3Handle;
static int nWaveHandle;
//=======================================


// �^�C�g���̏������i�V�[���J�n���j=====
void MusicInitScene( void )
{

}
//=======================================


// �^�C�g���̏I�������i�V�[���I�����j===
void MusicUnInitScene( void )
{
	CLOSEMP3(nMP3Handle);       // ��~���N���[�Y
}
//=======================================


// �^�C�g���̏I�������i�V�[���I�����j===
void MusicUnInitEfect( void )
{
	CLOSEWAVE(nWaveHandle);
}
//=======================================


// �^�C�g���̍X�V����=================
void MusicJumpUpdate( void )
{
	nWaveHandle = OPENWAVE("jump.wav");    // �I�[�v����������
	if (nWaveHandle == 0)
	{
		printf("Wave�t�@�C���̍Đ������Ɏ��s���܂����B\n");
		exit(0);
	}
	PLAYWAVE(nWaveHandle, 0);

}
//====================================


// �^�C�g���̍X�V����=================
void MusicEnterUpdate( void )
{
	nWaveHandle = OPENWAVE("enter.wav");    // �I�[�v����������
	if (nWaveHandle == 0)
	{
		printf("Wave�t�@�C���̍Đ������Ɏ��s���܂����B\n");
		exit(0);
	}
	PLAYWAVE(nWaveHandle, 0);
}
//====================================


// �^�C�g���̍X�V����=================
void MusicTemaUpdate( void )
{
	nMP3Handle = OPENMP3("start.mp3");// �I�[�v����������
	if (nMP3Handle == 0)
	{
		printf("MP3�t�@�C���̍Đ������Ɏ��s���܂����B\n");
		exit(0);
	}
	PLAYMP3(nMP3Handle, 1);//�J�Ԃ��Đ�

}
//====================================


// �^�C�g���̍X�V����=================
void MusicRunUpdate( void )
{
	nMP3Handle = OPENMP3("run.mp3");// �I�[�v����������
	if (nMP3Handle == 0)
	{
		printf("MP3�t�@�C���̍Đ������Ɏ��s���܂����B\n");
		exit(0);
	}
	PLAYMP3(nMP3Handle, 1);//�J�Ԃ��Đ�

}
//====================================


// �^�C�g���̍X�V����=================
void MusicOverUpdate( void )
{
	nMP3Handle = OPENMP3("game over....mp3");// �I�[�v����������
	if (nMP3Handle == 0)
	{
		printf("MP3�t�@�C���̍Đ������Ɏ��s���܂����B\n");
		exit(0);
	}
	PLAYMP3(nMP3Handle, 1);//�J�Ԃ��Đ�

}
//====================================


// �^�C�g���̍X�V����=================
void MusicCompleteUpdate( void )
{
	nMP3Handle = OPENMP3("game crear.mp3");// �I�[�v����������
	if (nMP3Handle == 0)
	{
		printf("MP3�t�@�C���̍Đ������Ɏ��s���܂����B\n");
		exit(0);
	}
	PLAYMP3(nMP3Handle, 1);//�J�Ԃ��Đ�

}
//====================================
