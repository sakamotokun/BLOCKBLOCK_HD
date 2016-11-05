// インクルード==========================
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

// 変数==================================
	static int scene_fast=0;
	static int scene_next=0;
	static int Mode;
	static int end=1;
//=======================================


// リザルトの初期化（一回のみ）==========
void ResultInit( void )
{

	ClearGraphicsBuffs( );
	Mode=APPMODE_RESULT1;
}
//=======================================

// リザルトの初期化（一回のみ）==========
void ResultUnInit( void )
{

}
//=======================================


// リザルトの初期化（シーン開始時）=====
void Result1InitScene( void )
{
	MusicOverUpdate();
	scene_fast=0;
	scene_next=0;
	end=1;
	ResultBuffSet( RESULT_FAST_ID );
}
//=======================================


// リザルトの初期化（シーン開始時）=====
void Result2InitScene( void )
{
	MusicCompleteUpdate();
	scene_fast=0;
	scene_next=0;
	end=1;
	ResultBuffSet( RESULT_NEXT_ID );
}
//=======================================

// リザルトの終了処理（シーン終了時）===
void ResultUnInitScene( void )
{
	INPCLEAR( ); // キーボードの入力をクリア
}
//=======================================



// リザルトの更新処理=================
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
		SetAppMode( APPMODE_TITLE );	//シーン移行
	}
}
//====================================



// リザルトの更新処理=================
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
		SetAppMode( APPMODE_TITLE );	//シーン移行
	}
}
//====================================



//	リザルトの描画処理================
void ResultDraw( void )
{

}
//====================================