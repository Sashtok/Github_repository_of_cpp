#pragma once
#include<iostream>
#include<cassert>
using namespace std;

class Date
{
public:
	Date();
	Print();
	GetMonthDay();
	operator<();
	operator<=();
	operator>();
	operator>=();
	operator==();
	operator!=();
	operator+=();
	operator+();
	operator-=();
	operator-();
	operator++();
	operator++();
	operator--();
	operator--();
	operator-();
private:
	int _day;
	int _month;
	int _year;
};