//  程式設計II，第三次上機考試 ，第 1 題 (4 分)
// 
// 宣告 CVec2 類別裡面包含
//   私有包含(都是 float 型別)
//       向量的 x y 座標
//   公有包含
//       建構元：有兩個 float 型別的引數，引數的預設值都是 0.0f         
//               也就是設定預設的向量內容為 (0.0f, 0.0f)
//       三個運算子 + - 與 = 
//       +運算子 ：也就 物件+物件，執行兩個向量的相加，回傳值為 CVec2 物件
//       -運算子 ：也就 物件-物件，執行兩個向量的相減，回傳值為 CVec2 物件 
//       =運算子 ：也就 物件=物件，執行向量內容的設定，回傳值為 CVec2 的參照物件 
//       show 函式 : 如題目所給，不用撰寫 
// 
//   完成以下的程式碼，並讓主程式能順利執行，同時輸出如下的結果
// 
// v1 = (0, 0)
// v2 = (3, 1)
// v3 = (1, 1)
// v1 - v3 = (-1, -1)
// v2 + v3 = (4, 2)
// v1 = v2 - v3 = (2, 0)
// v3 = v2 + v1 = (5, 1)
//  

#define P
#ifdef P1

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

// CVec2  類別
class CVec2 {
private:
	float x, y;
public:
	CVec2(float a = 0.0f, float b = 0.0f) {
		x = a;
		y = b;
	}
	CVec2& operator+(CVec2 &a) {
		CVec2 ans;
		ans.x = this->x + a.x;
		ans.y = this->y + a.y;
		return(ans);
	}
	CVec2& operator-(CVec2& a) {
		CVec2 ans;
		ans.x = this->x - a.x;
		ans.y = this->y - a.y;
		return(ans);
	}
	CVec2& operator=(CVec2& a) {
		this->x = a.x;
		this->y = a.y;
		return(*this);
	}

	void show() {cout << "(" << x << "," << y << ")";}
};
//	void show() {
//		cout << "(" << x << "," << y << ")";
//	}

int main(void)
{
	CVec2 v1, v2(3,1), v3(1,1);
	cout << "v1 = "; v1.show(); cout << endl;
	cout << "v2 = "; v2.show(); cout << endl;
	cout << "v3 = "; v3.show(); cout << endl;
	cout << "v1 - v3 = "; (v1-v3).show(); cout << endl;
	cout << "v2 + v3 = "; (v2+v3).show(); cout << endl;
	v1 = (v2 - v3);
	cout << "v1 = v2 - v3 = "; v1.show(); cout << endl;
	v3 = (v2 + v1);
	cout << "v3 = v2 + v1 = "; v3.show(); cout << endl;
	system("pause"); return(0);
}

#endif