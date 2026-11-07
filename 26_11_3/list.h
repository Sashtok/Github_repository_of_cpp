#pragma once
#include<iostream>
#include<list>
#include<cassert>

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
	template<class T>
	struct list_iterator
	{
		typedef list_iterator<T> Self;
		list_node<T>* _node;

		list_iterator(list_node<T>* other)
			: _node(other)
		{}
		T& operator*() const
		{
			return _node->_data;
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
		Self operator--()
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
		typedef list_iterator<T> iterator;
		iterator begin()
		{
			return _head->_next;
		}
		iterator end()
		{
			return _head;
		}

		list()
		{
			_head = new list_node<T>;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}


		void insert(iterator pos, const T& x)
		{
			list_node<T>* newNode = new list_node<T>(x);
			newNode->_prev = pos._node->_prev;
			newNode->_next = pos._node;
			pos._node->_prev->_next = newNode;
			pos._node->_prev = newNode;
			++_size;
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void erase(iterator pos)
		{
			assert(pos != end());
			pos._node->_prev->_next = pos._node->_next;
			pos._node->_next->_prev = pos._node->_prev;
			delete pos._node;
			--_size;
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

		
	private:
		list_node<T>* _head = nullptr;
		size_t _size = 0;
	};

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
	}
}