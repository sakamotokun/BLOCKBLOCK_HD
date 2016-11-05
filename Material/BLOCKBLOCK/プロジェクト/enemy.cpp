#include "inp.h"
#include "main.h"
#include "map.h"
#include "buffer.h"
#include "game.h"
#include "app.h"
#include "enemy.h"

// 変数===========================
static int Enemy_Num=6;
static POS sEnemy1AInfo; //プレーヤー情報
static POS sEnemy1BInfo; //プレーヤー情報
static POS sEnemy1CInfo; //プレーヤー情報
static POS sEnemy1DInfo; //プレーヤー情報
static POS sEnemy1EInfo; //プレーヤー情報
static POS sEnemy1FInfo; //プレーヤー情報
static POS sEnemy2AInfo; //プレーヤー情報
static POS sEnemy2BInfo; //プレーヤー情報
static POS sEnemy2CInfo; //プレーヤー情報
static POS sEnemy2DInfo; //プレーヤー情報
static POS sEnemy2EInfo; //プレーヤー情報
static POS sEnemy2FInfo; //プレーヤー情報
static int Uncount1A=0;
static int Uncount1B=0;
static int Uncount1C=0;
static int Uncount1D=0;
static int Uncount1E=0;
static int Uncount1F=0;
static int Uncount2A=0;
static int Uncount2B=0;
static int Uncount2C=0;
static int Uncount2D=0;
static int Uncount2E=0;
static int Uncount2F=0;
static int count1A=0;
static int count1B=0;
static int count1C=0;
static int count1D=0;
static int count1E=0;
static int count1F=0;
static int count2A=0;
static int count2B=0;
static int count2C=0;
static int count2D=0;
static int count2E=0;
static int count2F=0;
static int move1A=1;
static int move1B=1;
static int move1C=1;
static int move2D=1;
//================================


