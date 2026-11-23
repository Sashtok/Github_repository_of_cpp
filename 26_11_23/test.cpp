#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<string>

//// 类模板的继承
////namespace Sashtok
////{
////	template <class T>
////	class stack : public std::vector<T>
////	{
////	public:
////		void push(const T& x)
////		{
////			//push_back(x);// 编译报错:error C3861: “push_back”: 找不到标识符
////						   // 因为stack<int>实例化时，也实例化了vector<int>
////						   // 但是模版是按需实例化，push_back等成员函数未实例化，所以找不到
////			std::vector<T>::push_back(x);// 基类是类模板时，需要指定⼀下类域
////		}
////		void pop()
////		{
////			std::vector<T>::pop_back();
////		}
////		const T& top()
////		{
////			return std::vector<T>::back();
////		}
////		bool empty()
////		{
////			return std::vector<T>::empty();
////		}
////	};
////}
//
//// 用宏可以方便的完成替换
////#define CONTAINER std::vector
//#define CONTAINER std::list
////#define CONTAINER std::deque
//
//namespace Sashtok
//{
//	template <class T>
//	class stack : public CONTAINER<T>
//	{
//	public:
//		void push(const T& x)
//		{
//			CONTAINER<T>::push_back(x);
//		}
//		void pop()
//		{
//			CONTAINER<T>::pop_back();
//		}
//		const T& top()
//		{
//			return CONTAINER<T>::back();
//		}
//		bool empty()
//		{
//			return CONTAINER<T>::empty();
//		}
//	};
//}
//
//int main()
//{
//	Sashtok::stack<int> st;// 只实例化stack<int>的构造函数和vector<int>的构造函数
//	st.push(1);// 实例化stack<int>的push函数和vector<int>的push_back函数
//	st.push(2);
//	st.push(3);
//	while (!st.empty())
//	{
//		std::cout << st.top() << " ";
//		st.pop();
//	}
//	return 0;
//}



//class A
//{
//protected:
//	int _a;
//};
//
//class B : public A
//{
//private:
//	int _b;
//};
//
//int main()
//{
//	B b;
//
//	// 子类对象可以赋值给父类对象/指针/引用，不是类型转换
//	A a = b;
//	A* pa = &b;
//	A& ra = b;
//
//	// 父类对象不能赋值给子类对象
//	//b = a;
//	// 父类的指针在一定条件下可以赋值给子类的指针
//	B* pb = (B*)pa;
//
//	return 0;
//}

//class A
//{
//public:
//	void func()
//	{
//		std::cout << "A::func()" << std::endl;
//	}
//protected:
//	int _a = 1;
//};
//
//class B : public A
//{
//public:
//	void print()
//	{
//		std::cout << _a << std::endl;
//		std::cout << A::_a << std::endl;
//	}
//	void func(int i)// 只要函数名相同，就是隐藏，重载是需要在同一作用域的
//	{
//		std::cout << "B::func()" << std::endl;
//	}
//private:
//	int _a = 2;// 变量名相同，构成隐藏
//};
//
//int main()
//{
//	B b;
//	b.print();
//
//	//b.func();// 因为A的func被隐藏了，调不到，所以认为和B的func参数不匹配，编译报错
//	b.func(0);
//	b.A::func();
//
//	return 0;
//}



class A
{
public:
	//A(const std::string& s = "Bob")
	A(const std::string& s)
		: _name(s)
	{
		std::cout << "A(const std::string& s)" << std::endl;
	}
	A(const A& other)
		: _name(other._name)
	{
		std::cout << "A(const A& other)" << std::endl;
	}
	A& operator=(const A& other)
	{
		if (this != &other)// 避免自赋值
		{
			_name = other._name;
			
			std::cout << "operator=(const A& other)" << std::endl;
		}
		return *this;
	}
	~A()
	{
		std::cout << "~A()" << std::endl;
	}
protected:
	std::string _name;
};

class B : public A
{
public:
	// 编译器生成的默认构造函数的行为：
	// 1.将继承自父类的成员变量看为一个整体，调用父类的默认构造
	// 2.内置类型：不确定
	// 3.自定义类型：调用该类型的默认构造
	// 如果父类没有默认构造，需要手动在初始化列表调用父类的构造函数
	B(const std::string s = "")
		: A(s)
	{
		std::cout << "B(const std::string s = \"\")" << std::endl;
	}
	
	// 默认生成的拷贝构造、赋值重载、析构函数的行为可以类比默认构造函数，一般不用自己写
	// 有深拷贝才需要写这三个
	B(const B& other)
		: A(other)// 这里是赋值兼容转换
				  // 当自己实现拷贝构造时
				  // 如果不显示调用父类的拷贝构造
				  // 那么初始化列表默认调用父类的默认构造，不符合需求
		, _b(other._b)
		, _add(other._add)
	{
		std::cout << "B(const B& other)" << std::endl;
	}

	B& operator=(const B& other)
	{
		if (this != &other)
		{
			//operator=(other);// 如果这样写，会无线调用B的operator=()而栈溢出
							   // 因为B和A的operator=()构成的隐藏
			A::operator=(other);// 需要这样写
			_b = other._b;
			_add = other._add;
			
			std::cout << "operator=(const B& other)" << std::endl;
		}
		return *this;
	}

	~B()
	{
		////~A();// 由于编译器的特殊处理，所有的析构函数名都会变为destructor()
		//	     // 所以子类和父类的析构函数名构成隐藏，所以不能这样写
		//A::~A();// 需要这样写

		// 不过其实不需要显示调用父类的析构，因为把父类成员变量看成一个整体
		// 子类析构会在最后自动调用父类析构
		// 这样可以保证后定义的先析构

		std::cout << "~B()" << std::endl;
	}

private:
	int _b = 0	;
	std::string _add = "";
};

int main()
{
	B b1("aaa");
	B b2 = b1;
	B b3;
	b3 = b1;

	return 0;
}