#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"

namespace Sashtok
{
	// 不用再写static了
	const size_t string::npos = -1;

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* temp = new char[n + 1];
			strcpy(temp, _str);
			delete[] _str;
			_str = temp;
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		_str[_size] = ch;
		_size++;
		_str[_size] = '\0';
		_capacity = strlen(_str);
	}

	void string::append(const char* str)
	{
		if (_capacity < _size + strlen(str))
		{
			reserve(_size + strlen(str));
		}
		strcpy(_str + _size, str);
		_size += strlen(str);
		_capacity = strlen(_str);
	}

	void string::operator+=(char ch)
	{
		push_back(ch);
	}

	void string::operator+=(const char* str)
	{
		append(str);
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _capacity);
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}

		/*size_t end = _size;
		while (end >= pos)
		{
			_str[pos + 1] = _str[pos];
			--end;
		}*/
		// 如果这样写，会发现头插时，进入死循环，因为size_t是无符号的
		// 当end减到-1，反而会变成整型的最大值，进而再次进入循环
		/*int end = _size;
		while (end >= pos)
		{
			_str[pos + 1] = _str[pos];
			--end;
		}*/
		// 如果改成int类型，会发现还是会进入死循环
		// 因为end >= pos在比较时会进行类型提升，范围小的向范围大的转
		// int变成size_t类型
		/*int end = _size;
		while (end >= (int)pos)
		{
			_str[pos + 1] = _str[pos];
			--end;
		}*/
		// 想解决，需要把pos强制类型转换成int
		// 所以还是推荐下面的写法或者是用指针而不是下边来遍历

		for (int i = _size; i > pos; --i)
		{
			_str[i] = _str[i - 1];
		}
		_str[pos] = ch;
		++_size;
		_str[_size] = '\0';
		_capacity = strlen(_str);
	}
	
	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _capacity);
		size_t len = strlen(str);
		if (len == 0)
		{
			return;
		}
		if (_size + len  >  _capacity)
		{
			reserve(_capacity == 0 ? len : _size + len);
		}
		for (int i = _size + len - 1; i > pos; --i)
		{
			_str[i] = _str[i - len];
		}
		for (int i = 0; i < len; ++i)
		{
			_str[pos + i] = str[i];
		}
		_size += len;
		_str[_size] = '\0';
		_capacity = strlen(_str);
	}
	
	void string::erase(size_t pos, size_t len)
	{
		assert(pos <= _capacity);
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
			return;
		}
		strcpy(_str + pos, _str + pos + len);
	}

	size_t string::find(char ch)
	{
		for (int i = 0; i < _size; ++i)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return string::npos;
	}

	size_t string::find(const char* str)
	{
		const char* temp = strstr(_str, str);
		return temp - _str;
	}

	string string::substr(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len > _size - pos)
		{
			len = _size - pos;
		}
		string sub;
		for (int i = 0; i < len; ++i)
		{
			sub += _str[pos + i];
		}
		return sub;
	}

	// 传统写法
	//string& string::operator=(string& str)
	//{
	//	// 考虑自己给自己赋值
	//	if (this == &str)
	//	{
	//		return *this;
	//	}
	//	char* temp = new char[str.capacity() + 1];
	//	delete[] _str;
	//	_str = temp;
	//	int i = 0;
	//	for (auto ch : str)
	//	{
	//		_str[i++] = ch;
	//	}
	//	_capacity = str.capacity();
	//	_size = str.size();
	//	_str[_size] = '\0';
	//	return *this;
	//}
	
	// 现代写法
	/*string& string::operator=(string& str)
	{
		string temp(str);
		swap(temp);
		return *this;
	}*/
	// 现代写法
	string& string::operator=(string temp)
	{
		swap(temp);
		return *this;
	}

	bool operator<(string& s1, string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	bool operator<=(string& s1, string& s2)
	{
		return (s1 < s2) || (s1 == s2);
	}

	bool operator>(string& s1, string& s2)
	{
		return !(s1 <= s2);
	}

	bool operator>=(string& s1, string& s2)
	{
		return (s1 > s2) || (s1 == s2);
	}

	bool operator==(string& s1, string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	
	bool operator!=(string& s1, string& s2)
	{
		return !(s1 == s2);
	}

	std::ostream& operator<<(std::ostream& os, string& str)
	{
		for (auto ch : str)
		{
			os << ch;
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, string& str)
	{
		str.clear();
		char buff[1024];
		buff[1023] = '\0';
		int i = 0;
		buff[i++] = is.get();
		// 流提取时cin默认提取不到空格和换行
		// 需要用get()，空格和换行都能读到
		// 如果是输入带空格的句子，需要再实现一个
		//getline();
		while (buff[i - 1] != ' ' && buff[i - 1] != '\n')
		{
			if (i == 1023)
			{
				str += buff;
				i = 0;
			}
			buff[i++] = is.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			str += buff;
		}
		return is;
	}
}