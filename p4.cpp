//  程式設計II，第三次上機考試 ，第 4 題 (3 分)
//
//   CCharacter 類別包含私有的成員變數
//		角色的座標 x, y 與顏色 color 都是 int 型別。
//      建構元必須包含這三個引數來設定這三個變數的內容
//          而且【都不可以】給預設值，必須在宣告的時候給予
//      draw() 函式：直接使用所給的函式內容
//
//   CMouse 類別以【公有】的方式繼承自 CCharacter 類別
//   CMouse 類別中包含私有的成員變數 血量 hp (int) 型別
//		CMouse 建構元的引數必須包含這四個成員變數，而且引數 
//		x, y, color 與 hp 的引數預設值分別為  1 1 COLOR_YELLOW 與 10
//      showHP() 函式：直接使用所給的函式內容
//      
//   完成以下的程式碼，並讓主程式能順利執行，同時輸出如圖 p4.jpg
//   且命令提示自元輸出如下
// 
//  CCharacter 建構元被呼叫
//  CMouse 建構元被呼叫
//  CCharacter 建構元被呼叫
//  CMouse 建構元被呼叫
//  生命值 = 5
//


#define P
#ifdef P4

#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include "functions.h"

using namespace std;

// CCharacter 類別
class CCharacter {
private:
	int x, y, color;
public:
	CCharacter(int ix ,int iy,int icolor) {
		x = ix; y = iy; color = icolor;
		cout << "CCharacter 建構元被呼叫" << endl;
	}
	void draw(){ drawBoxMan(x, y, color); }
};
  // 放到 CCharacter 建構元中
//drawBoxMan(x, y, color); // draw 函式的內容

// CMouse  類別
class CMouse :public CCharacter {
private:
	int hp;
public:
	CMouse(int ix = 1, int iy =1, int icolor = COLOR_YELLOW, int ihp = 10) : CCharacter(ix, iy,icolor) {
		hp = ihp;
		cout << "CMouse 建構元被呼叫" << endl;
	}
	void showHP() {
		cout << "生命值 = " << hp << endl;
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