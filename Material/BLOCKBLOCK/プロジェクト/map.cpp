// �C���N���[�h==================
#include"main.h"
#include"map.h"
#include"buffer.h"
#include"game.h"
//===============================


// �ϐ�======================================
static char map[BUFF_Y_MAX][MAP_MAX+1];
static char title[BUFF_Y_MAX][MAP_MAX+1];
static char result[BUFF_Y_MAX][MAP_MAX+1];
static char player[KYARA_Y_MAX][KYARA_X_MAX+1];
static char enemy[BUFF_Y_MAX][MAP_MAX+1];
//===========================================


// MAP�Ăяo���֐�=====================
char getMap( int x, int y )
{
	return( map[x][y] );
}


//=====================================


// MAP�������݊֐�=====================
void setMap( int x, int y, int i )
{
	map[y][x] = i;
}

//=====================================


// TITLE�Ăяo���֐�=====================
char getTitle( int x, int y )
{
	return( title[x][y] );
}


//=====================================


// TITLE�������݊֐�=====================
void setTitle( int x, int y, int i )
{
	title[y][x] = i;
}

//=====================================


// PLAYER�Ăяo���֐�=====================
char getplayer( int x, int y )
{
	return( player[x][y] );
}


//========================================


// PLAYER�������݊֐�=====================
void setplayer( int x, int y, int i )
{
	player[y][x] = i;
}

//========================================


// ���U���g�Ăяo���֐�=====================
char getResult( int x, int y )
{
	return( result[x][y] );
}


//========================================


// ���U���g�������݊֐�=====================
void setResult( int x, int y, int i )
{
	result[y][x] = i;
}

//========================================


// �e�L�X�g���[�h�֐�========================
void Mapload( int mode )
{
	//open map.txt file

	int i,j;
	FILE *fmap;
	switch( mode )
	{
	case MAP_FAST_ID:
		fmap=fopen("map1.txt","r");
		if(NULL==fmap)
		{
			printf("no such data\n");
			return;
		}

		//map�s����ǂݍ���
		for (i=0;i<BUFF_Y_MAX;++i)
		{
			for (j=0;j<MAP_MAX+1;++j)
			{
				fscanf(fmap,"%c",&map[i][j]);
				if(j==MAP_MAX)
				{
					map[i][j] = map[i][j-1];
				}
			}
		}
		break;

	case MAP_NEXT_ID:
		fmap=fopen("map2.txt","r");
		if(NULL==fmap)
		{
			printf("no such data\n");
			return;
		}

		//map�s����ǂݍ���
		for (i=0;i<BUFF_Y_MAX;++i)
		{
			for (j=0;j<MAP_MAX+1;++j)
			{
				fscanf(fmap,"%c",&map[i][j]);
				if(j==MAP_MAX)
				{
					map[i][j] = map[i][j-1];
				}
			}
		}
		break;

	case MAP_LAST_ID:
		fmap=fopen("map3.txt","r");
		if(NULL==fmap)
		{
			printf("no such data\n");
			return;
		}

		//map�s����ǂݍ���
		for (i=0;i<BUFF_Y_MAX;++i)
		{
			for (j=0;j<MAP_MAX+1;++j)
			{
				fscanf(fmap,"%c",&map[i][j]);
				if(j==MAP_MAX)
				{
					map[i][j] = map[i][j-1];
				}
			}
		}
		break;

	case TITLE_FAST_ID:
		fmap=fopen("title1.txt","r");
		if(NULL==fmap)
		{
			printf("no such data\n");
			return;
		}

		//map�s����ǂݍ���
		for (i=0;i<BUFF_Y_MAX;++i)
		{
			for (j=0;j<MAP_MAX+1;++j)
			{
				fscanf(fmap,"%c",&title[i][j]);
				if(j==MAP_MAX)
				{
					title[i][j] = title[i][j-1];
				}
			}
		}
		break;

	case TITLE_NEXT_ID:
		fmap=fopen("title2.txt","r");
		if(NULL==fmap)
		{
			printf("no such data\n");
			return;
		}

		//map�s����ǂݍ���
		for (i=0;i<BUFF_Y_MAX;++i)
		{
			for (j=0;j<MAP_MAX+1;++j)
			{
				fscanf(fmap,"%c",&title[i][j]);
				if(j==MAP_MAX)
				{
					title[i][j] = title[i][j-1];
				}
			}
		}
		break;

	case TITLE_LAST_ID:
		fmap=fopen("title3.txt","r");
		if(NULL==fmap)
		{
			printf("no such data\n");
			return;
		}

		//map�s����ǂݍ���
		for (i=0;i<BUFF_Y_MAX;++i)
		{
			for (j=0;j<MAP_MAX+1;++j)
			{
				fscanf(fmap,"%c",&title[i][j]);
				if(j==MAP_MAX)
				{
					title[i][j] = title[i][j-1];
				}
			}
		}
		break;


	case RESULT_FAST_ID:
		fmap=fopen("result1.txt","r");
		if(NULL==fmap)
		{
			printf("no such data\n");
			return;
		}

		//map�s����ǂݍ���
		for (i=0;i<BUFF_Y_MAX;++i)
		{
			for (j=0;j<MAP_MAX+1;++j)
			{
				fscanf(fmap,"%c",&result[i][j]);
				if(j==MAP_MAX)
				{
					result[i][j] = result[i][j-1];
				}
			}
		}
		break;

	case RESULT_NEXT_ID:
		fmap=fopen("result2.txt","r");
		if(NULL==fmap)
		{
			printf("no such data\n");
			return;
		}

		//map�s����ǂݍ���
		for (i=0;i<BUFF_Y_MAX;++i)
		{
			for (j=0;j<MAP_MAX+1;++j)
			{
				fscanf(fmap,"%c",&result[i][j]);
				if(j==MAP_MAX)
				{
					result[i][j] = result[i][j-1];
				}
			}
		}
		break;

	case RESULT_LAST_ID:
		fmap=fopen("result3.txt","r");
		if(NULL==fmap)
		{
			printf("no such data\n");
			return;
		}

		//map�s����ǂݍ���
		for (i=0;i<BUFF_Y_MAX;++i)
		{
			for (j=0;j<MAP_MAX+1;++j)
			{
				fscanf(fmap,"%c",&result[i][j]);
				if(j==MAP_MAX)
				{
					result[i][j] = result[i][j-1];
				}
			}
		}
		break;
	}
	//close map.txt file
	fclose (fmap);
}
//===========================================