//  程式設計II，第三次上機考試 ，第 3 題 (4 分)
//   
// CMouse 類別包含
//		私有包含
//			int 型別的成員變數 x 、 y 與顏色 color
//			bool 型別的變數 btracer
//			CMouse 的指標變數 target
//		公有成員函式 
//         建構元：沒有引數，直接設定 x 與 y 為 0, 0，color 為  COLOR_YELLOW
//                 btracer 為 false (預設為【被】追蹤者)
//				   target 為 nullptr
//         setTracer 函式 : 一個 bool 型別的引數，設定 btracer 為傳入的值
//		   setTarget 函式 : 一個 CMouse 型別的【參照】引數，
//							設定 target 為指向該傳入【物件的位址】
//	 	   getPos 函式   : 兩個 int 型別以【傳指標】的形式傳入。
//                         將目前老鼠的位置利用該傳入的變數傳回給呼叫者
// 
//         draw  函式    : 根據自己的狀態(追蹤還是被追蹤)呼叫對應的函式畫出自己，直接使用所給的函式內容
//		   update 函式   : 直接使用所給的函式內容
// 
//   完成以下的程式碼，並控制四方塊上下左右移動即可，
//					   追蹤者保持在玩家控制方塊的正下方即可
//   

#define P
#ifdef P3

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip>
#include "functions.h"

using namespace std;

// CMouse  類別
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
		if (btracer) drawBoxMan(_ix, _iy - 100, _icolor); // 追蹤者呼叫這個函式
		else drawColorBox(_ix, _iy, _icolor);     // 被追蹤者呼叫這個函式
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
// 私有的

// 公有的
//void updatePos();
//update(char cIn);

//
//drawBoxMan(x, y - 100, color); // 追蹤者呼叫這個函式
//drawColorBox(x, y, color);     // 被追蹤者呼叫這個函式

void CMouse::update(char cIn) // update 函式的內容
{
	switch (cIn) {
	case 'w': // 往上. 更改老鼠位置,並根據新的位置,更新老鼠的狀態
		_iy = _iy + 20; break;
	case 's': // 往下
		_iy = _iy - 20; break;
	case 'a': // 往左
		_ix = _ix - 20; break;
	case 'd': // 往右
		_ix = _ix + 20; break;
	}
}
int main()
{
	char cIn;
	int i = 0;
	initwindow(SCREENWIDTH, SCREENWIDTH, "P3");
	CMouse m1, m2;
	m2.setTracer(true);					// 設定 m2 為追蹤者
	m2.setTarget(m1);				// 設定 m2 的追蹤對象為 m1
	m2.updatePos();					// 讓 m2 更新位置
	
	while ( i < 10 ) // 移動 10 次程式就會離開迴圈
	{
		cleardevice();
		m1.draw();	// 畫出老鼠
		m2.draw();
		swapbuffers();
		cIn = getch();
		m1.update(cIn);					// 更新輸入讓 m1 更新位置
		m2.updatePos();					// 讓 m2 更新位置
		rewind(stdin);
		i++;
	}
	cleardevice();
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
}

#endif