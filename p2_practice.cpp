#define P
#ifdef P2

#define _CRT_SECURE_NO_WARNINGS 1
#include ".\BGIKernel\graphics.h"
#include <iostream>
#include <iomanip> 
#include <windows.h>
#include "functions.h"
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
using namespace std;
bool g_bChange = false;// 宣告並初始化全域變數 g_bChange 為 false

class CMouse {
private: 
	int ix, iy, icolor;
public:
	CMouse(int x=0, int y=0, int color=COLOR_YELLOW) {
		ix = x;iy = y; icolor = color;
	}
	void draw() {
		if (g_bChange) {
			drawSizeBox(ix - 24, iy + 60, COLOR_LIGHTBLUE, 22); // 左耳朵
			drawSizeBox(ix + 24, iy + 60, COLOR_LIGHTBLUE, 22); // 右耳朵	
			drawBoxMan(ix, iy, icolor, COLOR_RED, COLOR_LIGHTMAGENTA);
		}
		else drawBoxMan(ix, iy, icolor, COLOR_RED);
	}
};


int main(void) {
	initwindow(SCREENWIDTH, SCREENWIDTH, "P2");
	int i = 0;
	char ch;
	CMouse mouse;

	while (i<2)
	{
		cleardevice();
		mouse.draw();
		swapbuffers();
		ch = getch();
		if (ch == 'c' || ch == 'C')g_bChange = !g_bChange;
		rewind(stdin);
		i++;
	}

	mouse.draw();
	swapbuffers();
	while (!kbhit()) { delay(200); } // 等待鍵盤輸入，延遲 200 毫秒
	return 0; // 程式正常結束
	system("pause"); // 暫停程式，等待使用者按任意鍵
	return(0); // 程式正常結束
}

#endif // 結束條件編譯