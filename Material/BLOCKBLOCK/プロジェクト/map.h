#ifndef __MAP_H__
#define __MAP_H__


// インクルード==================

//===============================



// 定義============================================================
#define TITLE_FAST_ID (1)//タイトル画面用
#define TITLE_NEXT_ID (2)//タイトル画面用
#define TITLE_LAST_ID (3)//タイトル画面用
#define MAP_FAST_ID (10)//入力画面用
#define MAP_NEXT_ID (11)//入力画面用
#define MAP_LAST_ID (12)//入力画面用
#define PLAYER_ID (20)//自分のターン用
#define ENEMY_ID (30)//相手のターン用
#define FIGHT_ID (40)//戦闘用
#define RESULT_FAST_ID (50)//結果用
#define RESULT_NEXT_ID (51)//結果用
#define RESULT_LAST_ID (52)//結果用
//==================================================================


// 構造体===============================
//=======================================


// プロトタイプ宣言==============
void Mapload( int mode );
char getMap( int x, int y );
void setTitle( int x, int y, int i );
char getTitle( int x, int y );
void setMap( int x, int y, int i );
char getplayer( int x, int y );
void setplayer( int x, int y, int i );
char getResult( int x, int y );
void setResult( int x, int y, int i );
//===============================


#endif