// �C���N���[�h==========================
#include "main.h"
#include "app.h"
#include "inp.h"
#include "buffer.h"
#include "result.h"
#include "cscreen.h"
#include <stdio.h>
#include "map.h"
#include "music.h"

//=======================================

// �ϐ�==================================
	static int scene_fast=0;
	static int scene_next=0;
	static int Mode;
	static int end=1;
//=======================================


// ���U���g�̏������i���̂݁j==========
void ResultInit( void )
{

	ClearGraphicsBuffs( );
	Mode=APPMODE_RESULT1;
}
//=======================================

// ���U���g�̏������i���̂݁j==========
void ResultUnInit( void )
{

}
//=======================================


// ���U���g�̏������i�V�[���J�n���j=====
void Result1InitScene( void )
{
	MusicOverUpdate();
	scene_fast=0;
	scene_next=0;
	end=1;
	ResultBuffSet( RESULT_FAST_ID );
}
//=======================================


// ���U���g�̏������i�V�[���J�n���j=====
void Result2InitScene( void )
{
	MusicCompleteUpdate();
	scene_fast=0;
	scene_next=0;
	end=1;
	ResultBuffSet( RESULT_NEXT_ID );
}
//=======================================

// ���U���g�̏I�������i�V�[���I�����j===
void ResultUnInitScene( void )
{
	INPCLEAR( ); // �L�[�{�[�h�̓��͂��N���A
}
//=======================================



// ���U���g�̍X�V����=================
void Result1Update( void )
{


	int count=1;
		scene_fast+=count;
	if(scene_fast==5)
	{
		ResultBuffSet( RESULT_FAST_ID );
	}
	else if(scene_fast==40)
	{
		ResultBuffSet( RESULT_LAST_ID );
	}
	Mode=getResult1Key( );
	if(Mode==APPMODE_TITLE)
	{
		SetAppMode( APPMODE_TITLE );	//�V�[���ڍs
	}
}
//====================================



// ���U���g�̍X�V����=================
void Result2Update( void )
{


	int count=1;
		scene_fast+=count;
	if(scene_fast==5)
	{
		ResultBuffSet( RESULT_NEXT_ID );
	}
	else if(scene_fast==40)
	{
		ResultBuffSet( RESULT_LAST_ID );
	}
	Mode=getResult2Key( );
	if(Mode==APPMODE_TITLE)
	{
		SetAppMode( APPMODE_TITLE );	//�V�[���ڍs
	}
}
//====================================



//	���U���g�̕`�揈��================
void ResultDraw( void )
{

}
//====================================