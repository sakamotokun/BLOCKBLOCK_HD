#ifndef __APP_H__
#define __APP_H__

// 構造体========================================
enum					//アプリケーションモード
{
	APPMODE_NONE = -1,	//無
	APPMODE_TITLE,		//タイトル
	APPMODE_GAME,		//ゲーム本編
	APPMODE_RESULT1,		//リザルト
	APPMODE_RESULT2,		//リザルト
	APPMODE_NUM			//総数
};


//===============================================


// プロトタイプ宣言==============================
int GetAppMode( void );//モード取得関数
void SetAppMode( int iMode );// モード設定関数
void AppInit( void );// アプリケーション全体の初期化
void AppUnInit( void );// アプリケーション全体の終了処理
void AppUpdate( void );// アプリケーション全体の更新処理
void AppDraw( void );// アプリケーション全体の描画処理
//================================================


#endif//__APP_H__