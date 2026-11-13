#pragma once
#include<iostream>
#include<list>
#include<cassert>
#include<vector>

namespace Sashtok
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _prev;
		list_node<T>* _next;

		list_node(const T& x = T())
			: _data(x)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};
	
	// 如果直接用list_node*作为迭代器，那*是list_node而不是T，++是与之相临的下一个地址，而不是next
	// 所以要单独封装一个类作为迭代器，再利用运算符重载实现迭代器的功能
	/*template<class T>
	struct list_iterator
	{
		typedef list_iterator<T> Self;
		list_node<T>* _node;

		list_iterator(list_node<T>* other)
			: _node(other)
		{}
		T& operator*()
		{
			return _node->_data;
		}
		T* operator->()
		{
			return &(_node->_data);
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self temp = *this;
			_node = _node->_next;
			return temp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self temp = *this;
			_node = _node->_prev;
			return temp;
		}

		bool operator!=(const Self& it) const
		{
			return _node != it._node;
		}
		bool operator==(const Self& it) const
		{
			return _node == it._node;
		}
	};*/

	// 如果要实现const_iterator，可以单独再写一个list_const_iterator类
	// 但官方是多加了两个模板参数来实现的，实际上和写两个类没什么不同
	// 只是把实例化的工作交给编译器完成
	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_iterator<T, Ref, Ptr> Self;
		list_node<T>* _node;

		list_iterator(list_node<T>* other)
			: _node(other)
		{}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &(_node->_data);
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self temp = *this;
			_node = _node->_next;
			return temp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			Self temp = *this;
			_node = _node->_prev;
			return temp;
		}

		bool operator!=(const Self& it) const
		{
			return _node != it._node;
		}
		bool operator==(const Self& it) const
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
	public:
		// typedef也受访问限定符的限制
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}
		const_iterator begin() const
		{
			return _head->_next;
		}
		const_iterator end() const
		{
			return _head;
		}

		void empty_init()
		{
			_head = new list_node<T>;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}
		list()
		{
			empty_init();
		}
		list(const list<T>& li)
		{
			empty_init();
			for (auto& e : li)
			{
				push_back(e);
			}
		}
		list(std::initializer_list<T> il)
		{
			empty_init();
			for (auto& e : il)
			{
				push_back(e);
			}
		}

		void swap(list<T>& li)
		{
			std::swap(_head, li._head);
			std::swap(_size, li._size);
		}
		list<T>& operator=(list<T> li)
		{
			swap(li);
			return *this;
		}

		iterator insert(iterator pos, const T& x)
		{
			list_node<T>* newNode = new list_node<T>(x);
			newNode->_prev = pos._node->_prev;
			newNode->_next = pos._node;
			pos._node->_prev->_next = newNode;
			pos._node->_prev = newNode;
			++_size;
			return pos._node->_prev;
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			list_node<T>* re = pos._node->_next;
			pos._node->_prev->_next = pos._node->_next;
			pos._node->_next->_prev = pos._node->_prev;
			delete pos._node;
			--_size;
			return re;
		}
		void pop_back()
		{
			erase(--end());
		}

		size_t size() const
		{
			return _size;
		}

		bool empty() const
		{
			return _size == 0;
		}

		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
			_size = 0;
		}
	private:
		list_node<T>* _head = nullptr;
		size_t _size = 0;
	};

	struct A
	{
		int _a;
		int _b;
	};

	template<class Container>
	void printContainer(const Container& con)
	{
		// const iterator：迭代器本身不能修改
		// const_iterator：迭代器指向的内容不能修改
		// 所以const_iterator不能用const iterator代替

		// 按需实例化
		//list<int>::const_iterator it = con.begin();
		//while (it != con.end())
		//{
		//	*it *= 10;// 如果没有调用这个函数，那么编译时，这个错误是检查不出来的
		//			  // 源自于这个函数模板未被调用
		//	std::cout << *it << ' ';
		//}
		//std::cout << std::endl;

		typename Container::const_iterator it = con.begin();
		//auto it = con.begin();
		while (it != con.end())
		{
			std::cout << *it << ' ';
			++it;
		}
		std::cout << std::endl;
	}

	void test1()
	{
		list<int> li;
		li.push_back(1);
		li.push_back(2);
		li.push_back(3);
		li.push_back(4);

		auto it = li.begin();
		while (it != li.end())
		{
			std::cout << *it << ' ';
			++it;
		}
		std::cout << std::endl;

		li.pop_back();
		it = li.begin();
		while (it != li.end())
		{
			*it *= 2;
			std::cout << *it << ' ';
			it++;
		}
		std::cout << std::endl;

		list<A> liA;
		liA.push_back(A());
		liA.push_back(A());
		liA.push_back(A());
		liA.push_back(A());
		auto itA = liA.begin();
		while (itA != liA.end())
		{
			// 可以用operator*，也可以重载->
			//std::cout << (*itA)._a << ':' << (*itA)._b << std::endl;
			std::cout << itA->_a << ':' << itA->_b << std::endl;
			// 实际上是两个->，为了可读性，编译器特殊处理，省略了后面的->
			//std::cout << itA.operator->()->_a << ':' << itA.operator->()->_b << std::endl;
			++itA;
		}
		std::cout << std::endl;
	}

	void test2()
	{
		// insert后迭代器不失效
		// erase后失效
		list<int> li;
		li.push_back(1);
		li.push_back(2);
		li.push_back(3);
		li.push_back(4);
		li.push_back(5);
		li.push_back(6);
		printContainer(li);
		auto it = li.begin();
		while (it != li.end())
		{
			if (*it % 2 == 0)
			{
				it = li.erase(it);
			}
			else
			{
				++it;
			}
		}
		printContainer(li);
	}

	void test3()
	{
		list<int> li1;
		li1.push_back(1);
		li1.push_back(2);
		li1.push_back(3);
		li1.push_back(4);
		printContainer(li1);
		list<int> li2 = li1;
		printContainer(li2);
		list<int> li3;
		li3 = li1;
		printContainer(li3);
	}

	void func(std::list<int> li)
	{}

	void test4()
	{
		// cpp11后，支持用初始化列表构造（不是写构造函数时的初始化列表）
		// std::initializer_list是标准库中的一个类模板
		std::initializer_list<int> il({ 1,2,3,4,5 });
		printContainer(il);
		// 这个类会开一块连续的数组，类中有两个指针，一个指向开始位置，一个指向结束位置
		// 官方的list，vector等可以用初始化列表构造
		std::list<int> li1({ 1,2,3,4,5 });
		printContainer(li1);
		std::list<int> li2(il);
		printContainer(li2);
		std::vector<int> v({ 1,2,3,4,5 });
		printContainer(v);
		// 自己的list想实现，需要自己实现一个用初始化列表初始化的构造函数
		const std::list<int>& li3 = { 1,2,3,4,5 };// 隐式类型转换
		printContainer(li3);

		// 有了这个，函数传参会方便一些
		func(li1);
		func({ 1,2,3,4,5 });// 隐式类型转换
		// 这个用法实际上是抄的python
	}
}