// プレイヤー初期化関数(1回)=====================
void EnemyInit( int Mode )
{
	switch(Mode)
	{
	case MAP_FAST_ID:
			sEnemy1AInfo.x=31;
			sEnemy1AInfo.xOld=31;
			sEnemy1AInfo.y=18;
			sEnemy1AInfo.yOld=18;
			count1A=0;
			Uncount1A=0;
			move1A=1;
			sEnemy1BInfo.x=46;
			sEnemy1BInfo.xOld=46;
			sEnemy1BInfo.y=15;
			sEnemy1BInfo.yOld=15;
			count1B=0;
			Uncount1B=0;
			move1B=1;
			sEnemy1CInfo.x=67;
			sEnemy1CInfo.xOld=67;
			sEnemy1CInfo.y=19;
			sEnemy1CInfo.yOld=19;
			count1C=0;
			Uncount1C=0;
			move1C=1;
			sEnemy2AInfo.x=18;
			sEnemy2AInfo.xOld=18;
			sEnemy2AInfo.y=24;
			sEnemy2AInfo.yOld=24;
			count2A=0;
			Uncount2A=0;
			sEnemy2BInfo.x=33;
			sEnemy2BInfo.xOld=33;
			sEnemy2BInfo.y=24;
			sEnemy2BInfo.yOld=24;
			count2B=0;
			Uncount2B=0;
			sEnemy2CInfo.x=50;
			sEnemy2CInfo.xOld=50;
			sEnemy2CInfo.y=24;
			sEnemy2CInfo.yOld=24;
			count2C=0;
			Uncount2C=0;
			sEnemy2DInfo.x=68;
			sEnemy2DInfo.xOld=68;
			sEnemy2DInfo.y=24;
			sEnemy2DInfo.yOld=24;
			count2D=0;
			Uncount2D=0;
			break;

	case MAP_NEXT_ID:
			sEnemy1AInfo.x=28;
			sEnemy1AInfo.xOld=28;
			sEnemy1AInfo.y=13;
			sEnemy1AInfo.yOld=13;
			count1A=0;
			Uncount1A=0;
			move1A=1;
			sEnemy1BInfo.x=65;
			sEnemy1BInfo.xOld=65;
			sEnemy1BInfo.y=9;
			sEnemy1BInfo.yOld=9;
			count1B=0;
			Uncount1B=0;
			move1B=1;
			sEnemy2AInfo.x=15;
			sEnemy2AInfo.xOld=15;
			sEnemy2AInfo.y=24;
			sEnemy2AInfo.yOld=24;
			count2A=0;
			Uncount2A=0;
			sEnemy2BInfo.x=37;
			sEnemy2BInfo.xOld=37;
			sEnemy2BInfo.y=24;
			sEnemy2BInfo.yOld=24;
			count2B=0;
			Uncount2B=0;
			sEnemy2CInfo.x=51;
			sEnemy2CInfo.xOld=51;
			sEnemy2CInfo.y=24;
			sEnemy2CInfo.yOld=24;
			count2C=0;
			Uncount2C=0;
			break;

	case MAP_LAST_ID:
		sEnemy1AInfo.x=31;
			sEnemy1AInfo.xOld=31;
			sEnemy1AInfo.y=18;
			sEnemy1AInfo.yOld=18;
			count1A=0;
			Uncount1A=0;
			move1A=1;
			sEnemy1BInfo.x=46;
			sEnemy1BInfo.xOld=46;
			sEnemy1BInfo.y=15;
			sEnemy1BInfo.yOld=15;
			count1B=0;
			Uncount1B=0;
			move1B=1;
			sEnemy1CInfo.x=67;
			sEnemy1CInfo.xOld=67;
			sEnemy1CInfo.y=19;
			sEnemy1CInfo.yOld=19;
			count1C=0;
			Uncount1C=0;
			move1C=1;
			sEnemy2AInfo.x=7;
			sEnemy2AInfo.xOld=7;
			sEnemy2AInfo.y=24;
			sEnemy2AInfo.yOld=24;
			count2A=0;
			Uncount2A=0;
			sEnemy2BInfo.x=19;
			sEnemy2BInfo.xOld=19;
			sEnemy2BInfo.y=24;
			sEnemy2BInfo.yOld=24;
			count2B=0;
			Uncount2B=0;
			sEnemy2CInfo.x=32;
			sEnemy2CInfo.xOld=32;
			sEnemy2CInfo.y=24;
			sEnemy2CInfo.yOld=24;
			count2C=0;
			Uncount2C=0;
			sEnemy2DInfo.x=40;
			sEnemy2DInfo.xOld=40;
			sEnemy2DInfo.y=24;
			sEnemy2DInfo.yOld=24;
			count2D=0;
			Uncount2D=0;
			sEnemy2EInfo.x=45;
			sEnemy2EInfo.xOld=45;
			sEnemy2EInfo.y=24;
			sEnemy2EInfo.yOld=24;
			count2E=0;
			Uncount2E=0;
			break;
	}


}
//================================================


// プレイヤー終了処理関数(1回)=====================
void EnemyUnInit( void )
{

}
//=================================================



// キー処理関数(ゲーム)========================================================================
int Enemy1AUpdate( void )
{
	sEnemy1AInfo.xOld = sEnemy1AInfo.x;
	sEnemy1AInfo.yOld = sEnemy1AInfo.y;
	int mapinfo;
	switch(move1A)
	{
		case 1:
			count1A++;
			if(count1A==7)
			{
				sEnemy1AInfo.x-=1;
				count1A=0;
			}
			mapinfo=getMap(sEnemy1AInfo.y,sEnemy1AInfo.x);
			if( mapinfo == '1'
			||  mapinfo == '3')
			{
				sEnemy1AInfo.y = sEnemy1AInfo.yOld;
			}
			Uncount1A++;
			if(Uncount1A==110)
			{
				Uncount1A=0;
				move1A=2;
			}
			break;
		case 2:
			count1A++;
			if(count1A==7)
			{
				sEnemy1AInfo.x+=1;
				count1A=0;
			}
			mapinfo=getMap(sEnemy1AInfo.y,sEnemy1AInfo.x);
			if( mapinfo == '1'
			||  mapinfo == '3')
			{
				sEnemy1AInfo.y = sEnemy1AInfo.yOld;
			}
			Uncount1A++;
			if(Uncount1A==110)
			{
				Uncount1A=0;
				move1A=1;
			}
	}
	return(0);
}
//=============================================================================================


