#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

class Date
{
public:
	Date(int year = 2026)
	{
		_year = year;
	}
	Date(const Date& d)
	{
		_year = d._year;
	}
private:
	int _year;
};

void func(Date d)
{

}

int main()
{
	// cpp规定，传值传参要调用拷贝构造函数，如
	Date d1;
	func(d1);// 运行到这里后，先进入拷贝构造函数，是为了在func函数内部创建一个d的副本
	         // 然后才进入func函数
	// 因此，如果拷贝构造写的是 Date(Date d)，进行拷贝构造时
	Date d2(d1);// 运行到这里，由于传值传参要调用拷贝构造函数，而拷贝构造函数也是传值传参
	            // 那么进入拷贝构造函数之前，会再次调用拷贝构造函数，进而形成无穷递归调用
	            // 所以拷贝构造函数的参数必须是引用
	// 此外，自定义类型的参数最好也写成引用，如func(Date& d)

	Date d3 = d1;// 拷贝构造也可以这样写
	
	return 0;
}