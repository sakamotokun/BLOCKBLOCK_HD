#ifndef __INP_H__
#define __INP_H__


// �C���N���[�h==================

//===============================



// ��`============================================================
#define JUMP_HIGH 10		//�W�����v�̍���
//==================================================================


// �\����===============================
typedef struct _POS
{
    int     x;
    int     y;

    int     xOld;
    int     yOld;
} POS;
//=======================================


// �v���g�^�C�v�錾==============
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