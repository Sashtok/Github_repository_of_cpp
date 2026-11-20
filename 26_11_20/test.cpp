#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

class A
{
public:
	A(int a = 0)
		: _a(a)
	{}
	bool operator<(const A& other) const
	{
		return _a < other._a;
	}
private:
	int _a;
};

//template<class T>
//bool less(T x, T y)
//{
//	return x < y;
//}
//
//// 模板的特化
//template<>
//bool less<A*>(A* x, A* y)
//{
//	return *x < *y;
//}

// 但一般是写成这样
template<class T>
bool less(const T& x, const T& y)
{
	return x < y;
}

// 模板的特化需要这样写
template<>
//bool less<A*>(const A*& x, const A*& y)// 这样不对，因为模板的const修饰的是x
										 // 这样修饰的是x指向的内容
//bool less(T const& x, T const& y)// 因为对于一般的类型而言，const在前和1后都可以
								   // 所以把模板写成这样更容易对应
bool less<A*>(A* const& x, A* const& y)// A*是T
{
	return *x < *y;
}

// 第二个特化
template<>
bool less<const A*>(const A* const& x, const A* const& y)// const A*是T
{
	return *x < *y;
}

// 所以推荐单独写一个函数，此函数和特化的模板可以同时存在，调用时会调用这个函数
bool less(A* x, A* y)
{
	return *x < *y;
}
bool less(const A* x, const A* y)
{
	return *x < *y;
}

int main()
{
	std::cout << less(1, 2) << std::endl;// 能正确比较
	std::cout << less(A(1), A(2)) << std::endl;// 能正确比较
	A a1(1);
	A a2(2);
	std::cout << less(&a1, &a2) << std::endl;// 如果不特化，比较的是地址，不能正确比较
	const A* p1 = &a1;
	const A* p2 = &a2;
	std::cout << less(p1, p2) << std::endl;// 如果再加上const指针，就不会走上面的特化了
										   // 需要再写一个特化

	return 0;
}