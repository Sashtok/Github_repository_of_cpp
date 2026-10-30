#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

//int main()
//{
//	// << 的结合性是从左往右的，= 的结合性是从右往左的
//
//	// 流对象不支持拷贝构造函数
//	return 0;
//}

int main()
{
	Date d1(10, 10, 2026);
	Date d2;

	cout << d1 << d2 << endl;
	cin >> d2;
	cout << d2 << endl;

	d1++;
	cout << d1 << endl;

	++d1;
	cout << d1 << endl;

	d1--;
	cout << d1 << endl;

	--d1;
	cout << d1 << endl;

	d2 += 100;
	cout << d2 << endl;

	d2 -= 100;
	cout << d2 << endl;

	cout << d1 - d2 << endl;

	return 0;
}