#ifndef __TITLE_H__
#define __TITLE_H__

// プロトタイプ宣言========================
void TitleInit( void );// タイトルの初期化（一回のみ）
void TitleInitScene( void );// タイトルの初期化（シーン開始時）
void TitleUnInit( void );// タイトルの終了処理（一回のみ）
void TitleUnInitScene( void );// タイトルの終了処理（シーン終了時）
void TitleUpdate( void );// タイトルの更新処理
void TitleDraw( void );// タイトルの描画処理
//=========================================
#endif//__TITLE_H__