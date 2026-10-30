#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v(5, 1);
	std::vector<std::vector<int>> vv(10, v);
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			std::cout << vv[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

//class Solution
//{
//public:
//    void reverse(string& s, size_t left, size_t right)
//    {
//        while (left < right)
//        {
//            swap(s[left++], s[right--]);
//        }
//    }
//    string reverseWords(string s)
//    {
//        size_t begin = 0;
//        size_t end = 0;
//        while (end < s.size())
//        {
//            end = s.find(' ', begin);
//            if (end == string::npos)
//            {
//                reverse(s, begin, s.size() - 1);
//                break;
//            }
//            reverse(s, begin, end - 1);
//            end++;
//            begin = end;
//        }
//        return s;
//    }
//};

//#include<algorithm>
//class Solution
//{
//public:
//    string add(string num1, string num2)
//    {
//        if (num1.empty() || num2.empty())
//        {
//            return num1.empty() ? num2 : num1;
//        }
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1;
//        string res;
//        int c = 0;
//        int t = 0;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int a = end1 >= 0 ? num1[end1--] - '0' : 0;
//            int b = end2 >= 0 ? num2[end2--] - '0' : 0;
//            t = a + b + c;
//            res += (t % 10) + '0';
//            c = t / 10;
//        }
//        if (c)
//        {
//            res += c + '0';
//        }
//        reverse(res.begin(), res.end());
//        return res;
//    }
//    string multiply(string num1, string num2)
//    {
//        if (num1 == "0" || num2 == "0")
//        {
//            return "0";
//        }
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1;
//        string res;
//        int c = 0;
//        while (end2 >= 0)
//        {
//            c = 0;
//            end1 = num1.size() - 1;
//            string temp;
//            while (end1 >= 0)
//            {
//                int t = (num1[end1--] - '0') * (num2[end2] - '0') + c;
//                temp += (t % 10) + '0';
//                c = t / 10;
//            }
//            if (c)
//            {
//                temp += c + '0';
//            }
//            reverse(temp.begin(), temp.end());
//            int k = num2.size() - 1 - end2;
//            while (k--)
//            {
//                temp += '0';
//            }
//            res = add(res, temp);
//            --end2;
//        }
//        return res;
//    }
//};

//namespace Sashtok
//{
//	class string
//	{
//	public:
//		string(const char* str = "")
//		{
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//		void swap(string& s)
//		{
//			std::swap(_str, s._str);
//		}
//		string(const string& s)
//		{
//			string temp(s._str);
//			swap(temp);
//		}
//		string& operator=(string s)
//		{
//			swap(s);
//			return *this;
//		}
//		~string()
//		{
//			delete[] _str;
//		}
//		const char* c_str()
//		{
//			return _str;
//		}
//	private:
//		char* _str = nullptr;
//	};
//}

//class Solution
//{
//public:
//	int singleNumber(vector<int>& nums)
//	{
//		int res = 0;
//		for (auto x : nums)
//		{
//			res ^= x;
//		}
//		return res;
//	}
//};