// キー処理関数(ゲーム)========================================================================
int Enemy1BUpdate( void )
{
	sEnemy1BInfo.xOld = sEnemy1BInfo.x;
	sEnemy1BInfo.yOld = sEnemy1BInfo.y;
	int mapinfo;
	switch(move1B)
	{
		case 1:
			count1B++;
			if(count1B==7)
			{
				sEnemy1BInfo.x-=1;
				count1B=0;
			}
			mapinfo=getMap(sEnemy1BInfo.y,sEnemy1BInfo.x);
			if( mapinfo == '1'
			||  mapinfo == '3')
			{
				sEnemy1BInfo.y = sEnemy1BInfo.yOld;
			}
			Uncount1B++;
			if(Uncount1B==110)
			{
				Uncount1B=0;
				move1B=2;
			}
			break;
		case 2:
			count1B++;
			if(count1B==7)
			{
				sEnemy1BInfo.x+=1;
				count1B=0;
			}
			mapinfo=getMap(sEnemy1BInfo.y,sEnemy1BInfo.x);
			if( mapinfo == '1'
			||  mapinfo == '3')
			{
				sEnemy1BInfo.y = sEnemy1BInfo.yOld;
			}
			Uncount1B++;
			if(Uncount1B==110)
			{
				Uncount1B=0;
				move1B=1;
			}
	}
	return(0);
}
//=============================================================================================


// キー処理関数(ゲーム)========================================================================
int Enemy1CUpdate( void )
{
	sEnemy1CInfo.xOld = sEnemy1CInfo.x;
	sEnemy1CInfo.yOld = sEnemy1CInfo.y;
	int mapinfo;
	switch(move1C)
	{
		case 1:
			count1C++;
			if(count1C==7)
			{
				sEnemy1CInfo.x-=1;
				count1C=0;
			}
			mapinfo=getMap(sEnemy1CInfo.y,sEnemy1CInfo.x);
			if( mapinfo == '1'
			||  mapinfo == '3')
			{
				sEnemy1CInfo.y = sEnemy1CInfo.yOld;
			}
			Uncount1C++;
			if(Uncount1C==110)
			{
				Uncount1C=0;
				move1C=2;
			}
			break;
		case 2:
			count1C++;
			if(count1C==7)
			{
				sEnemy1CInfo.x+=1;
				count1C=0;
			}
			mapinfo=getMap(sEnemy1CInfo.y,sEnemy1CInfo.x);
			if( mapinfo == '1'
			||  mapinfo == '3')
			{
				sEnemy1CInfo.y = sEnemy1CInfo.yOld;
			}
			Uncount1C++;
			if(Uncount1C==110)
			{
				Uncount1C=0;
				move1C=1;
			}
	}
	return(0);
}
//=============================================================================================


// キー処理関数(ゲーム)========================================================================
int Enemy1DUpdate( void )
{
	sEnemy1DInfo.xOld = sEnemy1DInfo.x;
	sEnemy1DInfo.yOld = sEnemy1DInfo.y;
	int mapinfo;
	count1D++;
	if(count1D==3)
	{
		sEnemy1DInfo.x-=1;
		sEnemy1DInfo.y+=1;
		count1D=0;
	}
	mapinfo=getMap(sEnemy1DInfo.y,sEnemy1DInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sEnemy1DInfo.y = sEnemy1DInfo.yOld;
	}
	if(sEnemy1DInfo.x<=0||sEnemy1DInfo.y>=BUFF_Y_MAX)
	{
		sEnemy1DInfo.x=70;
		sEnemy1DInfo.y=23;
		return(CLEAR_ENEMY_1D);
		
	}
	return(0);
}
//=============================================================================================


