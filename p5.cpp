//  �{���]�pII�A�ĤT���W���Ҹ� �A�� 5 �D (4 ��)
//
//   CCharacter ���O�]�t�p���������ܼ�
//		���⪺�y�� x, y �P�C�� color ���O int ���O�C
//      �غc��    �G �]�t�o�T�Ӥ޼ƨӳ]�w�o�T���ܼƪ����e
//                   �޼ƪ��w�]�Ȥ��O�O 0, 0, COLOR_WHITE
//      �����غc���G �]�w�ثe�����󪺮y�лP�C�⬰�ǤJ���󪺭�
//      setPos�禡�G��� int ���O�޼ơA�]�w���⪺ x/y �y�СA�S���^�ǭ�
//      draw()�禡�G�����ϥΩҵ����禡���e�A�S���^�ǭ�
//
//   CMouse ���O�H�i�����j���覡�~�Ӧ� CCharacter ���O
//   CMouse ���O���]�t�p���������ܼ� ��q hp (int) ���O
//		CMouse �غc�����޼ƥ����]�t�o�|�Ӧ����ܼơA�ӥB�޼� 
//		x, y, color �P hp ���޼ƹw�]�Ȥ��O��  0 0 COLOR_YELLOW �P 10
//      �����غc���G �]�w�ǤJ������ hp �A�éI�s CCharacter �������غc��
//      showHP() �禡�G�����ϥΩҵ����禡���e
//       
//  �p���n�D�G
//      1. CCharacter �P CMouse ���غc���P�����غc���������g�X��
//      2. ���浲�G�����P P5.jpg �ۦP�~��p��
// 
//   �����H�U���{���X�A�����D�{���බ�Q����A�P�ɿ�X�p�� p5.jpg
//


#define P5
#ifdef P5

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include "functions.h"

using namespace std;

// CCharacter ���O
class CCharacter {
private:
	int x, y, color;
public:
	CCharacter(int ix = 0, int iy = 0, int icolor = COLOR_WHITE) {
		x = ix; y = iy; color = icolor;
	}
	CCharacter(const CCharacter&ma) {
		x = ma.x; y = ma.y;
		color = ma.color;
	}
	void setPos(int ix, int iy) { x = ix; y = iy; }
	virtual void draw() { drawBoxMan(x, y, color); }
};
// CMouse  ���O
class CMouse :public CCharacter {
private:
	int hp;
public:
	CMouse(int ix = 0, int iy = 0, int icolor = COLOR_YELLOW, int ihp = 10) : CCharacter(ix, iy, icolor) {
		hp = ihp;
	}
	CMouse(const CMouse& a):CCharacter(a) {
		hp = a.hp;
	}
	void showHP() {
		cout << "�ͩR�� = " << hp << endl;
	}
};


int main(void) {
	initwindow(SCREENWIDTH, SCREENWIDTH, "P5");
	CMouse mx(0, 0, 14);
	CMouse my(mx);
	CMouse mz = my;
	mx.draw();
	my.setPos(0, 120); my.draw(); my.showHP();
	mz.setPos(0, -120); mz.draw(); mz.showHP();
	system("pause"); return(0);
}

#endif