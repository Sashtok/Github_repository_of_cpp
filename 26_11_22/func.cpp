#define _CRT_SECURE_NO_WARNINGS 1
#include"func.h"

// 定义
//template<class T>
//void func1(const T& x)
//{
//	std::cout << "func1(const T& x)" << std::endl;
//}

// 显示实例化
template
void func1(const int& x);

// 定义
void func2(const int& x)
{
	std::cout << "func1(const int& x)" << std::endl;
}