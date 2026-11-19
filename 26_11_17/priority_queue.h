#pragma once

// 仿函数：本质是一个类，这个类重载了()，即operator()，他的对象可以像函数一样访问
// 仿函数的对象叫做函数对象
template<class T>
class less
{
public:
	bool operator()(const T& x, const T& y) const
	{
		return x < y;
	}
};

template<class T>
class greater
{
public:
	bool operator()(const T& x, const T& y) const
	{
		return x > y;
	}
};

namespace Sashtok
{
	template<class T, class Container = std::vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		void adjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (parent >= 0 && com(_con[parent], _con[child]))
			{
				std::swap(_con[parent], _con[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			adjustUp(_con.size() - 1);
		}
		void adjustDown(int parent)
		{
			Compare com;
			int child = parent * 2 + 1;
			if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
			{
				child++;
			}
			while (child < _con.size() && com(_con[parent], _con[child]))
			{
				std::swap(_con[parent], _con[child]);
				parent = child;
				child = parent * 2 + 1;
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					child++;
				}
			}
		}
		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjustDown(0);
		}
		const T& top() const
		{
			return _con[0];
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