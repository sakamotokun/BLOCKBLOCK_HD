// warning 対策
#define _CRT_SECURE_NO_DEPRECATE
#include "main.h"
#include "inp.h"
#include "map.h"
#include "game.h"
#include "buffer.h"
#include "app.h"
#include "enemy.h"
#include "music.h"

// 変数=============================
	static int p_mode;
	static int y_cnt;
	static int yb;
	static bool j_flg;
	static int Mode;
	static int Enemy1A=0;
	static int Enemy1B=0;
	static int Enemy1C=0;
	static int Enemy1D=0;
	static int Enemy1E=0;
	static int Enemy1F=0;
	static int Enemy2A=0;
	static int Enemy2B=0;
	static int Enemy2C=0;
	static int Enemy2D=0;
	static int Enemy2E=0;
	static int Enemy2F=0;
	static int nMP3Handle;
//==================================

// ゲーム初期化関数(シーンごと)========
void GameInitScene( void)
{
	MusicRunUpdate();
	Mapload( MAP_FAST_ID);
	GameBuffSet( MAP_FAST_ID );
	Mode=MAP_FAST_ID;

	p_mode = 0;
	y_cnt = 0;
	yb = 1;
	j_flg = false;
}
//====================================


// ゲーム終了処理関数(シーンごと)=======
void GameUnInitScene( void)
{
	
}
//====================================



