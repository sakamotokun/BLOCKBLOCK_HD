#include"inp.h"
#include"main.h"
#include"map.h"
#include"buffer.h"
#include"game.h"
#include"app.h"
#include"enemy.h"
#include "music.h"

// �ϐ�===========================
static POS sPlayerInfo; //�v���[���[���
static POS sTitlePlayerInfo; //�v���[���[���
static int count=0;
static int nWaveHandle;
//================================

// �v���[���[���擾�֐�===================
int GetPlayerInfoX( void )
{
	return( sPlayerInfo.x);
}
//==========================================


// �v���[���[���擾�֐�===================
int GetPlayerInfoXOLD( void )
{
	return( sPlayerInfo.xOld);
}
//==========================================


// �v���[���[���擾�֐�===================
int GetPlayerInfoY( void )
{
	return( sPlayerInfo.y);
}
//==========================================


// �v���[���[���擾�֐�===================
int GetPlayerInfoYOLD( void )
{
	return( sPlayerInfo.yOld);
}
//==========================================


// �v���C���[�������֐�=====================
void PlayerInit( void )
{
	sPlayerInfo.x    = 2;
	sPlayerInfo.y    = 2; 
	sPlayerInfo.xOld = 2;
	sPlayerInfo.yOld = 2;
}
//===========================================


// �L�[�����֐�(�Q�[��)========================================================================
int getPlayerKeyFast( int *mode , int *y_cnt , int *yb , bool *j_flg )
{
	MusicJumpUpdate();
	char mapinfo;
	// ���݈ʒu�ۑ�
	sPlayerInfo.xOld = sPlayerInfo.x;
	sPlayerInfo.yOld = sPlayerInfo.y;

	if( INP( PK_LEFT ) != 0 )
	{
		sPlayerInfo.x -- ;
	}
	if( INP( PK_RIGHT ) != 0 )
	{
		sPlayerInfo.x ++;
	}
	mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sPlayerInfo.x = sPlayerInfo.xOld;
	}

	/* ��������̂ŃW�����v������2���1��ɂ��� */
	if(j_flg)
	{
		switch( *mode )
		{
			/* ���� */
			case 0:
				sPlayerInfo.y += *yb;
				mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);
				if( mapinfo == '1'
				||  mapinfo == '3'
				//||sPlayerInfo.y>=BUFF_Y_MAX
				||sPlayerInfo.y<=-1)
				{
					sPlayerInfo.y=sPlayerInfo.yOld;
					if( INP( PK_A ) != 0)
					{
						*mode = 1;
					}
				}
				break;
			/* �㏸�l�Z�b�g */
			case 1:
				*y_cnt = JUMP_HIGH;
				*mode = 2;
				break;
			/* �㏸ */
			case 2:
				sPlayerInfo.y -= *yb;
				mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);
				if( mapinfo == '1'
				||  mapinfo == '3'
				//||sPlayerInfo.y>=BUFF_Y_MAX
				||sPlayerInfo.y<=-1)
				{
					sPlayerInfo.y=sPlayerInfo.yOld;
					*mode = 0;
				}
				*y_cnt -= 1;
				if( *y_cnt < 0 )
				{
					*mode = 0;
				}
				break;
		}
		*j_flg = false;
	}

	else
	{
		*j_flg = true;
	}

	mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);
	int enemyinfo1AX=GetEnemy1AInfoX( );
	int enemyinfo1AY=GetEnemy1AInfoY( );
	int enemyinfo1BX=GetEnemy1BInfoX( );
	int enemyinfo1BY=GetEnemy1BInfoY( );
	int enemyinfo1CX=GetEnemy1CInfoX( );
	int enemyinfo1CY=GetEnemy1CInfoY( );
	int enemyinfo2AX=GetEnemy2AInfoX( );
	int enemyinfo2AY=GetEnemy2AInfoY( );
	int enemyinfo2BX=GetEnemy2BInfoX( );
	int enemyinfo2BY=GetEnemy2BInfoY( );
	int enemyinfo2CX=GetEnemy2CInfoX( );
	int enemyinfo2CY=GetEnemy2CInfoY( );
	int enemyinfo2DX=GetEnemy2DInfoX( );
	int enemyinfo2DY=GetEnemy2DInfoY( );

	if(sPlayerInfo.y>=BUFF_Y_MAX)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo1AX
		&&sPlayerInfo.y==enemyinfo1AY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo1BX
		&&sPlayerInfo.y==enemyinfo1BY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo1CX
		&&sPlayerInfo.y==enemyinfo1CY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2AX
		&&sPlayerInfo.y==enemyinfo2AY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2BX
		&&sPlayerInfo.y==enemyinfo2BY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2CX
		&&sPlayerInfo.y==enemyinfo2CY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2DX
		&&sPlayerInfo.y==enemyinfo2DY)
	{
	return( RESULT_FAST_ID);
	}
	if( mapinfo == '1'
	||  mapinfo == '3'
	||sPlayerInfo.x>=BUFF_X_MAX-1
	||sPlayerInfo.x<=0)
	{
	if(sPlayerInfo.x>=BUFF_X_MAX-1)
		{
		sPlayerInfo.x=sPlayerInfo.x-78;
			return( MAP_NEXT_ID );
		}
		sPlayerInfo.x = sPlayerInfo.xOld;

	}
	MusicUnInitEfect();
	return( MAP_FAST_ID );
}
//=============================================================================================


