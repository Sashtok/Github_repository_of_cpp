#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

void func1(int& x)
{}

int& func2()
{}

//void STModifyTop(Stack& st, int x)
//{
//  assert(st.size > 0);
//	st.a[st.top - 1] = x;
//}
//
//int& STTop(Stack& st)
//{
//  assert(st.size > 0);
//	return st.a[st.top - 1];
//}

int main()
{
	// 引用不开空间
	// 引用必须初始化
	// 可以给别名取别名
	int a = 0;
	int& b = a;
	int& c = b;

	// 引用不能改变指向
	int d = 20;
	b = d;// 赋值
	
	// 指针和引用相辅相成，如链表节点的next必须用指针

	func1(a);

	// 引用传参比指针更方便点，因为不用 & 和 *

	// 引用做返回值：返回别名
	// 比如我想修改栈顶元素
	// 不用引用返回值就只能调用 STModifyTop(st, 3);
	// 但是引用做返回值就可以 STTop(st) = 3;
	// 如果返回的是 int 就不行，因为返回值是临时对象，具有常性
	// 但也不能全用引用返回
	/*int& func()
	{
		int a = 0;
		return a;// a是局部变量
	}*/

	// const引用可以引用普通对象
	int m = 6;
	const int& rm = 6;// 只读

	// 常量也可以取别名，但必须使用const引用，用普通引用是权限放大
	const int& ra = 10;//
	int x = 0;
	int y = 0;
	const int& rb = x + y;// 表达式
	double n = 6.5;
	const int& rc = n;// 隐式类型转换会产生临时对象，具有常性
	// 临时对象的生命周期会和引用同步
	// const引用可以让函数传参很宽泛

	// 产生临时对象：函数传值返回，隐式类型转换，表达式的结果
	
	return 0;
}