#pragma once
#include<iostream>
#include<cassert>
#include<vector>
#include<string>
#include<list>

// 模板不能分离到两个文件
namespace Sashtok
{
	template<class T>
	class vector
	{
	public:
		// 无参构造
		//vector()
		//{}
		// cpp11后也可以写成这样
		vector() = default;

		// 拷贝构造
		// 类内可以用类名替代类型，类外不行
		vector(const vector<T>& v)// 写成vector(const vector& v)也行
		{
			reserve(v.size());
			for (auto& x: v)
			{
				push_back(x);
			}
		}
		
		// 用迭代器范围构造
		// 类模板的成员函数，也可以定义为函数模板
		// 任意容器迭代器初始化，但要求类型是匹配的
		// 如list<int>可以初始化vector<int>，但list<string>不能初始化vector<int>
		template<class InputIterator>
		vector(InputIterator begin, InputIterator end)
		{
			while (begin != end)
			{
				push_back(*begin);
				begin++;
			}
		}

		// n个val构造
		vector(int n, const T& val = T())
		{
			reserve(n);
			while (_finish != _start + n)
			{
				push_back(val);
			}
		}
		vector(size_t n, const T& val = T())
		{
			reserve(n);
			while (_finish != _start + n)
			{
				push_back(val);
			}
		}
		vector(long long n, const T& val = T())
		{
			reserve(n);
			while (_finish != _start + n)
			{
				push_back(val);
			}
		}

		~vector()
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_end_of_storage = nullptr;
		}
		
		// 传统写法
		//void clear()
		//{
		//	_finish = _start;
		//}
		//vector<int> operator=(const vector<T>& v)
		//{
		//	if (v != *this)
		///	{
		//		clear();
		//		reserve(v.size());
		//		for (auto& x : v)
		//		{
		//			push_back(x);
		///		}
		//	}
		//	return *this;
		//}
		// 现代写法
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		vector<T> operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

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
				//memcpy(temp, _start, old_size * sizeof(T));
				for (int i = 0; i < size(); ++i)
				{
					temp[i] = _start[i];
				}
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
		
		// operator[]和at都会进行边界检查，但前者是用assert，后者是抛异常
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
			assert(pos >= _start && pos <= _finish);
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

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			for (iterator i = pos + 1; i < _finish; ++i)
			{
				*(i - 1) = *i;
			}
			--_finish;
			return pos;
		}
		// erase后就认为迭代器失效了，需要更新后才能继续使用
		// vs依然会强制检查，erase后再访问迭代器就会报错，而gcc是不会检查的
		// 几乎所有容器的erase后都会导致迭代器失效，但insert后是否失效是不一定的

		void resize(size_t n, const T& val = T())// 写成void resize(size_t n, T val = T())也行
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					push_back(val);
				}
			}
		}
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

	void test3()
	{
		vector<int> v;
		v.push_back(2);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(4);
		print_Container(v);
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				v.erase(it);
			}
			else
			{
				++it;
			}
		}
		print_Container(v);
	}

	void test4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);
		v.push_back(9);
		v.push_back(0);
		print_Container(v);

		v.reserve(20);
		v.resize(5);
		print_Container(v);
		v.resize(15, 99);
		print_Container(v);
		v.resize(25, 88);
		print_Container(v);
	}

	void test5()
	{
		// 为了兼容模板的缺省值，内置类型也有了构造函数、析构函数
		int a = int();// 默认构造，默认初始化为0
		int b = int(2);// 用匿名对象拷贝构造
		int c(3);
		int d(c);

		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		print_Container(v1);
		vector<int> v2 = v1;
		print_Container(v2);
		vector<int> v3;
		v3 = v2;
		print_Container(v2);
	}

	void test6()
	{
		std::string s("hello");
		vector<std::string> v1(4, s);
		print_Container(v1);

		std::list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		vector<int> v2(++l.begin(), --l.end());
		print_Container(v2);

		vector<int> v3(10, 1);// 如果只写一个size_t n的n个val构造，那么这里会调用迭代器区间构造
		// 首先编译器会调用最匹配的构造函数
		// 因为整数10的类型默认是int，如果n的类型是size_t，而1的类型是int
		// 那么编译器把10和1当成迭代器，调用迭代器区间构造，这样两个参数的类型都是最匹配的
		// 如果想避免这种的情况，可以多写几个n个val构造的重载，让n的类型是int、size_t、long long等
		print_Container(v3);
	}

	void test7()
	{
		vector<std::string> v(4, "hello");
		print_Container(v);
		v.push_back("hello");
		print_Container(v);
		// 这时push_back会扩容，而扩容时调用的reserve，在拷贝数据的时候用的是memcpy
		// 这是浅拷贝，当拷贝完数据
		// 新的空间里的每一个的string的_str都指向原来对应的string的_str所指向的空间
		// 这时delete[]，原来的_str的空间被释放了，而新的string的_str还指向原来的空间
		// 再调用_str就会出错
		// 所以需要改变拷贝数据的方式
	}
}