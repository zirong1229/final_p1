//  程式設計II，第三次上機考試 ，第 5 題 (4 分)
//
//   CCharacter 類別包含私有的成員變數
//		角色的座標 x, y 與顏色 color 都是 int 型別。
//      建構元    ： 包含這三個引數來設定這三個變數的內容
//                   引數的預設值分別是 0, 0, COLOR_WHITE
//      拷貝建構元： 設定目前的物件的座標與顏色為傳入物件的值
//      setPos函式：兩個 int 型別引數，設定角色的 x/y 座標，沒有回傳值
//      draw()函式：直接使用所給的函式內容，沒有回傳值
//
//   CMouse 類別以【公有】的方式繼承自 CCharacter 類別
//   CMouse 類別中包含私有的成員變數 血量 hp (int) 型別
//		CMouse 建構元的引數必須包含這四個成員變數，而且引數 
//		x, y, color 與 hp 的引數預設值分別為  0 0 COLOR_YELLOW 與 10
//      拷貝建構元： 設定傳入的物件的 hp ，並呼叫 CCharacter 的拷貝建構元
//      showHP() 函式：直接使用所給的函式內容
//       
//  計分要求：
//      1. CCharacter 與 CMouse 的建構元與拷貝建構元都必須寫出來
//      2. 執行結果必須與 P5.jpg 相同才能計分
// 
//   完成以下的程式碼，並讓主程式能順利執行，同時輸出如圖 p5.jpg
//


#define P5
#ifdef P5

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
// CMouse  類別
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
		cout << "生命值 = " << hp << endl;
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