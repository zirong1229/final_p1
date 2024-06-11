//  程式設計II，第三次上機考試 ，第 6 題 (6 分)
//
//   宣告以下三個類別
//    CCharacter 類別包含私有的成員變數與公有成員函式
//		角色的座標 x, y 與顏色 color 都是 int 型別。
//      建構元    ： 包含這三個引數來設定這三個變數的內容
//                   引數的預設值分別是 0, 0, COLOR_LIGHTGREEN
//      setPos函式：兩個 int 型別引數，設定角色的 x/y 座標，沒有回傳值
//      draw函式：根據所給的函式呼叫，繪出對應的圖形，沒有回傳值
//       
//   CMouse 類別，【公有】繼承自 CCharacter 類別，包含以下的公有成員函式
//      建構元 : 接收角色的座標 x, y 與顏色 color，
//				 呼叫 CCharacter 建構元將所傳入的引數傳遞給該類別
//      draw函式：根據所給的函式呼叫，繪出對應的圖形，沒有回傳值
// 
//	 CRabbit 類別，【公有】繼承自 CCharacter 類別，包含以下的公有成員函式
//      建構元 : 接收角色的座標 x, y 與顏色 color，
//				 呼叫 CCharacter 建構元將所傳入的引數傳遞給該類別
//      draw函式：根據所給的函式呼叫，繪出對應的圖形，沒有回傳值
//      
// 
//  主程式以 CCharacter 宣告一個一維指標陣列，包含五個儲存空間，
//	各儲存空間所對應指向並取得的物件，請參考主程式的註解說明。
//  必須利用多型的方式完成如 p6.jpg 所繪出的【六】個圖形。
//  
//  計分要求：必須滿足以下的需求才能計分。
//      1. 三個類別的建構元都必須寫出來，
//		2. CRabbit 與 CMouse 的建構元必須呼叫 CCharacter 的建構元，否則所畫出的圖形將不會正確
//      3. 主程式必須有對應的資源釋放
//      4. 執行結果必須與 P6.jpg 相同才能計分
// 

#define P
#ifdef P6

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
	void setPos(int ix, int iy) { x = ix; y = iy; }
	virtual void draw() { drawBoxMan(x, y, color); }
};
// CMouse 類別
class CMouse :public CCharacter {
public:
	CMouse(int ix = 0, int iy = 0, int icolor = COLOR_LIGHTRED) : CCharacter(ix, iy, icolor) {}
	CMouse(const CMouse& a) :CCharacter(a) {}
	void draw() {
		drawSizeBox(x, y + 60, COLOR_WHITE, 30);
		drawBoxMan(x, y, color, COLOR_BLUE);
	}
};
// CRabbit 類別
class CRabbit :public CCharacter {
public:
	CRabbit(int ix = 0, int iy = 0, int icolor = COLOR_YELLOW) : CCharacter(ix, iy, icolor) {}
	CRabbit(const CMouse& a) :CCharacter(a) {}
	void draw() {
		drawSizeBox(x - 24, y + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
		drawSizeBox(x + 24, y + 60, COLOR_LIGHTBLUE, 22); // 右耳朵
		drawBoxMan(x, y, color, COLOR_RED, COLOR_LIGHTMAGENTA);
	}
};

// CRabbit 的 draw 函式的內容
		//drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
		//drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 右耳朵	
		//drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);

int main()
{
	int i;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P6");
	CCharacter* pc[5];							// 宣告 pc 為 CCharacter 的一維指標陣列，有 5 個存放空間
	pc[0] = new CCharacter;							// pc[0] 以 new 取得並指向 CCharacter 物件
	pc[1] = new CMouse(-150, 0);							// pc[1] 取得並指向 CMouse 物件，同時設定座標在(-150, 0)
	pc[2] = new CMouse(150, 0, COLOR_GREEN);						// pc[2] 取得並指向 CMouse 物件，設定座標與顏色為(150, 0, COLOR_GREEN)
	pc[3] = new CRabbit(0, -150, COLOR_BROWN);							// pc[3] 取得並指向 CRabbit 物件，設定座標與顏色為(0, -150, COLOR_BROWN)
	pc[4] = new CRabbit[2];							// pc[4] 取得並指向【兩個】 CRabbit 物件
	pc[4]->setPos(-150, -150);							// 設定 pc[4] 所指向的第 1 個物件的座標在 (-150, -150)。提示：呼叫 setPos 成員函式 
	(pc[4]+1)->setPos(150, -150);						// 設定 pc[4] 所指向的第 2 個物件的座標在 (150, -150)

	// pc[0] 到 pc[4] 呼叫 draw 函式，繪出圖形
	for (i = 0; i < 4; i++) {
		pc[i]->draw();
	}
	pc[4]->draw();
	(pc[4] + 1)->draw();
								// pc[4] 所指向的兩個物件，個別呼叫 draw 函式，繪出圖形
	for (i = 0; i < 4; i++) {
		delete pc[i];
	}
	delete[]pc[4];							// pc[0] 到 pc[4] 釋放取得的物件空間
								// pc[4] 釋放取得的物件空間

	while (!kbhit()) { delay(200); } return 0;
}

#endif