// インクルード=============
#include"main.h"
#include"buffer.h"
#include"game.h"
#include "map.h"

// =========================


// 変数宣言=================
   static char    bufferDraw[ BUFF_Y_MAX ][ BUFF_X_MAX ];   // 描画用
   static char    bufferDisp[ BUFF_Y_MAX ][ BUFF_X_MAX ];   // 表示用
   static int count=0;
//==========================


// バッファにデータを書き込む関数===================
void setBuffer( int x, int y, char moji )
{
	char *p = &bufferDraw[0][0];
    // バッファオーバーを防ぐために必ず行う
    if( (x > -1) && (x < BUFF_X_MAX) 
     && (y > -1) && (y < BUFF_Y_MAX) )
    {
        // アドレス計算できるようになろう！！
        *( p + (y * BUFF_X_MAX) + x ) = moji;
    }
}
//===================================================

// 表示処理=======================================
void printBuffer( void )
{
	char *p0=&bufferDisp[0][0];
	char *p1=&bufferDraw[0][0];
    int loopX, loopY;
    char *w0, *w1;      // アドレス計算用ポインタ


    // 縦のループ
    for( loopY=0; loopY<BUFF_Y_MAX; loopY++)
    {
        // 横のループ
        for( loopX=0; loopX<BUFF_X_MAX; loopX++)
        {
            // バッファのアドレス計算
            w0 = p0 + (loopY * BUFF_X_MAX) + loopX;
            w1 = p1 + (loopY * BUFF_X_MAX) + loopX;

            // バッファの内容確認
            if( *w0 != *w1 )
            {
                // バッファに変更があった場合描画
                LOCATE( loopX + DISP_OFF_SET_X, loopY + DISP_OFF_SET_Y );
           //     printf( "%c", *w1 );
				switch(*w1-'0')
				{
					break;
				case 1:
					COLOR(WHITE,RED);
					printf(" ");
					break;
				case 3:
					COLOR(WHITE,PINK);
					printf(" ");
					break;
				case 5:
					COLOR(WHITE,BLUE);
					printf(" ");
					break;
				case 6:
					COLOR(WHITE,GREEN);
					printf(" ");
					break;
				case 7:
					COLOR(WHITE,YELLOW);
					printf(" ");
					break;
				case 8:
					COLOR(WHITE,BLACK);
					printf(" ");
					break;
				default:
					COLOR(WHITE,WHITE);
					printf(" ");
					break;
				}

                // バッファの更新
                *w0 = *w1;
            }
        }
    }
	LOCATE(1,1);
}
// ===============================================

// 画面クリア=====================================
void ClearGraphicsBuffs( void )
{
	int i,j;
	//領域クリア
	for(i=0;i<BUFF_Y_MAX;++i)
	{
		for(j=0;j<BUFF_X_MAX;++j)
		{
			bufferDisp[i][j] = 0;
			bufferDraw[i][j] = 0;
		}
	}
	//画面クリア
	CLS();
}

//================================================

// ゲーム時のバッファ初期化========================
void GameBuffSet( int mode )
{
	int     loopX, loopY;
	int mapinfo;
	switch ( mode )
	{
		case MAP_FAST_ID:
			// ループ用
			Mapload( MAP_FAST_ID );
			// バッファ初期化
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// バッファの初期化
					mapinfo=getMap(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =mapinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;

		case MAP_NEXT_ID:
			// ループ用
			Mapload( MAP_NEXT_ID );
			// バッファ初期化
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// バッファの初期化
					mapinfo=getMap(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =mapinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;


		case MAP_LAST_ID:
			// ループ用
			Mapload( MAP_LAST_ID );
			// バッファ初期化
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// バッファの初期化
					mapinfo=getMap(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =mapinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;
	}
}
//=================================================


// タイトル時のバッファ初期化========================
void TitleBuffSet( int mode )
{
	int     loopX, loopY;
	int titleinfo;

	switch ( mode )
	{

		case TITLE_FAST_ID:
			// ループ用

			Mapload( TITLE_FAST_ID );
			// バッファ初期化
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// バッファの初期化
					titleinfo=getTitle(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =titleinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;

		case TITLE_NEXT_ID:
			// ループ用
			Mapload( TITLE_NEXT_ID );
			// バッファ初期化
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// バッファの初期化
					titleinfo=getTitle(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =titleinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;

		case TITLE_LAST_ID:
			// ループ用
			Mapload( TITLE_LAST_ID );
			// バッファ初期化
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// バッファの初期化
					titleinfo=getTitle(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =titleinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;
	}
}
//=================================================



// リザルト時のバッファ初期化========================
void ResultBuffSet( int mode )
{
	int     loopX, loopY;
	int resultinfo;

	switch ( mode )
	{

		case RESULT_FAST_ID:
			// ループ用

			Mapload( RESULT_FAST_ID );
			// バッファ初期化
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// バッファの初期化
					resultinfo=getResult(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =resultinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;

		case RESULT_NEXT_ID:
			// ループ用
			Mapload( RESULT_NEXT_ID );
			// バッファ初期化
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// バッファの初期化
					resultinfo=getResult(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =resultinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;

		case RESULT_LAST_ID:
			// ループ用
			Mapload( RESULT_LAST_ID );
			// バッファ初期化
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// バッファの初期化
					resultinfo=getResult(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =resultinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;
	}
}
//=================================================

