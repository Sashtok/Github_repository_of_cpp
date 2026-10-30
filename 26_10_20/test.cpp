#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"

//int main()
//{
//	// 把所有空格替换成 %% 的问题
//	std::string s("hello world hello friend");
//	std::cout << s << std::endl;
//	int pos = s.find(' ');
//	while (pos != std::string::npos)
//	{
//		s.replace(pos, 1, "%%");
//		//pos = s.find(' ');// 这样每次都从头开始找
//		pos = s.find(' ', pos + 2);// 这样就从第二个%的位置继续找
//	}
//	std::cout << s << std::endl;
//	// 但这样平凡挪动数据有效率问题
//	//可以换成下面的方法
//	std::string ss("hello world hello friend");
//	std::cout << ss << std::endl;
//	std::string temp;
//	temp.reserve(ss.size());// 避免频繁扩容
//	for (auto ch : ss)
//	{
//		if (ch == ' ')
//		{
//			temp += "%%";
//		}
//		else
//		{
//			temp += ch;
//		}
//	}
//	std::cout << temp << std::endl;
//	//ss = temp;// 拷贝赋值也有效率问题
//	ss.swap(temp);// 这样的效率更高，swap直接交换两个对象的成员变量 
//	std::cout << ss << std::endl;
//	std::cout << temp << std::endl;
//
//	return 0;
//}

//int main()
//{
//	std::string s("hello world.zip.doc");
//	int pos = s.rfind('.');
//	std::string sub = s.substr(pos);
//	std::cout << s << std::endl;
//	std::cout << sub << std::endl;
//
//	return 0;
//}

namespace Sashtok
{
	void testString1()
	{
		std::cout << "s1:" << std::endl;
		Sashtok::string s1;
		std::cout << s1.c_str() << std::endl;
	}

	void testString2()
	{
		std::cout << "s2:" << std::endl;
		Sashtok::string s2("hello world");
		std::cout << s2.c_str() << std::endl;
		for (int i = 0; i <= s2.size() - 1; ++i)
		{
			s2[i] += 2;
		}
		std::cout << s2.c_str() << std::endl;

		// 迭代器是一种封装的体现，提供了统一的类似的访问容器的方式
		// 不需要关心容器底层结构和实现细节
		Sashtok::string::iterator it = s2.begin();
		while (it != s2.end())
		{
			*it -= 2;
			++it;
		}
		std::cout << s2.c_str() << std::endl;

		for (auto ch : s2)
		{
			std::cout << ch << ' ';
		}
		std::cout << std::endl;
	}

	void testString3()
	{
		std::cout << "s3:" << std::endl;
		Sashtok::string s3("hello world");
		std::cout << s3.c_str() << std::endl;
		s3.push_back('*');
		std::cout << s3.c_str() << std::endl;
		s3 += '$';
		std::cout << s3.c_str() << std::endl;
		s3.append("hello cpp");
		std::cout << s3.c_str() << std::endl;
		s3 += "&come on";
		std::cout << s3.c_str() << std::endl;
		s3.insert(11, '@');
		std::cout << s3.c_str() << std::endl;
	}

	void testString4()
	{
		string s1("hello");
		std::cout << s1.c_str() << std::endl;
		s1.insert(0, "haha");
		std::cout << s1.c_str() << std::endl;
		s1.insert(5, "haha");
		std::cout << s1.c_str() << std::endl;
		s1.insert(2, "haha");
		std::cout << s1.c_str() << std::endl;
	}

	void testString5()
	{
		string s1("hello world");
		std::cout << s1.c_str() << std::endl;
		s1.erase(1, 2);
		std::cout << s1.c_str() << std::endl;

		/*string s2("hello world");
		std::cout << s2.c_str() << std::endl;
		s2.erase(s2.find('h'), 1);
		std::cout << s2.c_str() << std::endl;*/

		string s2("hello world");
		string s3 = s2.substr(s2.find('e'), 2);
		std::cout << s3.c_str() << std::endl;

		string s4("hello");
		string s5("hello");
		std::cout << (s4 < s5) << std::endl;

		// 这个能比较是因为常量字符串被识别为指针，const char*，这里比较的是指针,输出为1
		//std::cout << ("hello" == "hello") << std::endl;
	}

