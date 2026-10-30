#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>

void test1()
{
	std::vector<int> v1(10, 2);

	for (int i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << ' ';
	}
	std::cout << std::endl;

	std::vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;

	for (auto x : v1)
	{
		std::cout << x << ' ';
	}
	std::cout << std::endl;
}

void test2()
{
	std::vector<int> v(10, 2);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;

	v.reserve(20);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;

	v.resize(15, 3);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
}

void test3()
{
	std::vector<std::string> vs;
	vs.push_back("hello");
	for (const auto& s : vs)
	{
		std::cout << s << std::endl;
	}
	
	std::vector<int> v(5, 1);
	std::vector<std::vector<int>> vv(10, v);
	std::cout << vv[2][1] << ' ';
	vv[2][1] = 5;
	std::cout << vv[2][1] << ' ';
}

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}