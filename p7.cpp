//  �{���]�pII�A�ĤT���W���Ҹ� �A�� 7 �D (3 ��)
//
//   �ŧi�H�U�T�����O
//    CCharacter ���O�]�t�p���������ܼƻP���������禡
//		���⪺�y�� x, y �P�C�� color ���O int ���O�C
//      �غc��    �G �]�t�o�T�Ӥ޼ƨӳ]�w�o�T���ܼƪ����e
//                   �޼ƪ��w�]�Ȥ��O�O 0, 0, COLOR_LIGHTGREEN
//      �Ѻc��    �G �̭��]�t�Ҵ��Ѫ���X�Y�i
//      setPos�禡�G��� int ���O�޼ơA�]�w���⪺ x/y �y�СA�S���^�ǭ�
//      draw�禡  �G�S���^�ǭȡA�����ŧi���µ����禡
//        
//   CMouse ���O�A�i�����j�~�Ӧ� CCharacter ���O�A�]�t�H�U�����������禡
//      �غc�� : �������⪺�y�� x, y �P�C�� color�A
//				 �I�s CCharacter �غc���N�ҶǤJ���޼ƶǻ��������O
//      �Ѻc�� �G �̭��]�t�Ҵ��Ѫ���X�Y�i 
//      draw�禡�G�ھکҵ����禡�I�s�Aø�X�������ϧΡA�S���^�ǭ�
// 
// 
//  �����W�����ŧi�A�è̷ӥD�{�������ѡA���� pc2m �P pm ��������o
//	�P�����D�{���ॿ�`����A�ÿ�X�p�� p7.jpg �����G
// 
//  �p���n�D�G���������H�U���ݨD�~��p���C
//      1. ��ӫغc���P�Ѻc���������g�X�ӡA
//      2. �귽���񪺰T�������p�� p7.jpg �����G
// 

#define P
#ifdef P7

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
	virtual ~CCharacter(){ cout << "CCharacter �Ѻc���Q�I�s" << endl; }
	void setPos(int ix, int iy) { x = ix; y = iy; }
	virtual void draw() {
		drawSizeBox(x, y + 60, COLOR_WHITE, 30);
		drawBoxMan(x, y, color, COLOR_BLUE);
	}
};
class CMouse :public CCharacter {
public:
	CMouse(int ix = 0, int iy = 0, int icolor = COLOR_LIGHTRED) : CCharacter(ix, iy, icolor) {}
	CMouse(const CMouse& a) :CCharacter(a) {}
	void draw() {
		drawSizeBox(x, y + 60, COLOR_WHITE, 30);
		drawBoxMan(x, y, color, COLOR_BLUE);
	}
	~CMouse(){cout << "CMouse �Ѻc���Q�I�s" << endl;}
};
// draw �禡�����e
		//drawSizeBox(_ix, _iy + 60, COLOR_WHITE, 30); 
		//drawBoxMan(_ix, _iy, _icolor, COLOR_BLUE);

 // ��� CMouse �Ѻc����   


int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P7");
	CCharacter *pc2m = new CMouse(-100, 0, COLOR_YELLOW);
	CCharacter* pm = new CMouse(100, 0);							// �H new ���o�ë��V CMouse ����A�ó]�w�y�лP�C�⬰(-100,0, COLOR_YELLOW)
								// �H new ���o�ë��V CMouse ����A�ó]�w�y�Ь� (100,0)
	pc2m->draw();
	pm->draw();
	delete pm;
	delete pc2m;
	while (!kbhit()) { delay(200); } return 0;
}

#endif