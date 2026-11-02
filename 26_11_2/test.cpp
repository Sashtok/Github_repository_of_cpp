#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>

int main()
{
	// 迭代器根据功能分为4种：
	// iterator
	// const_iterator
	// reverse_iterator
	// const_reverse_iterator

	// 根据性质分为3种：（和底层结构有关）
	// 单向迭代器：forward_list/unordered_map/unordered_set...   只支持++
	// 双向迭代器：list/map/set...   只支持++/--
	// 随机（访问）迭代器：vector/string/deque...   支持++/--/+/-
	// 迭代器的性质决定了可以使用哪些算法

	return 0;
}