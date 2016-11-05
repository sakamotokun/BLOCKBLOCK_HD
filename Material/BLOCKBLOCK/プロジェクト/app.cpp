// インクルード=====================
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


// 変数宣言=========================
static int iAppMode = APPMODE_GAME;
//==================================


// モード取得関数===================
int GetAppMode( void )
{
	return( iAppMode );
}
//==================================


// モード設定関数===================
void SetAppMode( int iMode )
{
	//シーン毎の終了処理
	switch( iAppMode )
	{
	case APPMODE_TITLE:		//タイトル
		TitleUnInitScene();
		MusicUnInitScene( );
		
		break;
	case APPMODE_GAME:		//ゲーム本編
		GameUnInitScene();
		MusicUnInitScene( );
		break;

	case APPMODE_RESULT1:		//ゲームオーバー画面
		ResultUnInitScene();
		MusicUnInitScene( );
		break;

	case APPMODE_RESULT2:		//ゲームクリア画面
		ResultUnInitScene();
		MusicUnInitScene( );
		break;
	}
	//モードの変更
	iAppMode = iMode;
	//シーン毎の初期化処理
	switch( iAppMode )
	{
	case APPMODE_TITLE:		//タイトル
		TitleInitScene();
		break;
	case APPMODE_GAME:		//ゲーム本編
		GameInitScene();
		PlayerInit();
		EnemyInit(MAP_FAST_ID);
		break;
	case APPMODE_RESULT1:		//ゲームオーバー画面
		Result1InitScene();
		break;
	case APPMODE_RESULT2:		//ゲームクリア画面
		Result2InitScene();
		break;
	}
}

//==================================


// アプリケーション全体の更新処理============
void AppUpdate( void )
{
	//モード毎の更新処理
	switch( iAppMode )
	{
	case APPMODE_TITLE:		//タイトル
		TitleUpdate();
		break;
	case APPMODE_GAME:		//ゲーム本編
		GameUpdate();
		break;
	case APPMODE_RESULT1:		//タイトル
		Result1Update();
		break;
	case APPMODE_RESULT2:		//ゲーム本編
		Result2Update();
		break;
	}
}

//===========================================

// アプリケーション全体の描画処理============
void AppDraw( void )
{
	printBuffer( );			//描画システムの更新

	//モード毎の描画処理
	switch( iAppMode )
	{
	case APPMODE_TITLE:		//タイトル
		TitleDraw();
		break;
	case APPMODE_GAME:		//ゲーム本編
		GameDraw();
		break;
	case APPMODE_RESULT1:		//ゲーム本編
		ResultDraw();
		break;
	case APPMODE_RESULT2:		//ゲーム本編
		ResultDraw();
		break;
	}
}
//===========================================