#pragma once
#include<iostream>
#include<cassert>

// 模板不能分离到两个文件
namespace Sashtok
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		begin();
		end();
		begin();
		end();

		reserve();
		
		size();
		capacity();
		
		push_back();
		
		operator[]();
		operator[]();
		
		empty();
		pop_back();

		insert();
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
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
	
	print_vector();

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

	void test1()
	{

	}

	void test2()
	{

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		size_t x = 0;
		std::cin >> x;
		auto p = std::find(v.begin(), v.end(), x);
		if (p != v.end())
		{
			v.insert(p, 40);
			// 第二种迭代器失效
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
		}
		// 在STL的vector的insert的解决方案是，返回新插入的值的迭代器
		// iterator insert(iterator & pos, const T & x)
		// 这样把p更新后，就可以访问了
		//p = v.insert(p, 40);
		//*(p + 1) *= 10;
	}
}