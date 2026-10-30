#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

class Date
{
public:
	Date()
	{
		_x = 0;
	}
	void Print()
	{

	}
private:
	int _x;
};

int main()
{
	//Date d1();// 无参构造函数不可以写成这样,因为会和函数的声明搞混
	//d1.Print();          // Date func()
	
	// 虽然大多数情况编译器生成的构造函数没有用，但是有些情况下也有用
	// 如用两个栈实现队列时（栈的初始化还是要自己写）

	return 0;
}