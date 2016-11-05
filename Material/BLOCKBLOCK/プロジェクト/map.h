#ifndef __MAP_H__
#define __MAP_H__


// �C���N���[�h==================

//===============================



// ��`============================================================
#define TITLE_FAST_ID (1)//�^�C�g����ʗp
#define TITLE_NEXT_ID (2)//�^�C�g����ʗp
#define TITLE_LAST_ID (3)//�^�C�g����ʗp
#define MAP_FAST_ID (10)//���͉�ʗp
#define MAP_NEXT_ID (11)//���͉�ʗp
#define MAP_LAST_ID (12)//���͉�ʗp
#define PLAYER_ID (20)//�����̃^�[���p
#define ENEMY_ID (30)//����̃^�[���p
#define FIGHT_ID (40)//�퓬�p
#define RESULT_FAST_ID (50)//���ʗp
#define RESULT_NEXT_ID (51)//���ʗp
#define RESULT_LAST_ID (52)//���ʗp
//==================================================================


// �\����===============================
//=======================================


// �v���g�^�C�v�錾==============
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