#ifndef __APP_H__
#define __APP_H__

// �\����========================================
enum					//�A�v���P�[�V�������[�h
{
	APPMODE_NONE = -1,	//��
	APPMODE_TITLE,		//�^�C�g��
	APPMODE_GAME,		//�Q�[���{��
	APPMODE_RESULT1,		//���U���g
	APPMODE_RESULT2,		//���U���g
	APPMODE_NUM			//����
};


//===============================================


// �v���g�^�C�v�錾==============================
int GetAppMode( void );//���[�h�擾�֐�
void SetAppMode( int iMode );// ���[�h�ݒ�֐�
void AppInit( void );// �A�v���P�[�V�����S�̂̏�����
void AppUnInit( void );// �A�v���P�[�V�����S�̂̏I������
void AppUpdate( void );// �A�v���P�[�V�����S�̂̍X�V����
void AppDraw( void );// �A�v���P�[�V�����S�̂̕`�揈��
//================================================


#endif//__APP_H__