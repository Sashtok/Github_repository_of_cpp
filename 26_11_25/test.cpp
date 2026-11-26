#define _CRT_SECURE_NO_WARNINGS 1
#include"BinarySearchTree.h"
#include<string>

//int main()
//{
//	key::binary_search_tree<int> t;
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	for (auto x : a)
//	{
//		t.insert(x);
//	}
//	t.inOrder();
//	std::cout << std::endl;
//	
//	std::cout << t.find(1) << ' ' << t.find(0) << std::endl;
//
//	key::binary_search_tree<int> t2 = t;
//	t2.inOrder();
//	std::cout << std::endl;
//	key::binary_search_tree<int> t3;
//	t3 = t;
//	t3.inOrder();
//	std::cout << std::endl;
//
//	for (auto x : a)
//	{
//		t.erase(x);
//		t.inOrder();
//		std::cout << std::endl;
//	}
//
//	return 0;
//}

int main()
{
	//key_value::binary_search_tree<std::string, std::string> dict;
	////key_value::binary_search_tree<std::string, std::string> copy = dict;
	//auto copy = dict;
	//dict.insert("left", "左边");
	//dict.insert("right", "右边");
	//dict.insert("insert", "插入");
	//dict.insert("string", "字符串");

	//std::string str;
	//while (std::cin >> str)
	//{
	//	auto ret = dict.find(str);
	//	if (ret)
	//	{
	//		std::cout << "->" << ret->_val << std::endl;
	//	}
	//	else
	//	{
	//		std::cout << "无此单词，请重新输⼊" << std::endl;
	//	}
	//}

	std::string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	key_value::binary_search_tree<std::string, int> countTree;
	for (const auto& str : arr)
	{
		//key_value::binary_search_tree_node<std::string, int>* ret = countTree.Find(str);
		auto ret = countTree.find(str);
		if (ret == nullptr)
		{
			countTree.insert(str, 1);
		}
		else
		{
			ret->_val++;
		}
	}
	
	countTree.inOrder();

	return 0;
}