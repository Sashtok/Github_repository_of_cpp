#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

class Time
{
public:
	Time(int hour)
		: _hour(hour)
	{}
private:
	int _hour;
};

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1, int& x)
		// 初始化列表是成员变量的定义
		:_n(0)// 所以const成员变量必须在初始化列表中进行初始化
		,_m(x)// 引用在定义时必须初始化，所以只能用初始化列表进行初始化
		,_t(1)// 如果没有默认构造，就要自己定义
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	// 成员变量的声明
	int _year;
	int _month;
	int _day;

	const int _n;
	int& _m;
	Time _t;
};

int main()
{
	const int a = 0;
	//a = 1; //报错 
	// const类型的变量只有一次初始化的机会，就是定义的时候，之后不能再被修改

	Date d1(1, 1, 1);// 对象的定义

	// 成员变量声明的顺序其实是其在内存中存放的顺序
	// 所以初始化列表按照声明的顺序初始化成员变量

	return 0;
}

class Sashtok
{
public:
	Sashtok(int a)
	{}
private:
	// cpp11规定可以写缺省值（也可以写表达式），给初始化列表用
	int _a = 1;
	int* _b = (int*)malloc(8);
	// 缺省值同时弥补了编译器生成的默认构造中，内置类型不初始化的缺点
};