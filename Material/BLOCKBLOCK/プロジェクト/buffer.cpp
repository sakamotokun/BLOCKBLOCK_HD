// �C���N���[�h=============
#include"main.h"
#include"buffer.h"
#include"game.h"
#include "map.h"

// =========================


// �ϐ��錾=================
   static char    bufferDraw[ BUFF_Y_MAX ][ BUFF_X_MAX ];   // �`��p
   static char    bufferDisp[ BUFF_Y_MAX ][ BUFF_X_MAX ];   // �\���p
   static int count=0;
//==========================


// �o�b�t�@�Ƀf�[�^���������ފ֐�===================
void setBuffer( int x, int y, char moji )
{
	char *p = &bufferDraw[0][0];
    // �o�b�t�@�I�[�o�[��h�����߂ɕK���s��
    if( (x > -1) && (x < BUFF_X_MAX) 
     && (y > -1) && (y < BUFF_Y_MAX) )
    {
        // �A�h���X�v�Z�ł���悤�ɂȂ낤�I�I
        *( p + (y * BUFF_X_MAX) + x ) = moji;
    }
}
//===================================================

// �\������=======================================
void printBuffer( void )
{
	char *p0=&bufferDisp[0][0];
	char *p1=&bufferDraw[0][0];
    int loopX, loopY;
    char *w0, *w1;      // �A�h���X�v�Z�p�|�C���^


    // �c�̃��[�v
    for( loopY=0; loopY<BUFF_Y_MAX; loopY++)
    {
        // ���̃��[�v
        for( loopX=0; loopX<BUFF_X_MAX; loopX++)
        {
            // �o�b�t�@�̃A�h���X�v�Z
            w0 = p0 + (loopY * BUFF_X_MAX) + loopX;
            w1 = p1 + (loopY * BUFF_X_MAX) + loopX;

            // �o�b�t�@�̓��e�m�F
            if( *w0 != *w1 )
            {
                // �o�b�t�@�ɕύX���������ꍇ�`��
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

                // �o�b�t�@�̍X�V
                *w0 = *w1;
            }
        }
    }
	LOCATE(1,1);
}
// ===============================================

// ��ʃN���A=====================================
void ClearGraphicsBuffs( void )
{
	int i,j;
	//�̈�N���A
	for(i=0;i<BUFF_Y_MAX;++i)
	{
		for(j=0;j<BUFF_X_MAX;++j)
		{
			bufferDisp[i][j] = 0;
			bufferDraw[i][j] = 0;
		}
	}
	//��ʃN���A
	CLS();
}

//================================================

// �Q�[�����̃o�b�t�@������========================
void GameBuffSet( int mode )
{
	int     loopX, loopY;
	int mapinfo;
	switch ( mode )
	{
		case MAP_FAST_ID:
			// ���[�v�p
			Mapload( MAP_FAST_ID );
			// �o�b�t�@������
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// �o�b�t�@�̏�����
					mapinfo=getMap(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =mapinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;

		case MAP_NEXT_ID:
			// ���[�v�p
			Mapload( MAP_NEXT_ID );
			// �o�b�t�@������
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// �o�b�t�@�̏�����
					mapinfo=getMap(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =mapinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;


		case MAP_LAST_ID:
			// ���[�v�p
			Mapload( MAP_LAST_ID );
			// �o�b�t�@������
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// �o�b�t�@�̏�����
					mapinfo=getMap(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =mapinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;
	}
}
//=================================================


// �^�C�g�����̃o�b�t�@������========================
void TitleBuffSet( int mode )
{
	int     loopX, loopY;
	int titleinfo;

	switch ( mode )
	{

		case TITLE_FAST_ID:
			// ���[�v�p

			Mapload( TITLE_FAST_ID );
			// �o�b�t�@������
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// �o�b�t�@�̏�����
					titleinfo=getTitle(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =titleinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;

		case TITLE_NEXT_ID:
			// ���[�v�p
			Mapload( TITLE_NEXT_ID );
			// �o�b�t�@������
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// �o�b�t�@�̏�����
					titleinfo=getTitle(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =titleinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;

		case TITLE_LAST_ID:
			// ���[�v�p
			Mapload( TITLE_LAST_ID );
			// �o�b�t�@������
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// �o�b�t�@�̏�����
					titleinfo=getTitle(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =titleinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;
	}
}
//=================================================



// ���U���g���̃o�b�t�@������========================
void ResultBuffSet( int mode )
{
	int     loopX, loopY;
	int resultinfo;

	switch ( mode )
	{

		case RESULT_FAST_ID:
			// ���[�v�p

			Mapload( RESULT_FAST_ID );
			// �o�b�t�@������
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// �o�b�t�@�̏�����
					resultinfo=getResult(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =resultinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;

		case RESULT_NEXT_ID:
			// ���[�v�p
			Mapload( RESULT_NEXT_ID );
			// �o�b�t�@������
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// �o�b�t�@�̏�����
					resultinfo=getResult(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =resultinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;

		case RESULT_LAST_ID:
			// ���[�v�p
			Mapload( RESULT_LAST_ID );
			// �o�b�t�@������
			for( loopY=0; loopY<BUFF_Y_MAX; loopY++ )
			{
				for( loopX=0; loopX<MAP_MAX+1; loopX++ )
				{
					// �o�b�t�@�̏�����
					resultinfo=getResult(loopY,loopX);
					bufferDraw[ loopY ][ loopX ] =resultinfo;
					bufferDisp[ loopY ][ loopX ] = ' ';
				}
			}
		break;
	}
}
//=================================================

