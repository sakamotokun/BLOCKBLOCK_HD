// インクルード==========================
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

// 変数==================================
static int scene_fast=0;
static int scene_next=0;
static int Mode;
static int end=1;
//=======================================


// タイトルの初期化（一回のみ）==========
void TitleInit( void )
{
	ClearGraphicsBuffs( );
	Mode=APPMODE_TITLE;
}
//=======================================

// タイトルの初期化（一回のみ）==========
void TitleUnInit( void )
{
	scene_fast=0;
	scene_next=0;
	end=1;
}
//=======================================


// タイトルの初期化（シーン開始時）=====
void TitleInitScene( void )
{
	MusicTemaUpdate();
	TitleBuffSet( TITLE_FAST_ID );
}
//=======================================


// タイトルの終了処理（シーン終了時）===
void TitleUnInitScene( void )
{
	MusicUnInitEfect();
	scene_fast=0;
	scene_next=0;
	end=1;
}
//=======================================



// タイトルの更新処理=================
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
			SetAppMode( APPMODE_GAME );	//シーン移行
		}
		break;
	}

}
//====================================



//	タイトルの描画処理================
void TitleDraw( void )
{

}
//====================================