//  �{���]�pII�A�ĤT���W���Ҹ� �A�� 2 �D (2 ��)
//   
// CMouse ���O�]�t
//		�p�� int ���O�������ܼ� x �B y �P�C�� color
//		���������禡 
//         �غc���G�w�]�ȳ]�w  x �P y �� 0, 0�Acolor �� COLOR_YELLOW
//         draw�禡�G�I�s�������禡�e�X�ۤv
//                   �� g_bChange �� false �ɡA�I�s A �Ϭq���{���X
//                   �� g_bChange �� true �ɡA�I�s B �Ϭq���{���X
//                   A / B �Ϭq���{���X�A�Ѧ��D�ت�����
// 
// �ŧi�@�� bool ���O�������ܼ� g_bChange�A��l�Ȭ� false
//    �D�{�����{���X���A��ϥΪ̫��U c �ɡA
//	  �� g_bChange ���e�i�� true �P false ������
//
// �����H�U���{���X�A��X�����G�Ѧҹ� p2-1.jpg �P p2-2.jpg
//    �������� p2-1.jpg�A���U c ��ᬰ p2-2.jpg�A�A���@�� c ��ᬰ p2-1.jpg

#define P
#ifdef P2

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip> 
#include <windows.h>
#include "functions.h"

using namespace std;

bool g_bChange = false;					// �ŧi g_bChange

// CMouse  ���O
class CMouse {
private:
	int _ix, _iy, _icolor;
public:
	CMouse(int x = 0, int y = 0, int color = COLOR_YELLOW) {
		_ix = x; _iy = y; _icolor = color;
	}
	void draw() {
		if (g_bChange) {
			drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // ���զ�
			drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // �k�զ�	
			drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
		}
		else drawBoxMan(_ix, _iy, _icolor, COLOR_RED);
	}
};
			// A �Ϭq g_bChange �� �u�� �I�s�����e
			//drawSizeBox(x - 24, y + 60, COLOR_LIGHTBLUE, 22); // ���զ�
			//drawSizeBox(x + 24, y + 60, COLOR_LIGHTBLUE, 22); // �k�զ�	
			//drawBoxMan(x, y, color, COLOR_RED, COLOR_LIGHTMAGENTA);
			
			// B �Ϭq g_bChange �� �� �� �I�s�����e
			//drawBoxMan(x, y, color, COLOR_RED);

int main(void)
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P2");
	int i = 0;
	char ch;
	CMouse mx;			// �ŧi CMouse ����

	while (i < 2)  // ���T���{���N�|���}�j��
	{
		cleardevice();
		mx.draw();		// �e�X�ѹ�
		swapbuffers();
		ch = getch();
		if (ch == 'c' || ch == 'C') g_bChange = !g_bChange;				// �P�_�O�_���U c ��
		rewind(stdin);
		i++;
	}
	mx.draw();	// �e�X�ѹ�
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
	system("pause"); return(0);
}

#endif