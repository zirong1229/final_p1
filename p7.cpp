//  程式設計II，第三次上機考試 ，第 7 題 (3 分)
//
//   宣告以下三個類別
//    CCharacter 類別包含私有的成員變數與公有成員函式
//		角色的座標 x, y 與顏色 color 都是 int 型別。
//      建構元    ： 包含這三個引數來設定這三個變數的內容
//                   引數的預設值分別是 0, 0, COLOR_LIGHTGREEN
//      解構元    ： 裡面包含所提供的輸出即可
//      setPos函式：兩個 int 型別引數，設定角色的 x/y 座標，沒有回傳值
//      draw函式  ：沒有回傳值，必須宣告成純虛擬函式
//        
//   CMouse 類別，【公有】繼承自 CCharacter 類別，包含以下的公有成員函式
//      建構元 : 接收角色的座標 x, y 與顏色 color，
//				 呼叫 CCharacter 建構元將所傳入的引數傳遞給該類別
//      解構元 ： 裡面包含所提供的輸出即可 
//      draw函式：根據所給的函式呼叫，繪出對應的圖形，沒有回傳值
// 
// 
//  完成上面的宣告，並依照主程式的註解，完成 pc2m 與 pm 的物件取得
//	同時讓主程式能正常執行，並輸出如圖 p7.jpg 的結果
// 
//  計分要求：必須滿足以下的需求才能計分。
//      1. 兩個建構元與解構元都必須寫出來，
//      2. 資源釋放的訊息必須如圖 p7.jpg 的結果
// 

#define P
#ifdef P7

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include "functions.h"
using namespace std;

// CCharacter 類別
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
	virtual ~CCharacter(){ cout << "CCharacter 解構元被呼叫" << endl; }
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
	~CMouse(){cout << "CMouse 解構元被呼叫" << endl;}
};
// draw 函式的內容
		//drawSizeBox(_ix, _iy + 60, COLOR_WHITE, 30); 
		//drawBoxMan(_ix, _iy, _icolor, COLOR_BLUE);

 // 放到 CMouse 解構元中   


int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P7");
	CCharacter *pc2m = new CMouse(-100, 0, COLOR_YELLOW);
	CCharacter* pm = new CMouse(100, 0);							// 以 new 取得並指向 CMouse 物件，並設定座標與顏色為(-100,0, COLOR_YELLOW)
								// 以 new 取得並指向 CMouse 物件，並設定座標為 (100,0)
	pc2m->draw();
	pm->draw();
	delete pm;
	delete pc2m;
	while (!kbhit()) { delay(200); } return 0;
}

#endif