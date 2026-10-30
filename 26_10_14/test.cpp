#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

class Sashtok
{
public:
	Sashtok(int a = 0)
		:_a(a)
	{
		std::cout << "Sashtok(int a = 0)" << std::endl;
	}
	Sashtok(const Sashtok& s)
		:_a(s._a)
	{
		std::cout << "Sashtok(const Sashtok& s)" << std::endl;
	}
	~Sashtok()
	{
		std::cout << "~Sashtok()" << std::endl;
	}
	void Print()
	{
		std::cout << _a << std::endl;
	}
	Sashtok& operator++()
	{
		++_a;
		std::cout << "operator++()" << std::endl;
		return *this;
	}
private:
	int _a;
};

void func1(Sashtok s)
{}

Sashtok func2()
{
	Sashtok s(2);
	return s;
}

Sashtok func3()
{
	Sashtok s(2);
	++s;
	return s;
}

int main()
{
	// 首先需明确，优化是与编译器有关的
	// 传参的优化
	Sashtok s1 = 1;// 隐式类型转换，把构造+拷贝构造优化为构造
	func1(Sashtok(1));// 匿名对象的传值传参，把构造+拷贝构造优化为构造
	func1(1);// 相当于隐式类型转换，把构造+拷贝构造优化为构造

	// 传返回值的优化
	func2().Print();// 传值返回，然后调用临时对象的Print()，把构造+拷贝构造优化为构造
	// 这里的优化实际上是省去了对象s，直接构造临时对象
	// 临时对象会在调用完Print()就析构
	std::cout << "********";// 加这行是为了显示出临时对象的析构发生在这一行前

	func3().Print();// 更激进的优化，把构造、拷贝构造、前置++优化为一次构造
					// 直接用++后的值构造匿名对象

	Sashtok s2 = func2();// 把构造+拷贝构造+再次拷贝构造优化为构造+拷贝构造，省去了临时对象
						 // 更激烈的优化会把对象s也省去，直接构造s2

	Sashtok s3;
	s3 = func2();// 这里就有可能不会被优化
				 // 但也可能优化，把s构造后充当临时对象，省去了一次拷贝构造

	return 0;
}