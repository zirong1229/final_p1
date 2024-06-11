//  �{���]�pII�A�ĤT���W���Ҹ� �A�� 1 �D (4 ��)
// 
// �ŧi CVec2 ���O�̭��]�t
//   �p���]�t(���O float ���O)
//       �V�q�� x y �y��
//   �����]�t
//       �غc���G����� float ���O���޼ơA�޼ƪ��w�]�ȳ��O 0.0f         
//               �]�N�O�]�w�w�]���V�q���e�� (0.0f, 0.0f)
//       �T�ӹB��l + - �P = 
//       +�B��l �G�]�N ����+����A�����ӦV�q���ۥ[�A�^�ǭȬ� CVec2 ����
//       -�B��l �G�]�N ����-����A�����ӦV�q���۴�A�^�ǭȬ� CVec2 ���� 
//       =�B��l �G�]�N ����=����A����V�q���e���]�w�A�^�ǭȬ� CVec2 ���ѷӪ��� 
//       show �禡 : �p�D�ةҵ��A���μ��g 
// 
//   �����H�U���{���X�A�����D�{���බ�Q����A�P�ɿ�X�p�U�����G
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

// CVec2  ���O
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