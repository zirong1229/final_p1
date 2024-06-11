//  程式設計II，第三次上機考試 ，第 2 題 (2 分)
//   
// CMouse 類別包含
//		私有 int 型別的成員變數 x 、 y 與顏色 color
//		公有成員函式 
//         建構元：預設值設定  x 與 y 為 0, 0，color 為 COLOR_YELLOW
//         draw函式：呼叫對應的函式畫出自己
//                   當 g_bChange 為 false 時，呼叫 A 區段的程式碼
//                   當 g_bChange 為 true 時，呼叫 B 區段的程式碼
//                   A / B 區段的程式碼，參考題目的註解
// 
// 宣告一個 bool 型別的全域變數 g_bChange，初始值為 false
//    主程式的程式碼中，當使用者按下 c 時，
//	  讓 g_bChange 內容進行 true 與 false 的切換
//
// 完成以下的程式碼，輸出的結果參考圖 p2-1.jpg 與 p2-2.jpg
//    執行時顯示 p2-1.jpg，按下 c 鍵後為 p2-2.jpg，再按一次 c 鍵後為 p2-1.jpg

#define P
#ifdef P2

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip> 
#include <windows.h>
#include "functions.h"

using namespace std;

bool g_bChange = false;					// 宣告 g_bChange

// CMouse  類別
class CMouse {
private:
	int _ix, _iy, _icolor;
public:
	CMouse(int x = 0, int y = 0, int color = COLOR_YELLOW) {
		_ix = x; _iy = y; _icolor = color;
	}
	void draw() {
		if (g_bChange) {
			drawSizeBox(_ix - 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
			drawSizeBox(_ix + 24, _iy + 60, COLOR_LIGHTBLUE, 22); // 右耳朵	
			drawBoxMan(_ix, _iy, _icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
		}
		else drawBoxMan(_ix, _iy, _icolor, COLOR_RED);
	}
};
			// A 區段 g_bChange 為 真時 呼叫的內容
			//drawSizeBox(x - 24, y + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
			//drawSizeBox(x + 24, y + 60, COLOR_LIGHTBLUE, 22); // 右耳朵	
			//drawBoxMan(x, y, color, COLOR_RED, COLOR_LIGHTMAGENTA);
			
			// B 區段 g_bChange 為 假 時 呼叫的內容
			//drawBoxMan(x, y, color, COLOR_RED);

int main(void)
{
	initwindow(SCREENWIDTH, SCREENWIDTH, "P2");
	int i = 0;
	char ch;
	CMouse mx;			// 宣告 CMouse 物件

	while (i < 2)  // 按三次程式就會離開迴圈
	{
		cleardevice();
		mx.draw();		// 畫出老鼠
		swapbuffers();
		ch = getch();
		if (ch == 'c' || ch == 'C') g_bChange = !g_bChange;				// 判斷是否按下 c 鍵
		rewind(stdin);
		i++;
	}
	mx.draw();	// 畫出老鼠
	swapbuffers();
	while (!kbhit()) { delay(200); } return 0;
	system("pause"); return(0);
}

#endif