// キー処理関数(ゲーム)========================================================================
int Enemy1EUpdate( void )
{
	sEnemy1EInfo.xOld = sEnemy1EInfo.x;
	sEnemy1EInfo.yOld = sEnemy1EInfo.y;
	int mapinfo;
	count1E++;
	if(count1E==3)
	{
		sEnemy1EInfo.x-=1;
		sEnemy1EInfo.y+=1;
		count1E=0;
	}
	mapinfo=getMap(sEnemy1EInfo.y,sEnemy1EInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sEnemy1EInfo.y = sEnemy1EInfo.yOld;
	}
	if(sEnemy1EInfo.x<=0||sEnemy1EInfo.y>=BUFF_Y_MAX)
	{
		sEnemy1EInfo.x=70;
		sEnemy1EInfo.y=23;
		return(CLEAR_ENEMY_1E);
		
	}
	return(0);
}
//=============================================================================================



// キー処理関数(ゲーム)========================================================================
int Enemy1Fpdate( void )
{
	sEnemy1FInfo.xOld = sEnemy1FInfo.x;
	sEnemy1FInfo.yOld = sEnemy1FInfo.y;
	int mapinfo;
	count1F++;
	if(count1F==3)
	{
		sEnemy1FInfo.x-=1;
		sEnemy1FInfo.y+=1;
		count1F=0;
	}
	mapinfo=getMap(sEnemy1FInfo.y,sEnemy1FInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sEnemy1FInfo.y = sEnemy1FInfo.yOld;
	}
	if(sEnemy1FInfo.x<=0||sEnemy1FInfo.y>=BUFF_Y_MAX)
	{
		sEnemy1FInfo.x=70;
		sEnemy1FInfo.y=23;
		return(CLEAR_ENEMY_1F);
		
	}
	return(0);
}
//=============================================================================================



// キー処理関数(ゲーム)========================================================================
int Enemy2AUpdate( void )
{
	sEnemy2AInfo.xOld = sEnemy2AInfo.x;
	sEnemy2AInfo.yOld = sEnemy2AInfo.y;
	int mapinfo;
	count2A++;
	if(count2A==3)
	{
		Uncount2A++;
		if(Uncount2A<=24)
		{
			sEnemy2AInfo.y-=2;
		}
		sEnemy2AInfo.y+=1;
		count2A=0;
	}
	mapinfo=getMap(sEnemy2AInfo.y,sEnemy2AInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sEnemy2AInfo.y = sEnemy2AInfo.yOld;
	}
	if(sEnemy2AInfo.x<=0||sEnemy2AInfo.y>=BUFF_Y_MAX)
	{
		sEnemy2AInfo.y=24;
		Uncount2A=0;
		count2A=0;
	}
	return(0);
}
//=============================================================================================


// キー処理関数(ゲーム)========================================================================
int Enemy2BUpdate( void )
{
	sEnemy2BInfo.xOld = sEnemy2BInfo.x;
	sEnemy2BInfo.yOld = sEnemy2BInfo.y;
	int mapinfo;
	count2B++;
	if(count2B==3)
	{
		Uncount2B++;
		if(Uncount2B<=24)
		{
			sEnemy2BInfo.y-=2;
		}
		sEnemy2BInfo.y+=1;
		count2B=0;
	}
	mapinfo=getMap(sEnemy2BInfo.y,sEnemy2BInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sEnemy2BInfo.y = sEnemy2BInfo.yOld;
	}
	if(sEnemy2BInfo.x<=0||sEnemy2BInfo.y>=BUFF_Y_MAX)
	{
		sEnemy2BInfo.y=24;
		Uncount2B=0;
		count2B=0;
		
	}
	return(0);
}
//=============================================================================================


