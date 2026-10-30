#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>

//class Sashtok
//{
//};
//
//bool cmp(int a, int b)
//{
//	return a > b; // 降序
//}
//
//int main()
//{
//	// 代码块的局部域
//	{
//		Sashtok s;
//	}
//	// 出了局部域，对象就被销毁了
//
//	// 匿名对象的生命周期只在它所在的那一行
//	// const& 可以延长匿名对象的生命周期
//
//	int a[] = { 5,8,9,1,4,7,3 };
//	// sort() 需要包含<algorithm>头文件，同时它在std命名空间下
//	std::sort(a, a + 7);// 默认是升序
//	
//	int b[] = { 5,8,9,1,4,7,3 };
//	std::sort(b, b + 7, cmp);// 传函数指针可以改为降序
//
//	int c[] = { 5,8,9,1,4,7,3 };
//	std::greater<int> gr;
//	std::sort(c, c + 7, gr);// 这样也可以排成降序，但这里传的是有名对象
//
//	int d[] = { 5,8,9,1,4,7,3 };
//	std::sort(d, d + 7, std::greater<int>());// 这样就是传匿名对象传参，更方便点
//
//	return 0;
//}

//#include <cerrno>
//class Solution
//{
//public:
//	int Sum_Solution(int n)
//	{
//		_Solution a[n];
//		return res;
//	}
//private:
//	class _Solution
//	{
//	public:
//		_Solution()
//		{
//			res += i;
//			i++;
//		}
//	};
//	static int i;
//	static int res;
//};
//int Solution::i = 1;
//int Solution::res = 0;

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
private:
	int _a;
};

void func1(Sashtok s)
{
}

Sashtok func2()
{
	Sashtok s(2);
	return s;
}

int main()
{
	// 传参的优化
	Sashtok s1 = 1;// 隐式类型转换，把构造+拷贝构造优化为构造
	func1(Sashtok(1));// 匿名对象的传值传参，把构造+拷贝构造优化为构造
	func1(1);// 相当于隐式类型转换，把构造+拷贝构造优化为构造

	// 传返回值的优化
	func2().Print();// 传值返回，然后调用临时对象的Print()，把把构造+拷贝构造优化为构造
					// 这里的优化实际上是省去了对象s，直接构造临时对象
					// 临时对象会在调用完Print()就析构
	std::cout << "********";// 加这行是为了显示出临时对象的析构发生在这一行前
	
	return 0;
}