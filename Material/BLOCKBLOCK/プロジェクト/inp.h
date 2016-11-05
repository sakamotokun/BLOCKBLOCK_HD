#ifndef __INP_H__
#define __INP_H__


// インクルード==================

//===============================



// 定義============================================================
#define JUMP_HIGH 10		//ジャンプの高さ
//==================================================================


// 構造体===============================
typedef struct _POS
{
    int     x;
    int     y;

    int     xOld;
    int     yOld;
} POS;
//=======================================


// プロトタイプ宣言==============
void getPlayerKey( int *mode , int *y_cnt , int *yb , bool *j_flg );
int getTitleKey( void );
int getResult1Key( void );
int getResult2Key( void );
int getPlayerKeyFast( int *mode , int *y_cnt , int *yb , bool *j_flg );
int  getPlayerKeyNext( int *mode , int *y_cnt , int *yb , bool *j_flg );
int  getPlayerKeyLast( int *mode , int *y_cnt , int *yb , bool *j_flg );
void PlayerInit( void );
int GetPlayerInfoX( void );
int GetPlayerInfoXOLD( void );
int GetPlayerInfoY( void );
int GetPlayerInfoYOLD( void );
//===============================


#endif