// �L�[�����֐�(�Q�[��)========================================================================
int getPlayerKeyNext( int *mode , int *y_cnt , int *yb , bool *j_flg )
{
	MusicJumpUpdate();
	
	char mapinfo;

    // ���݈ʒu�ۑ�
    sPlayerInfo.xOld = sPlayerInfo.x;
    sPlayerInfo.yOld = sPlayerInfo.y;

	if( INP( PK_LEFT ) != 0 )
	{
		sPlayerInfo.x -- ;
	}
	if( INP( PK_RIGHT ) != 0 )
	{
		sPlayerInfo.x ++;
	}
	mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sPlayerInfo.x = sPlayerInfo.xOld;
	}

	/* ��������̂ŃW�����v������2���1��ɂ��� */
	if(j_flg)
	{
		switch( *mode )
		{
			/* ���� */
			case 0:
				sPlayerInfo.y += *yb;
				mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);
				if( mapinfo == '1'
				||  mapinfo == '3'
				//||sPlayerInfo.y>=BUFF_Y_MAX
				||sPlayerInfo.y<=-1)
				{
					sPlayerInfo.y=sPlayerInfo.yOld;
					if( INP( PK_A ) != 0)
					{
						*mode = 1;
					}
				}
				break;
			/* �㏸�l�Z�b�g */
			case 1:
				*y_cnt = JUMP_HIGH;
				*mode = 2;
				break;
			/* �㏸ */
			case 2:
				sPlayerInfo.y -= *yb;
				mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);

				if(sPlayerInfo.y>=BUFF_Y_MAX)
				{
					return( RESULT_FAST_ID);
				}

				if( mapinfo == '1'
				||  mapinfo == '3'
				//||sPlayerInfo.y>=BUFF_Y_MAX
				||sPlayerInfo.y<=-1)
				{
					sPlayerInfo.y=sPlayerInfo.yOld;
					*mode = 0;
				}
				*y_cnt -= 1;
				if( *y_cnt < 0 )
				{
					*mode = 0;
				}
				break;
		}
		*j_flg = false;
	}else
	{
		*j_flg = true;
	}
	mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);
	int enemyinfo1AX=GetEnemy1AInfoX( );
	int enemyinfo1AY=GetEnemy1AInfoY( );
	int enemyinfo1BX=GetEnemy1BInfoX( );
	int enemyinfo1BY=GetEnemy1BInfoY( );
	int enemyinfo2AX=GetEnemy2AInfoX( );
	int enemyinfo2AY=GetEnemy2AInfoY( );
	int enemyinfo2BX=GetEnemy2BInfoX( );
	int enemyinfo2BY=GetEnemy2BInfoY( );
	int enemyinfo2CX=GetEnemy2CInfoX( );
	int enemyinfo2CY=GetEnemy2CInfoY( );

	if(sPlayerInfo.y>=BUFF_Y_MAX)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo1AX
		&&sPlayerInfo.y==enemyinfo1AY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo1BX
		&&sPlayerInfo.y==enemyinfo1BY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2AX
		&&sPlayerInfo.y==enemyinfo2AY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2BX
		&&sPlayerInfo.y==enemyinfo2BY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2CX
		&&sPlayerInfo.y==enemyinfo2CY)
	{
	return( RESULT_FAST_ID);
	}

	if( mapinfo == '1'
	||  mapinfo == '3'
	||sPlayerInfo.x>=BUFF_X_MAX-1
	||sPlayerInfo.x<=0)
	{
		if(sPlayerInfo.x>=BUFF_X_MAX-1)
		{
			sPlayerInfo.x=sPlayerInfo.x-78;
			return( MAP_LAST_ID );
		}
		sPlayerInfo.x = sPlayerInfo.xOld;
	}
	MusicUnInitEfect();
	return( MAP_NEXT_ID );
}
//=============================================================================================


