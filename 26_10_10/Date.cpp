#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

Date::Date(int day, int month, int year)
{
	if(!CheckDate(day, month, year))
	{
		cout << "illegal";
	}
	_day = day;
	_month = month;
	_year = year;
}

bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else
	{
		if (_year == d._year && _month < d._month)
		{
			return true;
		}
		else
		{
			if (_year == d._year && _month == d._month && _day < d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator==(const Date& d) const
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d) const
{
	return !(*this < d) && !(*this == d);
}

bool Date::operator>=(const Date& d) const
{
	return *this > d || *this == d;
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

Date& Date::operator+=(int x)
{
	if (x < 0)
	{
		return *this -= -x;
	}
	_day += x;
	while (_day > GetMonthDay(_month, _year))
	{
		_day -= GetMonthDay(_month, _year);
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator+(int x) const
{
	Date temp = *this;
	temp += x;
	return temp;
}

Date& Date::operator-=(int x)
{
	if (x < 0)
	{
		return *this += -x;
	}
	_day -= x;
	while (_day <= 0)
	{
		_month--;
		if (_month <= 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_month, _year);
	}
	return *this;
}

Date Date::operator-(int x) const
{
	Date temp = *this;
	temp -= x;
	return temp;
}

Date Date::operator++(int)
{
	Date temp = *this;
	*this += 1;
	return temp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator--(int)
{
	Date temp = *this;
	*this -= 1;
	return temp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

int Date::operator-(const Date& d) const
{
	bool flag = false;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = true;
	}
	int gap = 0;
	while (min != max)
	{
		min++;
		gap++;
	}
	if (flag)
	{
		gap *= -1;
	}
	return gap;
}

ostream& operator<<(ostream& os, const Date& d)
{
	os << d._year << "-" << d._month << "-" << d._day;
	return os;
}

istream& operator>>(istream& is, Date& d)
{
	while (1)
	{
		is >> d._year >> d._month >> d._day;
		if (d.CheckDate(d._day, d._month, d._year))
		{
			break;
		}
	}
	return is;
}