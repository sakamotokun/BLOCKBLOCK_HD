
// warning 対策
#define _CRT_SECURE_NO_DEPRECATE


#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "inp.h"
#include "map.h"
#include"buffer.h"
#include"app.h"

void main( void )
{

    // カーソル OFF
    CUROFF();
	SetAppMode( APPMODE_TITLE );
	//framerate　固定
	int time,timeold;
	timeBeginPeriod( 1 );         //タイマ精度を最高にする
	time=timeold=timeGetTime();
    // メインループ
    while( 1 )
    {
		//現在の時間取得
		time=timeGetTime();
		if(time-timeold>=(1000/40))
		{
			//frame　前の時間取得
			timeold=time;
			//更新処理
			AppUpdate();
			//描画処理
			AppDraw();

		}

    }

	timeEndPeriod(1);

    // 画面が消えてしまうので、入力待ちをする
    rewind( stdin );
    getchar();
}