// �L�[�����֐�(�Q�[��)========================================================================
int getPlayerKeyLast( int *mode , int *y_cnt , int *yb , bool *j_flg )
{
	MusicJumpUpdate();
	
	char mapinfo;

    // ���݈ʒu�ۑ�
    sPlayerInfo.xOld = sPlayerInfo.x;
    sPlayerInfo.yOld = sPlayerInfo.y;

	if( INP( PK_LEFT ) != 0 )
	{
		sPlayerInfo.x -- ;
	}
	if( INP( PK_RIGHT ) != 0 )
	{
		sPlayerInfo.x ++;
	}
	mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);
	if( mapinfo == '1'
	||  mapinfo == '3')
	{
		sPlayerInfo.x = sPlayerInfo.xOld;
	}
	

	/* ��������̂ŃW�����v������2���1��ɂ��� */
	if(j_flg)
	{
		switch( *mode )
		{
			/* ���� */
			case 0:
				sPlayerInfo.y += *yb;
				mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);
				if( mapinfo == '1'
				||  mapinfo == '3'
				//||sPlayerInfo.y>=BUFF_Y_MAX
				||sPlayerInfo.y<=-1)
				{
					sPlayerInfo.y=sPlayerInfo.yOld;
					if( INP( PK_A ) != 0)
					{
						*mode = 1;
					}
				}
				break;
			/* �㏸�l�Z�b�g */
			case 1:
				*y_cnt = JUMP_HIGH;
				*mode = 2;
				break;
			/* �㏸ */
			case 2:
				sPlayerInfo.y -= *yb;
				mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);
				if( mapinfo == '1'
				||  mapinfo == '3'
				||sPlayerInfo.y>=BUFF_Y_MAX
				||sPlayerInfo.y<=-1)
				{
					sPlayerInfo.y=sPlayerInfo.yOld;
					*mode = 0;
				}
				*y_cnt -= 1;
				if( *y_cnt < 0 )
				{
					*mode = 0;
				}
				break;
		}
		*j_flg = false;
	}else
	{
		*j_flg = true;
	}
	mapinfo=getMap(sPlayerInfo.y,sPlayerInfo.x);
	int enemyinfo2AX=GetEnemy2AInfoX( );
	int enemyinfo2AY=GetEnemy2AInfoY( );
	int enemyinfo2BX=GetEnemy2BInfoX( );
	int enemyinfo2BY=GetEnemy2BInfoY( );
	int enemyinfo2CX=GetEnemy2CInfoX( );
	int enemyinfo2CY=GetEnemy2CInfoY( );
	int enemyinfo2DX=GetEnemy2DInfoX( );
	int enemyinfo2DY=GetEnemy2DInfoY( );
	int enemyinfo2EX=GetEnemy2EInfoX( );
	int enemyinfo2EY=GetEnemy2EInfoY( );
	int enemyinfo2FX=GetEnemy2FInfoX( );
	int enemyinfo2FY=GetEnemy2FInfoY( );

	if(sPlayerInfo.y>=BUFF_Y_MAX)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2AX
		&&sPlayerInfo.y==enemyinfo2AY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2BX
		&&sPlayerInfo.y==enemyinfo2BY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2CX
		&&sPlayerInfo.y==enemyinfo2CY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2DX
		&&sPlayerInfo.y==enemyinfo2DY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2EX
		&&sPlayerInfo.y==enemyinfo2EY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x==enemyinfo2FX
		&&sPlayerInfo.y==enemyinfo2FY)
	{
	return( RESULT_FAST_ID);
	}
	if(sPlayerInfo.x>=BUFF_X_MAX-1)
	{
		return( RESULT_NEXT_ID);
	}

	if( mapinfo == '1'
	||  mapinfo == '3'
	//||sPlayerInfo.x>=BUFF_X_MAX-1
	||sPlayerInfo.x<=0)
	{
		sPlayerInfo.x = sPlayerInfo.xOld;
	}
	MusicUnInitEfect();
	return( MAP_LAST_ID );
}
//=============================================================================================

// �L�[�����֐�(�^�C�g��)====================
int getTitleKey( void )
{
	if( INP( PK_ENTER ) != 0 )
	{
		return( APPMODE_GAME );
	}
	return( APPMODE_TITLE );
}
//===========================================

// �L�[�����֐�(�^�C�g��)====================
int getResult1Key( void )
{
	if( INP( PK_ENTER ) != 0 )
	{
		
		return( APPMODE_TITLE );
	}
	return( APPMODE_RESULT1 );
}
//===========================================


// �L�[�����֐�(�^�C�g��)====================
int getResult2Key( void )
{
	if( INP( PK_ENTER ) != 0 )
	{
		return( APPMODE_TITLE );
	}
	return( APPMODE_RESULT2 );
}
//===========================================