// キー処理関数(ゲーム)========================================================================
int Enemy2CUpdate( void )
{
	sEnemy2CInfo.xOld = sEnemy2CInfo.x;
	sEnemy2CInfo.yOld = sEnemy2CInfo.y;
	int mapinfo;
	count2C++;
	if(count2C==3)
	{
		Uncount2C++;
		if(Uncount2C<=24)
		{
			sEnemy2CInfo.y-=2;
		}
		sEnemy2CInfo.y+=1;
		count2C=0;
	}
	mapinfo=getMap(sEnemy2CInfo.y,sEnemy2CInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sEnemy2CInfo.y = sEnemy2CInfo.yOld;
	}
	if(sEnemy2CInfo.x<=0||sEnemy2CInfo.y>=BUFF_Y_MAX)
	{
		sEnemy2CInfo.y=24;
		Uncount2C=0;
		count2C=0;
	}
	return(0);
}
//=============================================================================================


// キー処理関数(ゲーム)========================================================================
int Enemy2DUpdate( void )
{
	sEnemy2DInfo.xOld = sEnemy2DInfo.x;
	sEnemy2DInfo.yOld = sEnemy2DInfo.y;
	int mapinfo;
	count2D++;
	if(count2D==3)
	{
		Uncount2D++;
		if(Uncount2D<=24)
		{
			sEnemy2DInfo.y-=2;
		}
		sEnemy2DInfo.y+=1;
		count2D=0;
	}
	mapinfo=getMap(sEnemy2DInfo.y,sEnemy2DInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sEnemy2DInfo.y = sEnemy2DInfo.yOld;
	}
	if(sEnemy2DInfo.x<=0||sEnemy2DInfo.y>=BUFF_Y_MAX)
	{
		
		Uncount2D=0;
		count2D=0;
		sEnemy2DInfo.y=24;
		
	}
	return(0);
}
//=============================================================================================


// キー処理関数(ゲーム)========================================================================
int Enemy2EUpdate( void )
{
	sEnemy2EInfo.xOld = sEnemy2EInfo.x;
	sEnemy2EInfo.yOld = sEnemy2EInfo.y;
	int mapinfo;
	count2E++;
	if(count2E==3)
	{
		Uncount2E++;
		if(Uncount2E<=24)
		{
			sEnemy2EInfo.y-=2;
		}
		sEnemy2EInfo.y+=1;
		count2E=0;
	}
	mapinfo=getMap(sEnemy2EInfo.y,sEnemy2EInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sEnemy2EInfo.y = sEnemy2EInfo.yOld;
	}
	if(sEnemy2EInfo.x<=0||sEnemy2EInfo.y>=BUFF_Y_MAX)
	{
		
		Uncount2E=0;
		count2E=0;
		sEnemy2EInfo.y=24;
		
	}
	return(0);
}
//=============================================================================================


// キー処理関数(ゲーム)========================================================================
int Enemy2FUpdate( void )
{
	sEnemy2FInfo.xOld = sEnemy2FInfo.x;
	sEnemy2FInfo.yOld = sEnemy2FInfo.y;
	int mapinfo;
	count2F++;
	if(count2F==3)
	{
		Uncount2F++;
		if(Uncount2F<=24)
		{
			sEnemy2FInfo.y-=2;
		}
		sEnemy2FInfo.y+=1;
		count2F=0;
	}
	mapinfo=getMap(sEnemy2FInfo.y,sEnemy2FInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sEnemy2FInfo.y = sEnemy2FInfo.yOld;
	}
	if(sEnemy2FInfo.x<=0||sEnemy2FInfo.y>=BUFF_Y_MAX)
	{
		
		Uncount2F=0;
		count2F=0;
		sEnemy2FInfo.y=24;
		
	}
	return(0);
}
//=============================================================================================

