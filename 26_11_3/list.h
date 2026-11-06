#pragma once
#include<iostream>
#include<list>

namespace Sashtok
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _prev;
		list_node<T>* _next;

		list_node();
	};
	
	struct list_iterator
	{

		list_iterator();
		operator*();
		operator++();
		operator!=();
	};

	template<class T>
	class list
	{
	public:

		begin();
		end();

		list()
		{

		}

		void push_back(T& x)
		{

		}

		size_t size()
		{
			return _size;
		}

		bool empty()
		{
			return _size == 0;
		}
	private:
		list_node<T>* _head = nullptr;
		size_t _size = 0;
	};
}