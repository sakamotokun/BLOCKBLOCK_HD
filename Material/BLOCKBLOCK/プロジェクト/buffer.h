#ifndef __BUFFER_H__
#define __BUFFER_H__


// �C���N���[�h==================

//===============================



// ��`============================================================
// �o�b�t�@�T�C�Y
#define BUFF_X_MAX   80     // �o�b�t�@����
#define BUFF_Y_MAX   25      // �o�b�t�@�c��
#define MAP_MAX      79     // MAP�̂�������

// �L�����T�C�Y
#define KYARA_X_MAX   3     // �o�b�t�@����
#define KYARA_Y_MAX   3      // �o�b�t�@�c��

// �\���ʒu �␳
#define DISP_OFF_SET_X  1
#define DISP_OFF_SET_Y  1


//==================================================================


// �\����===============================
//=======================================


// �v���g�^�C�v�錾==============
void setBuffer( int x, int y, char moji );
void printBuffer( void );
void ClearGraphicsBuffs( void );
void GameBuffSet( int mode );
void TitleBuffSet( int mode );
void ResultBuffSet( int mode );
//===============================


#endif