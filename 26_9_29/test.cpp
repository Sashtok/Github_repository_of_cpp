#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

//int main()
//{
//	// 指针和引用的底层一样，编译时转汇编可以看到
//	/*int a = 0;
//00007FF6B6D018BE  mov         dword ptr[a], 0
//	int* pa = &a;
//00007FF6B6D018C5  lea         rax, [a]
//00007FF6B6D018C9  mov         qword ptr[pa], rax
//	* pa = 1;
//00007FF6B6D018CD  mov         rax, qword ptr[pa]
//00007FF6B6D018D1  mov         dword ptr[rax], 1
//	int& ra = a;
//00007FF6B6D018D7  lea         rax, [a]
//00007FF6B6D018DB  mov         qword ptr[ra], rax
//	ra = 2;
//00007FF6B6D018DF  mov         rax, qword ptr[ra]
//00007FF6B6D018E3  mov         dword ptr[rax], 2 */
//	
//	// 空引用
//	int* p = NULL;
//	int& r = *p;// 此时运行没有问题
//	r++;// 此时程序运行有问题
//
//	return 0;
//}

////#define ADD(a, b) ((a) + (b))
//inline int ADD(int a, int b)// 替代宏函数
//{
//	return a + b;
//}// 但是debug时默认不展开，方便调试
//
//int main()
//{
//	// 如果特别大的函数每次都展开，会导致可执行程序变大，所以inline对编译器知识建议
//	
//	// inline函数的实现要直接放到.h文件
//
//	return 0;
//}

//int main()
//{
//	// c的NULL既可以转成int (0) 也可以转成int* ((void*)0)，在cpp有函数重载的情况下就有歧义
//	// c语言允许void*赋值给任意类型指针，不用强转，而cpp不行，所以引入nullptr关键字
//
//	return 0;
//}

namespace Sashtok
{
	struct Node{};
}
Sashtok::Node a;

int main()
{
	// struct和class都可以定义类，但是一般只有当一个类所有成员都是公有时才用struct

	// 直接在类里定义的函数默认是inline，但是声明和定义分开的成员函数不是inline

	//没有成员变量的类可以用在仿函数的类

	return 0;
}