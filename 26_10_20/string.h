#pragma once
#include<iostream>
#include<cassert>
#include<string>

namespace Sashtok
{
	class string
	{
	public:
		/*string()
			: _str(new char[1]{'0'})
			, _size(0)
			, _capacity(0)
		{}
		string(const char* s)
		{
			_size = strlen(s);
			_str = new char[_size + 1];
			strcpy(_str, s);
			_capacity = _size;
		}*/
		string(const char* s = "")
		{
			_size = strlen(s);
			_str = new char[_size + 1];
			strcpy(_str, s);
			_capacity = _size;
		}
		const char* c_str() const 
		{
			return _str;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
		const size_t size() const
		{
			return _size;
		}
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index) const
		{
			assert(index < _size);
			return _str[index];
		}
		const size_t capacity()
		{
			return _capacity;
		}
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		void operator+=(char ch);
		void operator+=(const char* str);
		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos, size_t len = npos);
		
		size_t find(char ch);
		size_t find(const char* str);
		string substr(size_t pos, size_t len = npos);  

		// 浅拷贝的缺点
		// 析构两次
		// 一个修改会影响另外一个

		// 传统写法
		/*string(string& str)
		{
			char* temp = new char[str.capacity() + 1];
			delete[] _str;
			_str = temp;
			int i = 0;
			for (auto ch : str)
			{
				_str[i++] = ch;
			}
			_capacity = str.capacity();
			_size = str.size();
			_str[_size] = '\0';
		}
		string& operator=(string& str);*/

		// 现代写法
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_capacity, str._capacity);
			std::swap(_size, str._size);
		}
		string(string& str)
		{
			string temp(str.c_str());
			swap(temp);
		}
		//string& operator=(string& str);// 方式一
		string& operator=(string temp);// 方式二
		// string 既有成员 swap，又有非成员 swap 重载
		// 成员 swap 通常只交换内部指针等资源，效率很高
		// 而 C++98 的通用 std::swap 模板是通过拷贝构造和赋值来实现的，对 string 可能产生三次深拷贝
		// 因此标准库为 string 提供了非成员 swap，内部调用成员 swap
		// 这样，通用代码写swap(a, b)时，就能通过重载/实参依赖查找 找到高效版本，避免退化成深拷贝交换

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
	private:
		char* _str = nullptr;
		size_t _size;
		size_t _capacity;
		static const size_t npos;

		// 奇特的是，本来static要在类外定义，但是static const的整形却可以在类内定义
		// 更奇特的是，static const的浮点型却不行
		//static const int N = 1;
		//static const double M = 1;
		// 可能是为了方便定义下面的数组
		//int buff[N];
		// 不推荐这样写
	};

	bool operator<(string& s1, string& s2);
	bool operator<=(string& s1, string& s2);
	bool operator>(string& s1, string& s2);
	bool operator>=(string& s1, string& s2);
	bool operator==(string& s1, string& s2);
	bool operator!=(string& s1, string& s2);

	std::ostream& operator<<(std::ostream& os, string& str);
	std::istream& operator>>(std::istream& is, string& str);

	void testString1();
	void testString2();
	void testString3();
	void testString4();
	void testString5();
	void testString6();
	void testString7();
}