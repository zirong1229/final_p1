//  �{���]�pII�A�ĤT���W���Ҹ� �A�� 3 �D (4 ��)
//   
// CMouse ���O�]�t
//		�p���]�t
//			int ���O�������ܼ� x �B y �P�C�� color
//			bool ���O���ܼ� btracer
//			CMouse �������ܼ� target
//		���������禡 
//         �غc���G�S���޼ơA�����]�w x �P y �� 0, 0�Acolor ��  COLOR_YELLOW
//                 btracer �� false (�w�]���i�Q�j�l�ܪ�)
//				   target �� nullptr
//         setTracer �禡 : �@�� bool ���O���޼ơA�]�w btracer ���ǤJ����
//		   setTarget �禡 : �@�� CMouse ���O���i�ѷӡj�޼ơA
//							�]�w target �����V�ӶǤJ�i���󪺦�}�j
//	 	   getPos �禡   : ��� int ���O�H�i�ǫ��Сj���Φ��ǤJ�C
//                         �N�ثe�ѹ�����m�Q�θӶǤJ���ܼƶǦ^���I�s��
// 
//         draw  �禡    : �ھڦۤv�����A(�l���٬O�Q�l��)�I�s�������禡�e�X�ۤv�A�����ϥΩҵ����禡���e
//		   update �禡   : �����ϥΩҵ����禡���e
// 
//   �����H�U���{���X�A�ñ���|����W�U���k���ʧY�i�A
//					   �l�ܪ̫O���b���a�����������U��Y�i
//   

#define P
#ifdef P3

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include "functions.h"

using namespace std;

// CMouse  ���O
class CMouse {
private:
	int _ix, _iy, _icolor;
	bool btracer;
	CMouse* target;
public:
	CMouse() {
		_ix = 0; _iy = 0; _icolor = COLOR_YELLOW;
		btracer = false;
		target = nullptr;
	}
	void draw() {
		if (btracer) drawBoxMan(_ix, _iy - 100, _icolor); // �l�ܪ̩I�s�o�Ө禡
		else drawColorBox(_ix, _iy, _icolor);     // �Q�l�ܪ̩I�s�o�Ө禡
	}
	void setTracer(bool bt) { btracer = bt; }
	void setTarget(CMouse& ma) { target = &ma; }
	void getPos(int& x, int& y) {
		x = _ix; y = _iy;
	}
	void update(char);
	void updatePos() {
		int itx, ity;
		target->getPos(itx,ity);
		_ix = itx; _iy = ity;
	}
};
// �p����

// ������
//void updatePos();
//update(char cIn);

//
//drawBoxMan(x, y - 100, color); // �l�ܪ̩I�s�o�Ө禡
//drawColorBox(x, y, color);     // �Q�l�ܪ̩I�s�o�Ө禡

void CMouse::update(char cIn) // update �禡�����e
{
	switch (cIn) {
	case 'w': // ���W. ���ѹ���m,�îھڷs����m,��s�ѹ������A
		_iy = _iy + 20; break;
	case 's': // ���U
		_iy = _iy - 20; break;
	case 'a': // ����
		_ix = _ix - 20; break;
	case 'd': // ���k
		_ix = _ix + 20; break;
	}
}
int main()
{
	char cIn;
	int i = 0;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P3");
	CMouse m1, m2;
	m2.setTracer(true);					// �]�w m2 ���l�ܪ�
	m2.setTarget(m1);				// �]�w m2 ���l�ܹ�H�� m1
	m2.updatePos();					// �� m2 ��s��m
	
	while ( i < 10 ) // ���� 10 ���{���N�|���}�j��
	{
		cleardevice();
		m1.draw();	// �e�X�ѹ�
		m2.draw();
		swapbuffers();
		cIn = getch();
		m1.update(cIn);					// ��s��J�� m1 ��s��m
		m2.updatePos();					// �� m2 ��s��m
		rewind(stdin);
		i++;
	}
	cleardevice();
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}

#endif