// プレーヤー情報取得関数===================
int GetEnemy1AInfoX( void )
{
	return( sEnemy1AInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1AInfoXOLD( void )
{
	return( sEnemy1AInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1AInfoY( void )
{
	return( sEnemy1AInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1AInfoYOLD( void )
{
	return( sEnemy1AInfo.yOld);
}
//==========================================


// プレーヤー情報取得関数===================
int GetEnemy1BInfoX( void )
{
	return( sEnemy1BInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1BInfoXOLD( void )
{
	return( sEnemy1BInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1BInfoY( void )
{
	return( sEnemy1BInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1BInfoYOLD( void )
{
	return( sEnemy1BInfo.yOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1CInfoX( void )
{
	return( sEnemy1CInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1CInfoXOLD( void )
{
	return( sEnemy1CInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1CInfoY( void )
{
	return( sEnemy1CInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1CInfoYOLD( void )
{
	return( sEnemy1CInfo.yOld);
}
//==========================================


// プレーヤー情報取得関数===================
int GetEnemy1DInfoX( void )
{
	return( sEnemy1DInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1DInfoXOLD( void )
{
	return( sEnemy1DInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1DInfoY( void )
{
	return( sEnemy1DInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1DInfoYOLD( void )
{
	return( sEnemy1DInfo.yOld);
}
//==========================================


// プレーヤー情報取得関数===================
int GetEnemy1EInfoX( void )
{
	return( sEnemy1EInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1EInfoXOLD( void )
{
	return( sEnemy1EInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1EInfoY( void )
{
	return( sEnemy1EInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1EInfoYOLD( void )
{
	return( sEnemy1EInfo.yOld);
}
//==========================================


// プレーヤー情報取得関数===================
int GetEnemy1FInfoX( void )
{
	return( sEnemy1FInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1FInfoXOLD( void )
{
	return( sEnemy1FInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1FInfoY( void )
{
	return( sEnemy1FInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy1FInfoYOLD( void )
{
	return( sEnemy1FInfo.yOld);
}
//==========================================


// プレーヤー情報取得関数===================
int GetEnemy2AInfoX( void )
{
	return( sEnemy2AInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2AInfoXOLD( void )
{
	return( sEnemy2AInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2AInfoY( void )
{
	return( sEnemy2AInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2AInfoYOLD( void )
{
	return( sEnemy2AInfo.yOld);
}
//==========================================


// プレーヤー情報取得関数===================
int GetEnemy2BInfoX( void )
{
	return( sEnemy2BInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2BInfoXOLD( void )
{
	return( sEnemy2BInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2BInfoY( void )
{
	return( sEnemy2BInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2BInfoYOLD( void )
{
	return( sEnemy2BInfo.yOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2CInfoX( void )
{
	return( sEnemy2CInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2CInfoXOLD( void )
{
	return( sEnemy2CInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2CInfoY( void )
{
	return( sEnemy2CInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2CInfoYOLD( void )
{
	return( sEnemy2CInfo.yOld);
}
//==========================================


// プレーヤー情報取得関数===================
int GetEnemy2DInfoX( void )
{
	return( sEnemy2DInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2DInfoXOLD( void )
{
	return( sEnemy2DInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2DInfoY( void )
{
	return( sEnemy2DInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2DInfoYOLD( void )
{
	return( sEnemy2DInfo.yOld);
}
//==========================================


// プレーヤー情報取得関数===================
int GetEnemy2EInfoX( void )
{
	return( sEnemy2EInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2EInfoXOLD( void )
{
	return( sEnemy2EInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2EInfoY( void )
{
	return( sEnemy2EInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2EInfoYOLD( void )
{
	return( sEnemy2EInfo.yOld);
}
//==========================================


// プレーヤー情報取得関数===================
int GetEnemy2FInfoX( void )
{
	return( sEnemy2FInfo.x);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2FInfoXOLD( void )
{
	return( sEnemy2FInfo.xOld);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2FInfoY( void )
{
	return( sEnemy2FInfo.y);
}
//==========================================

// プレーヤー情報取得関数===================
int GetEnemy2FInfoYOLD( void )
{
	return( sEnemy2FInfo.yOld);
}
//==========================================
