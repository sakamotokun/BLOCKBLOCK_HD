
// warning �΍�
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

    // �J�[�\�� OFF
    CUROFF();
	SetAppMode( APPMODE_TITLE );
	//framerate�@�Œ�
	int time,timeold;
	timeBeginPeriod( 1 );         //�^�C�}���x���ō��ɂ���
	time=timeold=timeGetTime();
    // ���C�����[�v
    while( 1 )
    {
		//���݂̎��Ԏ擾
		time=timeGetTime();
		if(time-timeold>=(1000/40))
		{
			//frame�@�O�̎��Ԏ擾
			timeold=time;
			//�X�V����
			AppUpdate();
			//�`�揈��
			AppDraw();

		}

    }

	timeEndPeriod(1);

    // ��ʂ������Ă��܂��̂ŁA���͑҂�������
    rewind( stdin );
    getchar();
}
