#ifndef __ENEMY_H__
#define __ENEMY_H__


// インクルード==================

//===============================



// 定義============================================================
#define ENEMY_1A (90)
#define ENEMY_1B (91)
#define ENEMY_1C (92)
#define ENEMY_1D (93)
#define ENEMY_1E (94)
#define ENEMY_1F (95)
#define ENEMY_2A (96)
#define ENEMY_2B (97)
#define ENEMY_2C (98)
#define ENEMY_2D (99)
#define ENEMY_2E (100)
#define ENEMY_2F (101)
#define CLEAR_ENEMY_1A (102)
#define CLEAR_ENEMY_1B (103)
#define CLEAR_ENEMY_1C (104)
#define CLEAR_ENEMY_1D (105)
#define CLEAR_ENEMY_1E (106)
#define CLEAR_ENEMY_1F (107)
#define CLEAR_ENEMY_2A (108)
#define CLEAR_ENEMY_2B (109)
#define CLEAR_ENEMY_2C (110)
#define CLEAR_ENEMY_2D (111)
#define CLEAR_ENEMY_2E (112)
#define CLEAR_ENEMY_2F (113)
//==================================================================


// 構造体===============================

//=======================================


// プロトタイプ宣言==============
void EnemyInit( int Mode );
void EnemyUnInit( void );
int Enemy1AUpdate( void );
int Enemy1BUpdate( void );
int Enemy1CUpdate( void );
int Enemy1DUpdate( void );
int Enemy1FUpdate( void );
int Enemy2AUpdate( void );
int Enemy2BUpdate( void );
int Enemy2CUpdate( void );
int Enemy2DUpdate( void );
int Enemy2EUpdate( void );
int Enemy2FUpdate( void );
int GetEnemy1AInfoX( void );
int GetEnemy1AInfoXOLD( void );
int GetEnemy1AInfoY( void );
int GetEnemy1AInfoYOLD( void );
int GetEnemy1BInfoX( void );
int GetEnemy1BInfoXOLD( void );
int GetEnemy1BInfoY( void );
int GetEnemy1BInfoYOLD( void );
int GetEnemy1CInfoX( void );
int GetEnemy1CInfoXOLD( void );
int GetEnemy1CInfoY( void );
int GetEnemy1CInfoYOLD( void );
int GetEnemy1DInfoX( void );
int GetEnemy1DInfoXOLD( void );
int GetEnemy1DInfoY( void );
int GetEnemy1DInfoYOLD( void );
int GetEnemy1EInfoX( void );
int GetEnemy1EInfoXOLD( void );
int GetEnemy1EInfoY( void );
int GetEnemy1EInfoYOLD( void );
int GetEnemy1FInfoX( void );
int GetEnemy1FInfoXOLD( void );
int GetEnemy1FInfoY( void );
int GetEnemy1FInfoYOLD( void );
int GetEnemy2AInfoX( void );
int GetEnemy2AInfoXOLD( void );
int GetEnemy2AInfoY( void );
int GetEnemy2AInfoYOLD( void );
int GetEnemy2BInfoX( void );
int GetEnemy2BInfoXOLD( void );
int GetEnemy2BInfoY( void );
int GetEnemy2BInfoYOLD( void );
int GetEnemy2CInfoX( void );
int GetEnemy2CInfoXOLD( void );
int GetEnemy2CInfoY( void );
int GetEnemy2CInfoYOLD( void );
int GetEnemy2DInfoX( void );
int GetEnemy2DInfoXOLD( void );
int GetEnemy2DInfoY( void );
int GetEnemy2DInfoYOLD( void );
int GetEnemy2EInfoX( void );
int GetEnemy2EInfoXOLD( void );
int GetEnemy2EInfoY( void );
int GetEnemy2EInfoYOLD( void );
int GetEnemy2FInfoX( void );
int GetEnemy2FInfoXOLD( void );
int GetEnemy2FInfoY( void );
int GetEnemy2FInfoYOLD( void );
//===============================


#endif