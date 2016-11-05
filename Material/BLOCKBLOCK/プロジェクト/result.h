#ifndef __RESULT_H__
#define __RESULT_H__

// プロトタイプ宣言========================
void ResultInit( void );// リザルトの初期化（一回のみ）
void Result1InitScene( void );// リザルトの初期化（シーン開始時）
void Result2InitScene( void );// リザルトの初期化（シーン開始時）
void ResultUnInit( void );// リザルトの終了処理（一回のみ）
void ResultUnInitScene( void );// リザルトの終了処理（シーン終了時）
void Result1Update( void );// リザルトの更新処理
void Result2Update( void );// リザルトの更新処理
void ResultDraw( void );// リザルトの描画処理
//=========================================
#endif//__RESULT_H__