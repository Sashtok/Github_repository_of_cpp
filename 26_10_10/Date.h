#pragma once
#include<iostream>
#include<cassert>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& os, const Date& d);
	friend istream& operator>>(istream& is, Date& d);
public:
	Date(int day = 1, int month = 1, int year = 1900);

	bool CheckDate(int day, int month, int year) const
	{
		if (month < 1 || month > 12 || day < 1 || day > GetMonthDay(month, year))
		{
			return false;
		}
		return true;
	}

	void Print() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	int GetMonthDay(int month, int year) const
	{
		assert(month > 0 && month < 13);
		int monthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthDay[month];
	}

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	
	Date& operator+=(int x);
	Date operator+(int x) const;

	Date& operator-=(int x);
	Date operator-(int x) const;

	Date operator++(int);
	Date& operator++();
	Date operator--(int);
	Date& operator--();

	int operator-(const Date& d) const;
private:
	int _day;
	int _month;
	int _year;
};