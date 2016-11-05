#ifndef __BUFFER_H__
#define __BUFFER_H__


// インクルード==================

//===============================



// 定義============================================================
// バッファサイズ
#define BUFF_X_MAX   80     // バッファ横数
#define BUFF_Y_MAX   25      // バッファ縦数
#define MAP_MAX      79     // MAPのおおきさ

// キャラサイズ
#define KYARA_X_MAX   3     // バッファ横数
#define KYARA_Y_MAX   3      // バッファ縦数

// 表示位置 補正
#define DISP_OFF_SET_X  1
#define DISP_OFF_SET_Y  1


//==================================================================


// 構造体===============================
//=======================================


// プロトタイプ宣言==============
void setBuffer( int x, int y, char moji );
void printBuffer( void );
void ClearGraphicsBuffs( void );
void GameBuffSet( int mode );
void TitleBuffSet( int mode );
void ResultBuffSet( int mode );
//===============================


#endif