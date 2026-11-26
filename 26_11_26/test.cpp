#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
#include<string>

int main()
{
	//std::set<int> s;// 默认是升序+去重
	std::set<int, std::greater<int>> s;// 降序+去重
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(5);
	auto it = s.begin();
	while (it != s.end())
	{
		//*it = 2;// 不可修改
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;

	s.insert({ 1,5,6,1,8,4 });// 传初始化列表
	it = s.begin();
	while (it != s.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;

	std::set<std::string> str = { "aa", "bb", "cc" };// 初始化列表初始化
	auto sit = str.begin();
	while (sit != str.end())
	{
		std::cout << *sit << ' ';
		++sit;
	}
	std::cout << std::endl;

	// erase后认为迭代器失效
	// 可能是野指针
	// 可能是指向的节点的关键字已经改变

	// 官方库的find的时间复杂度是O(n)
	auto pos1 = std::find(s.begin(), s.end(), 1);
	// set自己的find的时间复杂度是O(logN)
	auto pos2 = s.find(1);

	// 如果只想知道某个值存不存在
	// 用count比find更高效
	// count返回值的个数，find返回迭代器
	int x;
	std::cin >> x;
	if (s.count(x))
	{
		std::cout << "存在" << std::endl;
	}
	else
	{
		std::cout << "不存在" << std::endl;
	}

	return 0;
}