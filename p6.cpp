//  �{���]�pII�A�ĤT���W���Ҹ� �A�� 6 �D (6 ��)
//
//   �ŧi�H�U�T�����O
//    CCharacter ���O�]�t�p���������ܼƻP���������禡
//		���⪺�y�� x, y �P�C�� color ���O int ���O�C
//      �غc��    �G �]�t�o�T�Ӥ޼ƨӳ]�w�o�T���ܼƪ����e
//                   �޼ƪ��w�]�Ȥ��O�O 0, 0, COLOR_LIGHTGREEN
//      setPos�禡�G��� int ���O�޼ơA�]�w���⪺ x/y �y�СA�S���^�ǭ�
//      draw�禡�G�ھکҵ����禡�I�s�Aø�X�������ϧΡA�S���^�ǭ�
//       
//   CMouse ���O�A�i�����j�~�Ӧ� CCharacter ���O�A�]�t�H�U�����������禡
//      �غc�� : �������⪺�y�� x, y �P�C�� color�A
//				 �I�s CCharacter �غc���N�ҶǤJ���޼ƶǻ��������O
//      draw�禡�G�ھکҵ����禡�I�s�Aø�X�������ϧΡA�S���^�ǭ�
// 
//	 CRabbit ���O�A�i�����j�~�Ӧ� CCharacter ���O�A�]�t�H�U�����������禡
//      �غc�� : �������⪺�y�� x, y �P�C�� color�A
//				 �I�s CCharacter �غc���N�ҶǤJ���޼ƶǻ��������O
//      draw�禡�G�ھکҵ����禡�I�s�Aø�X�������ϧΡA�S���^�ǭ�
//      
// 
//  �D�{���H CCharacter �ŧi�@�Ӥ@�����а}�C�A�]�t�����x�s�Ŷ��A
//	�U�x�s�Ŷ��ҹ������V�è��o������A�аѦҥD�{�������ѻ����C
//  �����Q�Φh�����覡�����p p6.jpg ��ø�X���i���j�ӹϧΡC
//  
//  �p���n�D�G���������H�U���ݨD�~��p���C
//      1. �T�����O���غc���������g�X�ӡA
//		2. CRabbit �P CMouse ���غc�������I�s CCharacter ���غc���A�_�h�ҵe�X���ϧαN���|���T
//      3. �D�{���������������귽����
//      4. ���浲�G�����P P6.jpg �ۦP�~��p��
// 

#define P
#ifdef P6

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include "functions.h"

using namespace std;

// CCharacter ���O
class CCharacter {
protected:
	int x, y, color;
public:
	CCharacter(int ix = 0, int iy = 0, int icolor = COLOR_LIGHTGREEN) {
		x = ix; y = iy; color = icolor;
	}
	CCharacter(const CCharacter& ma) {
		x = ma.x; y = ma.y;
		color = ma.color;
	}
	void setPos(int ix, int iy) { x = ix; y = iy; }
	virtual void draw() { drawBoxMan(x, y, color); }
};
// CMouse ���O
class CMouse :public CCharacter {
public:
	CMouse(int ix = 0, int iy = 0, int icolor = COLOR_LIGHTRED) : CCharacter(ix, iy, icolor) {}
	CMouse(const CMouse& a) :CCharacter(a) {}
	void draw() {
		drawSizeBox(x, y + 60, COLOR_WHITE, 30);
		drawBoxMan(x, y, color, COLOR_BLUE);
	}
};
// CRabbit ���O
class CRabbit :public CCharacter {
public:
	CRabbit(int ix = 0, int iy = 0, int icolor = COLOR_YELLOW) : CCharacter(ix, iy, icolor) {}
	CRabbit(const CMouse& a) :CCharacter(a) {}
	void draw() {
		drawSizeBox(x - 24, y + 60, COLOR_LIGHTBLUE, 22); // ���զ�
		drawSizeBox(x + 24, y + 60, COLOR_LIGHTBLUE, 22); // �k�զ�
		drawBoxMan(x, y, color, COLOR_RED, COLOR_LIGHTMAGENTA);
	}
};

// CRabbit �� draw �禡�����e
		//drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // ���զ�
		//drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // �k�զ�	
		//drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P6");
	CCharacter* pc[5];							// �ŧi pc �� CCharacter ���@�����а}�C�A�� 5 �Ӧs��Ŷ�
	pc[0] = new CCharacter;							// pc[0] �H new ���o�ë��V CCharacter ����
	pc[1] = new CMouse(-150, 0);							// pc[1] ���o�ë��V CMouse ����A�P�ɳ]�w�y�Цb(-150, 0)
	pc[2] = new CMouse(150, 0, COLOR_GREEN);						// pc[2] ���o�ë��V CMouse ����A�]�w�y�лP�C�⬰(150, 0, COLOR_GREEN)
	pc[3] = new CRabbit(0, -150, COLOR_BROWN);							// pc[3] ���o�ë��V CRabbit ����A�]�w�y�лP�C�⬰(0, -150, COLOR_BROWN)
	pc[4] = new CRabbit[2];							// pc[4] ���o�ë��V�i��ӡj CRabbit ����
	pc[4]->setPos(-150, -150);							// �]�w pc[4] �ҫ��V���� 1 �Ӫ��󪺮y�Цb (-150, -150)�C���ܡG�I�s setPos �����禡 
	(pc[4]+1)->setPos(150, -150);						// �]�w pc[4] �ҫ��V���� 2 �Ӫ��󪺮y�Цb (150, -150)

	// pc[0] �� pc[4] �I�s draw �禡�Aø�X�ϧ�
	for (i = 0; i < 4; i++) {
		pc[i]->draw();
	}
	pc[4]->draw();
	(pc[4] + 1)->draw();
								// pc[4] �ҫ��V����Ӫ���A�ӧO�I�s draw �禡�Aø�X�ϧ�
	for (i = 0; i < 4; i++) {
		delete pc[i];
	}
	delete[]pc[4];							// pc[0] �� pc[4] ������o������Ŷ�
								// pc[4] ������o������Ŷ�

	while (!kbhit()) { delay(200); } return 0;
}

#endif