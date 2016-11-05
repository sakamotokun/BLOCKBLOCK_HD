// �C���N���[�h==========================
#include "main.h"
#include "app.h"
#include "inp.h"
#include "buffer.h"
#include "title.h"
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


// �^�C�g���̏������i���̂݁j==========
void TitleInit( void )
{
	ClearGraphicsBuffs( );
	Mode=APPMODE_TITLE;
}
//=======================================

// �^�C�g���̏������i���̂݁j==========
void TitleUnInit( void )
{
	scene_fast=0;
	scene_next=0;
	end=1;
}
//=======================================


// �^�C�g���̏������i�V�[���J�n���j=====
void TitleInitScene( void )
{
	MusicTemaUpdate();
	TitleBuffSet( TITLE_FAST_ID );
}
//=======================================


// �^�C�g���̏I�������i�V�[���I�����j===
void TitleUnInitScene( void )
{
	MusicUnInitEfect();
	scene_fast=0;
	scene_next=0;
	end=1;
}
//=======================================



// �^�C�g���̍X�V����=================
void TitleUpdate( void )
{

	if(end==1)
	{
		Mode=getTitleKey( );
	}

	int count=1;
	switch ( Mode )
	{
	case APPMODE_TITLE:
		scene_fast+=count;
		if(scene_fast==10)
		{
			TitleBuffSet( TITLE_NEXT_ID );
		}
		else if(scene_fast==20)
		{
			TitleBuffSet( TITLE_FAST_ID );
			scene_fast=0;
		}
		break;

	case APPMODE_GAME:
		end=0;
		scene_next+=count;
		if(scene_next==5)
		{
			TitleBuffSet( TITLE_LAST_ID );
		}
		else if(scene_next==40)
		{
			SetAppMode( APPMODE_GAME );	//�V�[���ڍs
		}
		break;
	}

}
//====================================



//	�^�C�g���̕`�揈��================
void TitleDraw( void )
{

}
//====================================