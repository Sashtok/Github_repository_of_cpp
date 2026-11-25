#pragma once
#include<iostream>

// 声明
template<class T>
void func1(const T& x);

// 声明+定义
//template<class T>
//void func1(const T& x)
//{
//	std::cout << "func1(const T& x)" << std::endl;
//}

// 声明
void func2(const int& x);