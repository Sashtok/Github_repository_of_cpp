#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

int main()
{

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

//class Solution
//{
//public:
//    int myAtoi(string str)
//    {
//        int pos = str.find_first_not_of(' ');
//        if (pos == string::npos)
//        {
//            return 0;
//        }
//        int sign = 1;
//        if (str[pos] == '-')
//        {
//            sign = -1;
//            pos++;
//        }
//        else if (str[pos] == '+')
//        {
//            pos++;
//        }
//        while (str[pos] == '0')
//        {
//            ++pos;
//        }
//        int i = pos;
//        while (i < str.size())
//        {
//            if (str[i] < '0' || str[i] > '9')
//            {
//                break;
//            }
//            ++i;
//        }
//        if (i == pos)
//        {
//            return 0;
//        }
//        string res = str.substr(pos, i - pos);
//        string max("2147483647");
//        string min("2147483648");
//        if (sign == 1 && res.size() >= max.size())
//        {
//            if ((res.size() > max.size()) || (res.size() == max.size() && res >= max))
//            {
//                return 2147483647;
//            }
//        }
//        if (sign == -1 && res.size() >= min.size())
//        {
//            if ((res.size() > min.size()) || (res.size() == min.size() && res >= min))
//            {
//                return -2147483648;
//            }
//        }
//        int r = 0;
//        for (int i = 0; i < res.size(); ++i)
//        {
//            int x = res[i] - '0';
//            r = r * 10 + x;
//        }
//        return r * sign;
//    }
//};

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

//class Solution
//{
//public:
//    void reverseString(vector<char>& s)
//    {
//        int left = 0;
//        int right = s.size() - 1;
//        while (left < right)
//        {
//            swap(s[left++], s[right--]);
//        }
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

//class Solution
//{
//public:
//    bool is_right(char ch)
//    {
//        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
//    }
//    bool isPalindrome(string s)
//    {
//        int left = 0;
//        int right = s.size() - 1;
//        while (left < right)
//        {
//            while (left < s.size() && !is_right(s[left]))
//            {
//                ++left;
//            }
//            while (right > 0 && !is_right(s[right]))
//            {
//                --right;
//            }
//            if (s[left] >= 'A' && s[left] <= 'Z')
//            {
//                s[left] += ('a' - 'A');
//            }
//            if (s[right] >= 'A' && s[right] <= 'Z')
//            {
//                s[right] += ('a' - 'A');
//            }
//            if (left < right && s[left] != s[right])
//            {
//                return false;
//            }
//            left++;
//            right--;
//        }
//        return true;
//    }
//};

//class Solution
//{
//public:
//    void reverse(string& s, int left, int right)
//    {
//        while (left < right)
//        {
//            swap(s[left++], s[right--]);
//        }
//    }
//    string reverseStr(string s, int k)
//    {
//        int count = 2 * k;
//        int left = 0;
//        int right = 0;
//        while (right < s.size())
//        {
//            while (count-- && right < s.size())
//            {
//                right++;
//            }
//            if (count == -1)
//            {
//                reverse(s, left, left + k - 1);
//                left = right;
//                count = 2 * k;
//            }
//        }
//        if (s.size() - left < k)
//        {
//            reverse(s, left, s.size() - 1);
//        }
//        else
//        {
//            reverse(s, left, left + k - 1);
//        }
//        return s;
//    }
//};