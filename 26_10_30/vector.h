#pragma once
#include<iostream>
#include<cassert>
#include<vector>

// 模板不能分离到两个文件
namespace Sashtok
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		typedef const T* const_iterator;
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				iterator temp = new T[n];
				memcpy(temp, _start, old_size * sizeof(T));
				delete[] _start;
				_start = temp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}
		
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*_finish = x;
			++_finish;
		}
		
		T& operator[](size_t pos)
		{
			assert(pos >= 0 && pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			assert(pos >= 0 && pos < size());
			return _start[pos];
		}
		
		bool empty() const
		{
			return _start == _finish;
		}
		void pop_back()
		{
			if (!empty())
			{
				--_finish;
			}
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish)
			if (_finish == _end_of_storage)
			{
				// 修正pos
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}
			iterator end = _finish;
			while (end != pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		//void insert(iterator pos, const T& x)
		//{
		//	// 第一种迭代器失效：类似野指针
		//	// 如果这里扩容了，那么pos还指向原来开辟的空间，但_finish之类的已经指向其他地址
		//	// 一般是比原来更大的地址，那么end就会一直 -- ，直到越界
		//	if (_finish == _end_of_storage)
		//	{
		//		reserve(capacity() == 0 ? 4 : 2 * capacity());
		//	}
		//	iterator end = _finish;
		//	while (end > pos)
		//	{
		//		*end = *(end - 1);
		//		--end;
		//	}
		//	*pos = x;
		//	++_finish;
		//}

		erase();
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
	
	template<class T>
	void print_vector(const vector<T> v)
	{
		auto it = v.begin();
		while (it != v.end())
		{
			std::cout << *it << ' ';
			++it;
		}
		std::cout << std::endl;

		for (auto& x : v)
		{
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	//void print_vector(const vector<int>& v)
	//{
	//	// 错误一
	//	//vector<int>::iterator it = v.begin();// const对象不能调用非const成员函数
	//										 // 需要实现const_iterator，以及对应的begin()，end()
	//	// 错误二
	//	//vector<int>::iterator it = v.begin();// 如果已经实现了const_iterator，以及对应的begin()，end()
	//										 // 那么原因是const_iterator不能赋值给iterator
	//	// 正确
	//	vector<int>::const_iterator it = v.begin();
	//	while (it != v.end())
	//	{
	//		std::cout << *it << ' ';
	//		++it;
	//	}
	//	std::cout << std::endl;
	//
	//	for (auto x : v)// 范围for底层也是用iterator，因为v是const对象，不能调用非const成员函数
	//					// 需要实现const_iterator，以及对应的begin()，end()
	//	{
	//		std::cout << x << ' ';
	//	}
	//	std::cout << std::endl;
	//}

	//template<class T>
	//void print_vector(const vector<T>& v)
	//{
	//	//vector<T>::const_iterator it = v.begin();// 这里编译时会报错，报未加 ;
	//	// 这是因为vector<T>没有实例化
	//	// 而vector<T>:: 可能会取到类型，也可能取到静态成员变量
	//	// 编译器无法区分
	//	// 规定：不能去未实例化的模板里取东西
	//	// 如果是静态成员变量，就是如下写法，也就是编译器认为的没加 ;
	//	//vector<T>::const_iterator;
	//	//it = v.begin();
	//
	//	typename vector<T>::const_iterator it = v.begin();// 所以需要加一个typename说明是类型
	//	//auto it = v.begin();// 写成auto更简单，通过begin()确定类型
	//	while (it != v.end())
	//	{
	//		std::cout << *it << ' ';
	//		++it;
	//	}
	//	std::cout << std::endl;
	//
	//	for (auto x : v)
	//	{
	//		std::cout << x << ' ';
	//	}
	//	std::cout << std::endl;
	//}

	template<class T>
	void print_Container(const T& v)
	{
		auto it = v.begin();
		while (it != v.end())
		{
			std::cout << *it << ' ';
			++it;
		}
		std::cout << std::endl;

		for (auto& x : v)
		{
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	void test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		for (int i = 0; i < v.size(); ++i)
		{
			std::cout << v[i] << ' ';
		}
		std::cout << std::endl;
		print_vector(v);
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();
		print_vector(v);
	}

	void test2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		print_vector(v);
		/*v.insert(v.begin() + 2, 40);
		print_vector(v);*/

		size_t x = 0;
		std::cin >> x;
		auto p = std::find(v.begin(), v.end(), x);
		if (p != v.end())
		{
			//v.insert(p, 40);
			// 第二种迭代器失效：位置的意义变了
			//*p *= 10;
			// 1.本来想改变原来p位置的值，但是改变的却是新插入的值，因为原来的值已经挪走了
			// 2.此外，如果insert进行了扩容，那么p指向的是原来的空间，这里解引用就是越界访问
			//   那么，我已经在insert里修正了pos，为什么p没变呢？
			//   因为是传值传参，修改形参不影响实参
			// 那么，改成void insert(iterator& pos, const T& x)可以吗？
			// 虽然这里可以，但是会导致下面的操作报错
			//vector<int> v;
			//insert(v.begin() + 2, 30);
			// v.begin() + 2 返回的是临时对象，具有常性，传给iterator& pos就是权限放大
			// 那么，改成void insert(const iterator& pos, const T& x)可以吗？
			// 不行，改成这样，还怎么修正pos呢
			// 总之，insert后，p就失效了，不要再直接访问p了
			
			// 在官方的STL中，vector的insert的解决方案是，返回新插入的值的迭代器
			// iterator insert(iterator & pos, const T & x)
			p = v.insert(p, 40);// 这样把p更新后，就可以访问了
			*(p + 1) *= 10;
		}
		print_vector(v); 

		// 如果是用vs下的STL的vector，会强制检查
		std::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		print_Container(v1);

		size_t x1 = 0;
		std::cin >> x1;
		auto p1 = std::find(v1.begin(), v1.end(), x1);
		if (p1 != v1.end())
		{
			v1.insert(p1, 40);
			*p1 *= 10;// 这里不论是否扩容，程序都会崩溃
		}
		print_Container(v1);
	}
}