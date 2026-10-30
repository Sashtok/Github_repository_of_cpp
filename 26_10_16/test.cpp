#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

template<class T>
T* func(int n)
{
	return new T[n];
}

int main()
{
	// 一般模板不需要显式实例化
	// 但也有必须显式实例化的
	// double* d = func(10);// 这样会报错，因为不知道T是啥类型
	double* d = func<double>(10);

	return 0;
}