	void testString6()
	{
		string s("hello");
		std::cin >> s;
		std::cout << s << std::endl;
	}
	
	void testString7()
	{
		string s1("hello world");
		std::cout << s1 << std::endl;
		string s2 = s1;
		std::cout << s2 << std::endl;

		string s3("haha");
		std::cout << s3 << std::endl;
		s3 = s2;
		std::cout << s3 << std::endl;
	}
}

int main()
{
	//Sashtok::testString1();
	//Sashtok::testString2();
	//Sashtok::testString3();
	//Sashtok::testString4();
	//Sashtok::testString5();
	//Sashtok::testString6();
	Sashtok::testString7();

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// 题目
//class Solution
//{
//public:
//    void Reverse(string& s)
//    {
//        int begin = 0;
//        int end = s.size() - 1;
//        while (begin < end)
//        {
//            swap(s[begin++], s[end--]);
//        }
//    }
//    string addStrings(string num1, string num2)
//    {
//        string res;
//        string::reverse_iterator rit1 = num1.rbegin();
//        string::reverse_iterator rit2 = num2.rbegin();
//        int C = 0;
//        while (rit1 != num1.rend() && rit2 != num2.rend())
//        {
//            int x = *rit1 + *rit2 + C - 2 * '0';
//            C = x / 10;
//            x %= 10;
//            res.push_back(x + '0');
//            ++rit1;
//            ++rit2;
//        }
//        while (rit1 != num1.rend())
//        {
//            int x = *rit1 + C - '0';
//            C = x / 10;
//            x %= 10;
//            res.push_back(x + '0');
//            ++rit1;
//        }
//        while (rit2 != num2.rend())
//        {
//            int x = *rit2 + C - '0';
//            C = x / 10;
//            x %= 10;
//            res.push_back(x + '0');
//            ++rit2;
//        }
//        if (C == 1)
//        {
//            res.push_back('1');
//        }
//        Reverse(res);
//        return res;
//    }
//};

//#include<iostream>
//using namespace std;
//
//int a1[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//int a2[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//class Date
//{
//public:
//    bool IsLeap()
//    {
//        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
//    }
//    Date& operator++()
//    {
//        ++day;
//        if (IsLeap())
//        {
//            if (day > a2[month])
//            {
//                day = 1;
//                month++;
//                if (month > 12)
//                {
//                    month = 1;
//                    year++;
//                }
//            }
//        }
//        else
//        {
//            if (day > a1[month])
//            {
//                day = 1;
//                month++;
//                if (month > 12)
//                {
//                    month = 1;
//                    year++;
//                }
//            }
//        }
//        return *this;
//    }
//    bool operator==(Date& d)
//    {
//        return year == d.year && month == d.month && day == d.day;
//    }
//    bool operator<(Date& d)
//    {
//        if (year < d.year)
//        {
//            return true;
//        }
//        else if (year == d.year)
//        {
//            if (month < d.month)
//            {
//                return true;
//            }
//            else if (month == d.month)
//            {
//                if (day < d.day)
//                {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//    int year = 0;
//    int month = 0;
//    int day = 0;
//};
//
//int main()
//{
//    int x1 = 0;
//    int x2 = 0;
//    while (scanf("%d %d", &x1, &x2) == 2)
//    {
//        Date d1;
//        Date d2;
//        d1.day = x1 % 100;
//        x1 /= 100;
//        d1.month = x1 % 100;
//        x1 /= 100;
//        d1.year = x1;
//        d2.day = x2 % 100;
//        x2 /= 100;
//        d2.month = x2 % 100;
//        x2 /= 100;
//        d2.year = x2;
//        int res = 0;
//        if (d1 < d2)
//        {
//            while (!(d1 == d2))
//            {
//                res++;
//                ++d1;
//            }
//        }
//        else
//        {
//            while (!(d1 == d2))
//            {
//                res++;
//                ++d2;
//            }
//        }
//        cout << res + 1 << endl;
//    }
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int a1[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    int a2[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
//    int year;
//    int month;
//    int day;
//    cin >> year >> month >> day;
//    int res = 0;
//    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
//    {
//        for (int i = 1; i < month; ++i)
//        {
//            res += a2[i];
//        }
//    }
//    else
//    {
//        for (int i = 1; i < month; ++i)
//        {
//            res += a1[i];
//        }
//    }
//    cout << res + day;
//    return 0;
//}

//#include <climits>
//#include <iostream>
//#include<iomanip>
//using namespace std;
//
//class Date
//{
//    friend istream& operator>>(istream& is, Date& d);
//    friend ostream& operator<<(ostream& os, Date& d);
//public:
//    bool isLeap()
//    {
//        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
//    }
//    int getMonthDay()
//    {
//        int monthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//        if (month == 2 && isLeap())
//        {
//            return 29;
//        }
//        return monthDay[month];
//    }
//    Date& operator++()
//    {
//        day++;
//        if (day > getMonthDay())
//        {
//            day = 1;
//            month++;
//            if (month > 12)
//            {
//                month = 1;
//                year++;
//            }
//        }
//        return *this;
//    }
//    Date operator+(int n)
//    {
//        Date temp = *this;
//        while (n--)
//        {
//            ++temp;
//        }
//        return temp;
//    }
//private:
//    int year;
//    int month;
//    int day;
//};
//
//istream& operator>>(istream& is, Date& d)
//{
//    is >> d.year >> d.month >> d.day;
//    return is;
//}
//
//ostream& operator<<(ostream& os, Date& d)
//{
//    os << d.year << '-' << setw(2) << setfill('0') << d.month << '-' << setw(2) << setfill('0') << d.day;
//    return os;
//}
//
//int main()
//{
//    int m = 0;
//    cin >> m;
//    while (m--)
//    {
//        Date d;
//        int n = 0;
//        cin >> d >> n;
//        Date temp = d + n;
//        cout << temp << endl;
//    }
//    return 0;
//}

//#include <iostream>
//#include<iomanip>
//using namespace std;
//
//class Date
//{
//    friend istream& operator>>(istream& is, Date& d);
//    friend ostream& operator<<(ostream& os, Date& d);
//public:
//    bool isLeap()
//    {
//        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
//    }
//    int getMonthDay()
//    {
//        int monthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//        if (month == 2 && isLeap())
//        {
//            return 29;
//        }
//        return monthDay[month];
//    }
//    Date& operator++()
//    {
//        day++;
//        if (day > getMonthDay())
//        {
//            day = 1;
//            month++;
//            if (month > 12)
//            {
//                month = 1;
//                year++;
//            }
//        }
//        return *this;
//    }
//    Date operator+(int n)
//    {
//        Date temp = *this;
//        while (n--)
//        {
//            ++temp;
//        }
//        return temp;
//    }
//    void setYear(int y)
//    {
//        year = y;
//    }
//private:
//    int year = 0;
//    int month = 1;
//    int day = 0;
//};
//
//istream& operator>>(istream& is, Date& d)
//{
//    is >> d.year >> d.month >> d.day;
//    return is;
//}
//
//ostream& operator<<(ostream& os, Date& d)
//{
//    os << d.year << '-' << setw(2) << setfill('0') << d.month << '-' << setw(2) << setfill('0') << d.day;
//    return os;
//}
//
//int main()
//{
//    int y = 0;
//    int n = 0;
//    while (scanf("%d %d", &y, &n) == 2)
//    {
//        Date d;
//        d.setYear(y);
//        while (n--)
//        {
//            ++d;
//        }
//        cout << d << endl;
//    }
//    return 0;
//}

//#include<algorithm>
//class Solution
//{
//public:
//    string addStrings(string num1, string num2)
//    {
//        string res;
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1;
//        int C = 0;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int res1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//            int res2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//            int x = res1 + res2 + C;
//            C = x / 10;
//            x %= 10;
//            res += (x + '0');
//        }
//        if (C == 1)
//        {
//            res += '1';
//        }
//        reverse(res.begin(), res.end());
//        return res;
//    }
//};

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    string s;
//    getline(cin, s);
//    int pos = s.rfind(' ');
//    if (pos == string::npos)
//    {
//        cout << s.size() << endl;
//    }
//    else
//    {
//        cout << s.size() - pos - 1 << endl;
//    }
//    return 0;
//}