// ゲームアップデート関数=============
void GameUpdate( void )
{
	POS enemy1A;
	enemy1A.x=GetEnemy1AInfoX();
	enemy1A.xOld=GetEnemy1AInfoXOLD();
	enemy1A.y=GetEnemy1AInfoY();
	enemy1A.yOld=GetEnemy1AInfoYOLD();
	POS enemy1B;
	enemy1B.x=GetEnemy1BInfoX();
	enemy1B.xOld=GetEnemy1BInfoXOLD();
	enemy1B.y=GetEnemy1BInfoY();
	enemy1B.yOld=GetEnemy1BInfoYOLD();
	POS enemy1C;
	enemy1C.x=GetEnemy1CInfoX();
	enemy1C.xOld=GetEnemy1CInfoXOLD();
	enemy1C.y=GetEnemy1CInfoY();
	enemy1C.yOld=GetEnemy1CInfoYOLD();
	POS enemy1D;
	enemy1D.x=GetEnemy1DInfoX();
	enemy1D.xOld=GetEnemy1DInfoXOLD();
	enemy1D.y=GetEnemy1DInfoY();
	enemy1D.yOld=GetEnemy1DInfoYOLD();
	POS enemy2A;
	enemy2A.x=GetEnemy2AInfoX();
	enemy2A.xOld=GetEnemy2AInfoXOLD();
	enemy2A.y=GetEnemy2AInfoY();
	enemy2A.yOld=GetEnemy2AInfoYOLD();
	POS enemy2B;
	enemy2B.x=GetEnemy2BInfoX();
	enemy2B.xOld=GetEnemy2BInfoXOLD();
	enemy2B.y=GetEnemy2BInfoY();
	enemy2B.yOld=GetEnemy2BInfoYOLD();
	POS enemy2C;
	enemy2C.x=GetEnemy2CInfoX();
	enemy2C.xOld=GetEnemy2CInfoXOLD();
	enemy2C.y=GetEnemy2CInfoY();
	enemy2C.yOld=GetEnemy2CInfoYOLD();
	POS enemy2D;
	enemy2D.x=GetEnemy2DInfoX();
	enemy2D.xOld=GetEnemy2DInfoXOLD();
	enemy2D.y=GetEnemy2DInfoY();
	enemy2D.yOld=GetEnemy2DInfoYOLD();
	POS enemy2E;
	enemy2E.x=GetEnemy2EInfoX();
	enemy2E.xOld=GetEnemy2EInfoXOLD();
	enemy2E.y=GetEnemy2EInfoY();
	enemy2E.yOld=GetEnemy2EInfoYOLD();
	POS enemy2F;
	enemy2F.x=GetEnemy2FInfoX();
	enemy2F.xOld=GetEnemy2FInfoXOLD();
	enemy2F.y=GetEnemy2FInfoY();
	enemy2F.yOld=GetEnemy2FInfoYOLD();
	POS player;
	player.x=GetPlayerInfoX();
	player.xOld=GetPlayerInfoXOLD();
	player.y=GetPlayerInfoY();
	player.yOld=GetPlayerInfoYOLD();
	int x,y;
	int Aaxold,Aayold;
	int Abxold,Abyold;
	int Acxold,Acyold;
	int Baxold,Bayold;
	int Bbxold,Bbyold;
	int Bcxold,Bcyold;
	int Bdxold,Bdyold;
	int Bexold,Beyold;
	char mapinfo;
	char mapinfo1A;
	char mapinfo1B;
	char mapinfo1C;
	char mapinfo2A;
	char mapinfo2B;
	char mapinfo2C;
	char mapinfo2D;
	char mapinfo2E;


	switch ( Mode )
	{

	case MAP_FAST_ID:
		Enemy1A=Enemy1AUpdate( );
		Enemy1B=Enemy1BUpdate( );
		Enemy1C=Enemy1CUpdate( );
		Enemy2A=Enemy2AUpdate( );
		Enemy2B=Enemy2BUpdate( );
		Enemy2C=Enemy2CUpdate( );
		Enemy2D=Enemy2DUpdate( );
		Aayold=enemy1A.yOld;
		Aaxold=enemy1A.xOld;
		Abyold=enemy1B.yOld;
		Abxold=enemy1B.xOld;
		Acyold=enemy1C.yOld;
		Acxold=enemy1C.xOld;
		Bayold=enemy2A.yOld;
		Baxold=enemy2A.xOld;
		Bbyold=enemy2B.yOld;
		Bbxold=enemy2B.xOld;
		Bcyold=enemy2C.yOld;
		Bcxold=enemy2C.xOld;
		Bdyold=enemy2D.yOld;
		Bdxold=enemy2D.xOld;
		// キー入力
		Mode=getPlayerKeyFast( &p_mode , &y_cnt , &yb , &j_flg );
		if( Mode==MAP_NEXT_ID )
		{

			mapinfo1A=getMap(enemy1A.y,enemy1A.x);
			mapinfo1B=getMap(enemy1B.y,enemy1B.x);
			mapinfo1C=getMap(enemy1C.y,enemy1C.x);
			mapinfo2A=getMap(enemy2A.y,enemy2A.x);
			mapinfo2B=getMap(enemy2B.y,enemy2B.x);
			mapinfo2C=getMap(enemy2C.y,enemy2C.x);
			mapinfo2D=getMap(enemy2D.y,enemy2D.x);
			setBuffer( enemy1A.x, enemy1A.y, mapinfo1A );      // 足跡消し
			setBuffer( enemy1B.x, enemy1B.y, mapinfo1B );      // 足跡消し
			setBuffer( enemy1C.x, enemy1C.y, mapinfo1C );      // 足跡消し
			setBuffer( enemy2A.x, enemy2A.y, mapinfo2A );      // 足跡消し
			setBuffer( enemy2B.x, enemy2B.y, mapinfo2B );      // 足跡消し
			setBuffer( enemy2C.x, enemy2C.y, mapinfo2C );      // 足跡消し
			setBuffer( enemy2D.x, enemy2D.y, mapinfo2D );      // 足跡消し
			EnemyInit( MAP_NEXT_ID );
			GameBuffSet( MAP_NEXT_ID );
		}
		else
		{
			y=player.yOld;
			x=player.xOld;
			// キャラクタをバッファに書き込む
			mapinfo=getMap(y,x);
			mapinfo1A=getMap(Aayold,Aaxold);
			mapinfo1B=getMap(Abyold,Abxold);
			mapinfo1C=getMap(Acyold,Acxold);
			mapinfo2A=getMap(Bayold,Baxold);
			mapinfo2B=getMap(Bbyold,Bbxold);
			mapinfo2C=getMap(Bcyold,Bcxold);
			mapinfo2D=getMap(Bdyold,Bdxold);

			if(Enemy1A==0)
			{
				setBuffer( enemy1A.xOld, enemy1A.yOld, mapinfo1A );      // 足跡消し
				setBuffer( enemy1A.x, enemy1A.y, '7' );            // プレイヤー書き込み
			}
			if(Enemy1A==CLEAR_ENEMY_1A)
			{
				setBuffer( enemy1A.xOld, enemy1A.yOld, mapinfo1A );      // 足跡消し
				Enemy1A=0;
			}
			if(Enemy1B==0)
			{
				setBuffer( enemy1B.xOld, enemy1B.yOld, mapinfo1B );      // 足跡消し
				setBuffer( enemy1B.x, enemy1B.y, '7' );            // プレイヤー書き込み
			}
			if(Enemy1B==CLEAR_ENEMY_1B)
			{
				setBuffer( enemy1B.xOld, enemy1B.yOld, mapinfo1B );      // 足跡消し
				Enemy1B=0;
			}
			if(Enemy1C==0)
			{
				setBuffer( enemy1C.xOld, enemy1C.yOld, mapinfo1C );      // 足跡消し
				setBuffer( enemy1C.x, enemy1C.y, '7' );            // プレイヤー書き込み
			}
			if(Enemy1C==CLEAR_ENEMY_1C)
			{
				setBuffer( enemy1C.xOld, enemy1C.yOld, mapinfo1C );      // 足跡消し
				Enemy1C=0;
			}
			if(Enemy2A==0)
			{
				setBuffer( enemy2A.xOld, enemy2A.yOld, mapinfo2A );      // 足跡消し
				setBuffer( enemy2A.x, enemy2A.y, '6' );            // プレイヤー書き込み
			}
			if(Enemy2A==CLEAR_ENEMY_2A)
			{
				setBuffer( enemy2A.xOld, enemy2A.yOld, mapinfo2A );      // 足跡消し
				Enemy2A=0;
			}
			if(Enemy2B==0)
			{
				setBuffer( enemy2B.xOld, enemy2B.yOld, mapinfo2B );      // 足跡消し
				setBuffer( enemy2B.x, enemy2B.y, '6' );            // プレイヤー書き込み
			}
			if(Enemy2B==CLEAR_ENEMY_2B)
			{
				setBuffer( enemy2B.xOld, enemy2B.yOld, mapinfo2B );      // 足跡消し
				Enemy2B=0;
			}
			if(Enemy2C==0)
			{
				setBuffer( enemy2C.xOld, enemy2C.yOld, mapinfo2C );      // 足跡消し
				setBuffer( enemy2C.x, enemy2C.y, '6' );            // プレイヤー書き込み
			}
			if(Enemy2C==CLEAR_ENEMY_2C)
			{
				setBuffer( enemy2C.xOld, enemy2C.yOld, mapinfo2C );      // 足跡消し
				Enemy2C=0;
			}
			if(Enemy2D==0)
			{
				setBuffer( enemy2D.xOld, enemy2D.yOld, mapinfo2D );      // 足跡消し
				setBuffer( enemy2D.x, enemy2D.y, '6' );            // プレイヤー書き込み
			}
			if(Enemy2D==CLEAR_ENEMY_2D)
			{
				setBuffer( enemy2D.xOld, enemy2D.yOld, mapinfo2D );      // 足跡消し
				Enemy2D=0;
			}
			setBuffer( player.xOld, player.yOld, mapinfo );      // 足跡消し
			setBuffer( player.x, player.y, '5' );            // プレイヤー書き込み
		}
		break;

	case MAP_NEXT_ID:
		Enemy1A=Enemy1AUpdate( );
		Enemy1B=Enemy1BUpdate( );
		Enemy2A=Enemy2AUpdate( );
		Enemy2B=Enemy2BUpdate( );
		Enemy2C=Enemy2CUpdate( );
		Aayold=enemy1A.yOld;
		Aaxold=enemy1A.xOld;
		Abyold=enemy1B.yOld;
		Abxold=enemy1B.xOld;
		Bayold=enemy2A.yOld;
		Baxold=enemy2A.xOld;
		Bbyold=enemy2B.yOld;
		Bbxold=enemy2B.xOld;
		Bcyold=enemy2C.yOld;
		Bcxold=enemy2C.xOld;
		// キー入力
		Mode=getPlayerKeyNext( &p_mode , &y_cnt , &yb , &j_flg );
		if( Mode==MAP_LAST_ID )
		{
			GameBuffSet( MAP_LAST_ID );
			mapinfo1A=getMap(enemy1A.y,enemy1A.x);
			mapinfo1B=getMap(enemy1B.y,enemy1B.x);
			mapinfo2A=getMap(enemy2A.y,enemy2A.x);
			mapinfo2B=getMap(enemy2B.y,enemy2B.x);
			mapinfo2C=getMap(enemy2C.y,enemy2C.x);
			setBuffer( enemy1A.x, enemy1A.y, mapinfo1A );      // 足跡消し
			setBuffer( enemy1B.x, enemy1B.y, mapinfo1B );      // 足跡消し
			setBuffer( enemy2A.x, enemy2A.y, mapinfo2A );      // 足跡消し
			setBuffer( enemy2B.x, enemy2B.y, mapinfo2B );      // 足跡消し
			setBuffer( enemy2C.x, enemy2C.y, mapinfo2C );      // 足跡消し
			EnemyInit( MAP_LAST_ID );
			GameBuffSet( MAP_LAST_ID );
			
		}
		else
		{
			y=player.yOld;
			x=player.xOld;

			mapinfo=getMap(y,x);
			mapinfo1A=getMap(Aayold,Aaxold);
			mapinfo1B=getMap(Abyold,Abxold);
			mapinfo2A=getMap(Bayold,Baxold);
			mapinfo2B=getMap(Bbyold,Bbxold);
			mapinfo2C=getMap(Bcyold,Bcxold);
			// キャラクタをバッファに書き込む
			if(Enemy1A==0)
			{
				setBuffer( enemy1A.xOld, enemy1A.yOld, mapinfo1A );      // 足跡消し
				setBuffer( enemy1A.x, enemy1A.y, '7' );            // プレイヤー書き込み
			}
			if(Enemy1A==CLEAR_ENEMY_1A)
			{
				setBuffer( enemy1A.xOld, enemy1A.yOld, mapinfo1A );      // 足跡消し
				Enemy1A=0;
			}
			if(Enemy1B==0)
			{
				setBuffer( enemy1B.xOld, enemy1B.yOld, mapinfo1B );      // 足跡消し
				setBuffer( enemy1B.x, enemy1B.y, '7' );            // プレイヤー書き込み
			}
			if(Enemy1B==CLEAR_ENEMY_1B)
			{
				setBuffer( enemy1B.xOld, enemy1B.yOld, mapinfo1B );      // 足跡消し
				Enemy1B=0;
			}
			if(Enemy2A==0)
			{
				setBuffer( enemy2A.xOld, enemy2A.yOld, mapinfo2A );      // 足跡消し
				setBuffer( enemy2A.x, enemy2A.y, '6' );            // プレイヤー書き込み
			}
			if(Enemy2A==CLEAR_ENEMY_2A)
			{
				setBuffer( enemy2A.xOld, enemy2A.yOld, mapinfo2A );      // 足跡消し
				Enemy2A=0;
			}
			if(Enemy2B==0)
			{
				setBuffer( enemy2B.xOld, enemy2B.yOld, mapinfo2B );      // 足跡消し
				setBuffer( enemy2B.x, enemy2B.y, '6' );            // プレイヤー書き込み
			}
			if(Enemy2B==CLEAR_ENEMY_2B)
			{
				setBuffer( enemy2B.xOld, enemy2B.yOld, mapinfo2B );      // 足跡消し
				Enemy2B=0;
			}
			if(Enemy2C==0)
			{
				setBuffer( enemy2C.xOld, enemy2C.yOld, mapinfo2C );      // 足跡消し
				setBuffer( enemy2C.x, enemy2C.y, '6' );            // プレイヤー書き込み
			}
			if(Enemy2C==CLEAR_ENEMY_2C)
			{
				setBuffer( enemy2C.xOld, enemy2C.yOld, mapinfo2C );      // 足跡消し
				Enemy2C=0;
			}
			setBuffer( player.xOld, player.yOld, mapinfo );      // 足跡消し
			setBuffer( player.x, player.y, '5' );            // プレイヤー書き込み
		}
		break;


	case MAP_LAST_ID:
		Enemy1A=Enemy1AUpdate( );
		Enemy1B=Enemy1BUpdate( );
		Enemy1C=Enemy1CUpdate( );
		Enemy2A=Enemy2AUpdate( );
		Enemy2B=Enemy2BUpdate( );
		Enemy2C=Enemy2CUpdate( );
		Enemy2D=Enemy2DUpdate( );
		Enemy2E=Enemy2EUpdate( );
		Aayold=enemy1A.yOld;
		Aaxold=enemy1A.xOld;
		Abyold=enemy1B.yOld;
		Abxold=enemy1B.xOld;
		Acyold=enemy1C.yOld;
		Acxold=enemy1C.xOld;
		Bayold=enemy2A.yOld;
		Baxold=enemy2A.xOld;
		Bbyold=enemy2B.yOld;
		Bbxold=enemy2B.xOld;
		Bcyold=enemy2C.yOld;
		Bcxold=enemy2C.xOld;
		Bdyold=enemy2D.yOld;
		Bdxold=enemy2D.xOld;
		Beyold=enemy2E.yOld;
		Bexold=enemy2E.xOld;
		// キー入力
		Mode=getPlayerKeyLast( &p_mode , &y_cnt , &yb , &j_flg );
		y=player.yOld;
		x=player.xOld;
		// キャラクタをバッファに書き込む
		mapinfo=getMap(y,x);
		mapinfo1A=getMap(enemy1A.y,enemy1A.x);
		mapinfo1B=getMap(enemy1B.y,enemy1B.x);
		mapinfo1C=getMap(enemy1C.y,enemy1C.x);
		mapinfo2A=getMap(enemy2A.y,enemy2A.x);
		mapinfo2B=getMap(enemy2B.y,enemy2B.x);
		mapinfo2C=getMap(enemy2C.y,enemy2C.x);
		mapinfo2D=getMap(enemy2D.y,enemy2D.x);
		mapinfo2E=getMap(enemy2E.y,enemy2E.x);
		if(Enemy1A==0)
		{
			setBuffer( enemy1A.xOld, enemy1A.yOld, mapinfo1A );      // 足跡消し
			setBuffer( enemy1A.x, enemy1A.y, '7' );            // プレイヤー書き込み
		}
		if(Enemy1A==CLEAR_ENEMY_1A)
		{
			setBuffer( enemy1A.xOld, enemy1A.yOld, mapinfo1A );      // 足跡消し
			Enemy1A=0;
		}
		if(Enemy1B==0)
		{
			setBuffer( enemy1B.xOld, enemy1B.yOld, mapinfo1B );      // 足跡消し
			setBuffer( enemy1B.x, enemy1B.y, '7' );            // プレイヤー書き込み
		}
		if(Enemy1B==CLEAR_ENEMY_1B)
		{
			setBuffer( enemy1B.xOld, enemy1B.yOld, mapinfo1B );      // 足跡消し
			Enemy1B=0;
		}
		if(Enemy1C==0)
		{
			setBuffer( enemy1C.xOld, enemy1C.yOld, mapinfo1C );      // 足跡消し
			setBuffer( enemy1C.x, enemy1C.y, '7' );            // プレイヤー書き込み
		}
		if(Enemy1C==CLEAR_ENEMY_1C)
		{
			setBuffer( enemy1C.xOld, enemy1C.yOld, mapinfo1C );      // 足跡消し
			Enemy1C=0;
		}
		if(Enemy2A==0)
		{
			setBuffer( enemy2A.xOld, enemy2A.yOld, mapinfo2A );      // 足跡消し
			setBuffer( enemy2A.x, enemy2A.y, '6' );            // プレイヤー書き込み
		}
		if(Enemy2A==CLEAR_ENEMY_2A)
		{
			setBuffer( enemy2A.xOld, enemy2A.yOld, mapinfo2A );      // 足跡消し
			Enemy2A=0;
		}
		if(Enemy2B==0)
		{
			setBuffer( enemy2B.xOld, enemy2B.yOld, mapinfo2B );      // 足跡消し
			setBuffer( enemy2B.x, enemy2B.y, '6' );            // プレイヤー書き込み
		}
		if(Enemy2B==CLEAR_ENEMY_2B)
		{
			setBuffer( enemy2B.xOld, enemy2B.yOld, mapinfo2B );      // 足跡消し
			Enemy2B=0;
		}
		if(Enemy2C==0)
		{
			setBuffer( enemy2C.xOld, enemy2C.yOld, mapinfo2C );      // 足跡消し
			setBuffer( enemy2C.x, enemy2C.y, '6' );            // プレイヤー書き込み
		}
		if(Enemy2C==CLEAR_ENEMY_2C)
		{
			setBuffer( enemy2C.xOld, enemy2C.yOld, mapinfo2C );      // 足跡消し
			Enemy2C=0;
		}
		if(Enemy2D==0)
		{
			setBuffer( enemy2D.xOld, enemy2D.yOld, mapinfo2D );      // 足跡消し
			setBuffer( enemy2D.x, enemy2D.y, '6' );            // プレイヤー書き込み
		}
		if(Enemy2D==CLEAR_ENEMY_2D)
		{
			setBuffer( enemy2D.xOld, enemy2D.yOld, mapinfo2D );      // 足跡消し
			Enemy2D=0;
		}
		if(Enemy2E==0)
		{
			setBuffer( enemy2E.xOld, enemy2E.yOld, mapinfo2E );      // 足跡消し
			setBuffer( enemy2E.x, enemy2E.y, '6' );            // プレイヤー書き込み
		}
		if(Enemy2E==CLEAR_ENEMY_2E)
		{
			setBuffer( enemy2E.xOld, enemy2E.yOld, mapinfo2E );      // 足跡消し
			Enemy2E=0;
		}
		setBuffer( player.xOld, player.yOld, mapinfo );      // 足跡消し
		setBuffer( player.x, player.y, '5' );            // プレイヤー書き込み
		break;

		case RESULT_FAST_ID:
			SetAppMode( APPMODE_RESULT1 );	//シーン移行
			break;

		case RESULT_NEXT_ID:
			SetAppMode( APPMODE_RESULT2 );	//シーン移行
			break;
	}
}

//====================================


// ゲーム描画=========================
void GameDraw( void )
{

}
//====================================