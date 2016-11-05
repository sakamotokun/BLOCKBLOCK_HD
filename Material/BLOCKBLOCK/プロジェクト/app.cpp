// �C���N���[�h=====================
#include "inp.h"
#include "buffer.h"
#include "app.h"
#include "game.h"
#include "map.h"
#include "title.h"
#include "result.h"
#include "enemy.h"
#include "music.h"

//==================================


// �ϐ��錾=========================
static int iAppMode = APPMODE_GAME;
//==================================


// ���[�h�擾�֐�===================
int GetAppMode( void )
{
	return( iAppMode );
}
//==================================


// ���[�h�ݒ�֐�===================
void SetAppMode( int iMode )
{
	//�V�[�����̏I������
	switch( iAppMode )
	{
	case APPMODE_TITLE:		//�^�C�g��
		TitleUnInitScene();
		MusicUnInitScene( );
		
		break;
	case APPMODE_GAME:		//�Q�[���{��
		GameUnInitScene();
		MusicUnInitScene( );
		break;

	case APPMODE_RESULT1:		//�Q�[���I�[�o�[���
		ResultUnInitScene();
		MusicUnInitScene( );
		break;

	case APPMODE_RESULT2:		//�Q�[���N���A���
		ResultUnInitScene();
		MusicUnInitScene( );
		break;
	}
	//���[�h�̕ύX
	iAppMode = iMode;
	//�V�[�����̏���������
	switch( iAppMode )
	{
	case APPMODE_TITLE:		//�^�C�g��
		TitleInitScene();
		break;
	case APPMODE_GAME:		//�Q�[���{��
		GameInitScene();
		PlayerInit();
		EnemyInit(MAP_FAST_ID);
		break;
	case APPMODE_RESULT1:		//�Q�[���I�[�o�[���
		Result1InitScene();
		break;
	case APPMODE_RESULT2:		//�Q�[���N���A���
		Result2InitScene();
		break;
	}
}

//==================================


// �A�v���P�[�V�����S�̂̍X�V����============
void AppUpdate( void )
{
	//���[�h���̍X�V����
	switch( iAppMode )
	{
	case APPMODE_TITLE:		//�^�C�g��
		TitleUpdate();
		break;
	case APPMODE_GAME:		//�Q�[���{��
		GameUpdate();
		break;
	case APPMODE_RESULT1:		//�^�C�g��
		Result1Update();
		break;
	case APPMODE_RESULT2:		//�Q�[���{��
		Result2Update();
		break;
	}
}

//===========================================

// �A�v���P�[�V�����S�̂̕`�揈��============
void AppDraw( void )
{
	printBuffer( );			//�`��V�X�e���̍X�V

	//���[�h���̕`�揈��
	switch( iAppMode )
	{
	case APPMODE_TITLE:		//�^�C�g��
		TitleDraw();
		break;
	case APPMODE_GAME:		//�Q�[���{��
		GameDraw();
		break;
	case APPMODE_RESULT1:		//�Q�[���{��
		ResultDraw();
		break;
	case APPMODE_RESULT2:		//�Q�[���{��
		ResultDraw();
		break;
	}
}
//===========================================