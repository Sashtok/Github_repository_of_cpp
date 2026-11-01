#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"

int main()
{
	//Sashtok::test1();
	//Sashtok::test2();
	//Sashtok::test3();
	//Sashtok::test4();
	//Sashtok::test5();
	//Sashtok::test6();
	Sashtok::test7();

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

//class Solution
//{
//public:
//    vector<vector<int>> generate(int numRows)
//    {
//        vector<vector<int>> vv(numRows);
//        for (int i = 0; i < vv.size(); ++i)
//        {
//            vv[i].resize(i + 1, 1);
//        }
//        for (int i = 2; i < vv.size(); ++i)
//        {
//            for (int j = 1; j < vv[i].size() - 1; ++j)
//            {
//                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//            }
//        }
//        return vv;
//    }
//};

//class Solution
//{
//public:
//    vector<int> singleNumber(vector<int>& nums)
//    {
//        vector<int> v(2);
//        int res = 0;
//        for (auto x : nums)
//        {
//            res ^= x;
//        }
//        size_t flag = 1;
//        for (int i = 0; i < 32; ++i)
//        {
//            if ((flag & res) == flag)
//            {
//                break;
//            }
//            flag *= 2;
//        }
//        int temp = res;
//        for (auto x : nums)
//        {
//            if ((flag & x) == flag)
//            {
//                temp ^= x;
//            }
//        }
//        v[0] = temp;
//        v[1] = temp ^ res;
//        return v;
//    }
//};

//class Solution
//{
//public:
//    int singleNumber(vector<int>& nums)
//    {
//        size_t res = 0;
//        for (int i = 0; i < 32; ++i)
//        {
//            int num = 0;
//            for (size_t x : nums)
//            {
//                if (((x >> i) & 1) == 1)
//                {
//                    ++num;
//                }
//            }
//            if (num % 3 != 0)
//            {
//                size_t x = 1;
//                res += (x << i);
//            }
//        }
//        return (int)res;
//    }
//};