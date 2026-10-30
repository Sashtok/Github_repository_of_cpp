#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

////void func1(auto a) // 会报错
////{}
//
//auto func2()
//{
//	return 3;
//}
//
//int main()
//{
//	std::string s1;
//	std::string s2 = "hellow world";
//	std::cout << s2 << std::endl;// string重载了流插入和流提取运算符
//
//	// 三种遍历方法（没什么区别）
//	// 1.[]运算符重载
//	for (int i = 0; i < s2.size(); ++i)
//	{
//		std::cout << s2[i] << " ";
//	}
//	std::cout << std::endl;
//
//	// 2.迭代器（迭代器是像指针一样的东西，但不是所有迭代器都是用指针实现的）
//	std::string::iterator it2 = s2.begin();
//	while (it2 != s2.end())
//	{
//		std::cout << *it2 << " ";
//		++it2;
//	}
//	std::cout << std::endl;
//
//	// 3.范围for（所有容器都支持范围for，因为底层是迭代器，所有容器都支持迭代器）
//	// 自动赋值，自动迭代，自动判断结束
//	for (auto c : s2)// auto是一个关键字，用来自动推导类型，写成 char c : s2 也行
//	{
//		std::cout << c << " ";
//	}
//	std::cout << std::endl;
//
//	// 但是范围for有个坑
//	std::string s3 = "hellow world";
//	std::string::iterator it3 = s3.begin();
//	while (it3 != s3.end())
//	{
//		*it3 += 2;// 这里修改字符串的值
//		std::cout << *it3 << " ";
//		++it3;
//	}
//	std::cout << std::endl;
//
//	for (auto c : s3)
//	{
//		c -= 2;// 这里让字符串的值变回来
//		std::cout << c << " ";
//	}
//	std::cout << std::endl;
//	std::cout << s3 << std::endl;// 但是这里打印出来发现并没有变回去
//	// 因为范围for实际上是把*it的值赋值给c，c只是一份临时拷贝
//	// 想能够修改，需要写成引用
//	for (auto& c : s3)// 
//	{
//		c -= 2;// 这里让字符串的值变回来
//		std::cout << c << " ";
//	}
//	std::cout << std::endl;
//	std::cout << s3 << std::endl;
//
////////////////////////////////////////////////////////////////////////////////////////////
//
//	// auto可以用来简化代码，就比如下面这一长串
//	std::string::iterator it4 = s3.begin();
//	auto it5 = s3.begin();// 可以写成这样
//
//	// auto必须有初始值设定项
//	//auto a;// 会报错
//
//	// auto不能定义数组
//	//auto arr[] = { 0 };// 会报错
//
//	// auto不能做函数参数，给缺省值也不行
//	//func1();
//
//	// auto可以做返回值
//	auto b = func2();
//	// 虽然func2返回的是什么类型，b就是什么类型
//	// 但是func2有可能返回的是func3的值，而func3有可能返回的是func4的值......
//	// 这样的话，想知道b是什么类型就很麻烦了
//	// 实际上auto做返回值的用法是抄的python的
//
////////////////////////////////////////////////////////////////////////////////////////////
//
//	// 范围for适用于容器和数组
//	int arr[] = { 1,2,3,4,5,6,7 };
//	for (auto& x : arr)
//	{
//		x *= 2;
//	}
//	for (auto x : arr)
//	{
//		std::cout << x;
//	}
//
//	return 0;
//}

//int main()
//{
//	std::string s1 = "hello world";
//
//	// 正向迭代器
//	std::string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		std::cout << *it << " ";
//		++it;
//	}
//	std::cout << std::endl;
//
//	// 反向迭代器（一定不是指针）
//	std::string::reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		std::cout << *rit << " ";
//		++rit;// 也是++
//	}
//	std::cout << std::endl;
//	// 迭代器的begin、rbegin都是指向第一个有效字符（只不过反向迭代器是倒着走的）
//	// end、rend都是指向最后一个有效元素的下一个位置
//
//	const std::string s2 = "hello world";
//
//	// const迭代器
//	//std::string::const_iterator cit = s2.begin();
//	auto cit = s2.begin();// 用auto更方便
//	while (cit != s2.end())
//	{
//		std::cout << *cit << " ";
//		++cit;
//	}
//	std::cout << std::endl;
//
//	// const反向迭代器
//	//std::string::const_reverse_iterator crit = s2.rbegin();
//	auto crit = s2.rbegin();
//	while (crit != s2.rend())
//	{
//		std::cout << *crit << " ";
//		++crit;
//	}
//	std::cout << std::endl;
//	// begin、rbegin、end、rend都有重载const和非const的
//
//	return 0;
//}

int main()
{
	std::string s;

	std::cout << s.capacity() << std::endl;// 得到容量，但是会比实际容量少1，因为要存'\0'
	// 这里得到的容量是15，原因如下
	// 不同的编译器对于string的扩容方案不同
	// 比如微软的是长度小于16，就放在一个容量为16的buff数组里
	// 大于16后，就用 new 存到堆上，第一次扩容是 *2，后面是 *1.5
	// 而linux的g++的string没有buff数组，容量是从0开始，每次都 *2

	// 提前开空间，避免扩容
	s.reserve(100);// 开100的空间
	// 一般说到string的容量，都不包含'\0'，也就是实际要开101的空间
	std::cout << s.capacity() << std::endl;// 这里发现容量是111，是因为VS会做一个整数倍对齐
	// 而g++就会刚好开100的空间

	// 当传给reserve的值小于当前容量时，reserve在保证不改变原字符串的基础上
	// （也就是容量不小于有效长度，也不改变字符串内容）
	// 是否缩容是不确定的

	s.clear();// 清除数据，但是一般不清容量
	std::cout << s.size() << std::endl;
	std::cout << s.capacity() << std::endl;

	return 0;
}

//class Solution
//{
//public:
//    string reverseOnlyLetters(string s)
//    {
//        int left = 0;
//        int right = s.size() - 1;
//        while (left < right)
//        {
//            while ((s[left] < 'A' || (s[left] > 'Z' && s[left] < 'a') || s[left] > 'z') && left < right)
//            {
//                ++left;
//            }
//            while ((s[right] < 'A' || (s[right] > 'Z' && s[right] < 'a') || s[right] > 'z') && left < right)
//            {
//                --right;
//            }
//            std::swap(s[left], s[right]);
//            ++left;
//            --right;
//        }
//        return s;
//    }
//};

//class Solution
//{
//public:
//    int firstUniqChar(string s)
//    {
//        int count[26];
//        string::iterator it = s.begin();
//        while (it != s.end())
//        {
//            ++count[(int)(*it - 'a')];
//            ++it;
//        }
//        it = s.begin();
//        int i = 0;
//        while (it != s.end())
//        {
//            if (count[(int)(*it - 'a')] == 1)
//            {
//                return i;
//            }
//            ++i;
//            ++it;
//        }
//        return -1;
//    }
//};