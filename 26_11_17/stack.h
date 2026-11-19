#pragma once
#include<deque>

namespace Sashtok
{
	// Container适配转换出stack
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		void push(const T& x) 
		{
			_con.push_back(x);
		}
		void pop()
		{
			// 类模板实例化时，按需实例化，使用哪些成员函数就实例化哪些，不会全实例化
			//_con.pop();// 比如，这里写成这样，deque没有pop()接口
						 // 如果不调用stack的pop()，编译器不会报错，调用了，才会报错
			_con.pop_back();
		}
		const T& top() const
		{
			return _con.back();
		}
		size_t size() const
		{
			return _con.size();
		}
		bool empty() const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}