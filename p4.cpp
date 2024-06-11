//  �{���]�pII�A�ĤT���W���Ҹ� �A�� 4 �D (3 ��)
//
//   CCharacter ���O�]�t�p���������ܼ�
//		���⪺�y�� x, y �P�C�� color ���O int ���O�C
//      �غc�������]�t�o�T�Ӥ޼ƨӳ]�w�o�T���ܼƪ����e
//          �ӥB�i�����i�H�j���w�]�ȡA�����b�ŧi���ɭԵ���
//      draw() �禡�G�����ϥΩҵ����禡���e
//
//   CMouse ���O�H�i�����j���覡�~�Ӧ� CCharacter ���O
//   CMouse ���O���]�t�p���������ܼ� ��q hp (int) ���O
//		CMouse �غc�����޼ƥ����]�t�o�|�Ӧ����ܼơA�ӥB�޼� 
//		x, y, color �P hp ���޼ƹw�]�Ȥ��O��  1 1 COLOR_YELLOW �P 10
//      showHP() �禡�G�����ϥΩҵ����禡���e
//      
//   �����H�U���{���X�A�����D�{���බ�Q����A�P�ɿ�X�p�� p4.jpg
//   �B�R�O���ܦۤ���X�p�U
// 
//  CCharacter �غc���Q�I�s
//  CMouse �غc���Q�I�s
//  CCharacter �غc���Q�I�s
//  CMouse �غc���Q�I�s
//  �ͩR�� = 5
//


#define P
#ifdef P4

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
	CCharacter(int ix ,int iy,int icolor) {
		x = ix; y = iy; color = icolor;
		cout << "CCharacter �غc���Q�I�s" << endl;
	}
	void draw(){ drawBoxMan(x, y, color); }
};
  // ��� CCharacter �غc����
//drawBoxMan(x, y, color); // draw �禡�����e

// CMouse  ���O
class CMouse :public CCharacter {
private:
	int hp;
public:
	CMouse(int ix = 1, int iy =1, int icolor = COLOR_YELLOW, int ihp = 10) : CCharacter(ix, iy,icolor) {
		hp = ihp;
		cout << "CMouse �غc���Q�I�s" << endl;
	}
	void showHP() {
		cout << "�ͩR�� = " << hp << endl;
	}
};


int main(void) {
	initwindow(SCREENWIDTH, SCREENWIDTH, "P4");
	CMouse mx1, mx2(0, 100, 13, 5);
	mx1.draw();
	mx2.draw();
	mx2.showHP();
	system("pause"); return(0);
}

#endif