#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<array>

// bool，char也是整形家族
template<size_t N = 10, bool flag = true>
class A
{
private:
	int _A[N];
};

// cpp20后支持
//template<double N>
//class B
//{
//};

//int main()
//{
//	A<> a1;
//	//A a1;// cpp20后支持，但还是推荐上面的写法，因为是向前兼容的
//	A<5> a2;
//
//	return 0;
//}

int main()
{
	// 非类型参数的用处：array类

	// 对于越界检查
	// 静态数组是抽查
	// 越界读不检查
	// 越界写是抽查，比如有两个标志位，运行结束后检查标志位是否被改变
	int a1[10];
	std::cout << a1[20] << std::endl;// 不会报错
	//a1[10] = 1;// 会检查出来
	//a1[20] = 1;// 不会检查出来

	// 类array越界读写都可以检查
	std::array<int, 5> a2;

	// 本来array是要代替静态数组的，但是vector更好用
	// 二者区别是array的数据在栈上，vector的数据在堆上
	// 在栈上开空间比在堆上效率高

	return 0;
}