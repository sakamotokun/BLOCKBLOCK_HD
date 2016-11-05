// インクルード==========================
#include "music.h"

//=======================================

// 変数==================================
static int nMP3Handle;
static int nWaveHandle;
//=======================================


// タイトルの初期化（シーン開始時）=====
void MusicInitScene( void )
{

}
//=======================================


// タイトルの終了処理（シーン終了時）===
void MusicUnInitScene( void )
{
	CLOSEMP3(nMP3Handle);       // 停止＆クローズ
}
//=======================================


// タイトルの終了処理（シーン終了時）===
void MusicUnInitEfect( void )
{
	CLOSEWAVE(nWaveHandle);
}
//=======================================


// タイトルの更新処理=================
void MusicJumpUpdate( void )
{
	nWaveHandle = OPENWAVE("jump.wav");    // オープン＆初期化
	if (nWaveHandle == 0)
	{
		printf("Waveファイルの再生準備に失敗しました。\n");
		exit(0);
	}
	PLAYWAVE(nWaveHandle, 0);

}
//====================================


// タイトルの更新処理=================
void MusicEnterUpdate( void )
{
	nWaveHandle = OPENWAVE("enter.wav");    // オープン＆初期化
	if (nWaveHandle == 0)
	{
		printf("Waveファイルの再生準備に失敗しました。\n");
		exit(0);
	}
	PLAYWAVE(nWaveHandle, 0);
}
//====================================


// タイトルの更新処理=================
void MusicTemaUpdate( void )
{
	nMP3Handle = OPENMP3("start.mp3");// オープン＆初期化
	if (nMP3Handle == 0)
	{
		printf("MP3ファイルの再生準備に失敗しました。\n");
		exit(0);
	}
	PLAYMP3(nMP3Handle, 1);//繰返し再生

}
//====================================


// タイトルの更新処理=================
void MusicRunUpdate( void )
{
	nMP3Handle = OPENMP3("run.mp3");// オープン＆初期化
	if (nMP3Handle == 0)
	{
		printf("MP3ファイルの再生準備に失敗しました。\n");
		exit(0);
	}
	PLAYMP3(nMP3Handle, 1);//繰返し再生

}
//====================================


// タイトルの更新処理=================
void MusicOverUpdate( void )
{
	nMP3Handle = OPENMP3("game over....mp3");// オープン＆初期化
	if (nMP3Handle == 0)
	{
		printf("MP3ファイルの再生準備に失敗しました。\n");
		exit(0);
	}
	PLAYMP3(nMP3Handle, 1);//繰返し再生

}
//====================================


// タイトルの更新処理=================
void MusicCompleteUpdate( void )
{
	nMP3Handle = OPENMP3("game crear.mp3");// オープン＆初期化
	if (nMP3Handle == 0)
	{
		printf("MP3ファイルの再生準備に失敗しました。\n");
		exit(0);
	}
	PLAYMP3(nMP3Handle, 1);//繰返し再生

}
//====================================
