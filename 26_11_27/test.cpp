#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>

//int main()
//{
//	std::set<int> s;
//	for (int i = 1; i < 10; ++i)
//	{
//		s.insert(i * 10);
//	}
//	for (auto x : s)
//	{
//		std::cout << x << ' ';
//	}
//	std::cout << std::endl;
//
//	// 利用迭代器区间删除一段值，需要左闭右开
//	// 删除[15, 50]
//	auto lowit = s.lower_bound(15);// 返回>=15的值
//	auto upit = s.upper_bound(50);// 返回>50的值
//	s.erase(lowit, upit);
//	for (auto x : s)
//	{
//		std::cout << x << ' ';
//	}
//
//	return 0;
//}

int main()
{
	std::multiset<int> ms = { 1,5,2,6,44,2,3,8,4,1,15,4 };
	for (auto x : ms)
	{
		std::cout << x << ' ';
	}
	std::cout << std::endl;

	// find找的是中序的第一个
	int x = 0;
	std::cin >> x;
	auto it = ms.find(x);
	while (it != ms.end() && *it == x)
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;

	// count会返回x的个数
	std::cout << ms.count(x) << std::endl;

	// erase会把x全部删掉
	ms.erase(x);
	for (auto x : ms)
	{
		std::cout << x << ' ';
	}
	std::cout << std::endl;

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////

//class Solution
//{
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
//	{
//		set<int> s1(nums1.begin(), nums1.end());
//		set<int> s2(nums2.begin(), nums2.end());
//		auto it1 = s1.begin();
//		vector<int> res;
//		while (it1 != s1.end())
//		{
//			auto it2 = s2.begin();
//			while (it2 != s2.end())
//			{
//				if (*it1 == *it2)
//				{
//					res.push_back(*it1);
//				}
//				++it2;
//			}
//			++it1;
//		}
//		return res;
//	}
//};