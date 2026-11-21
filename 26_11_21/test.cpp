#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

template<class T1, class T2>
class A
{
public:
	A()
	{
		std::cout << "A(T1, T2)" << std::endl;
	}
private:
	T1 _a1;
	T2 _a2;
};

// 全特化
template<>
class A<int, char>
{
public:
	A()
	{
		std::cout << "A(int, char)" << std::endl;
	}
};

// 偏特化/半特化
template<class T1>
class A<T1, double>
{
public:
	A()
	{
		std::cout << "A(T1, double)" << std::endl;
	}
};

template<class T1>
class A<T1, char>
{
public:
	A()
	{
		std::cout << "A(T1, char)" << std::endl;
	}
};

// 特殊的偏特化
template<class T1, class T2>
class A<T1*, T2*>
{
public:
	A()
	{
		std::cout << "A(T1*, T2*)" << std::endl;
	}
};

template<class T1, class T2>
class A<T1&, T2&>
{
public:
	A()
	{
		std::cout << "A(T1&, T2&)" << std::endl;
	}
};

template<class T1, class T2>
class A<T1*, T2&>
{
public:
	A()
	{
		std::cout << "A(T1*, T2&)" << std::endl;
	}
};

int main()
{
	A<int, int> a1;

	A<int, char> a2;

	A<int, double> a3;
	A<char, double> a4;
	A<char, char> a5;

	A<int*, char*> a6;
	A<int&, char&> a7;
	A<int*, char&> a8;

	return 0;
}