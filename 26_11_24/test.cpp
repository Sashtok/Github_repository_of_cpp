#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

//// 菱形继承
////class A
////{
////public:
////	std::string _name;
////};
////
////class B1 : public A
////{
////protected:
////	int _b1;
////};
////
////class B2 : public A
////{
////protected:
////	int _b2;
////};
////
////class C : public B1, public B2
////{
////protected:
////	int _c;
////};
//
//// 菱形虚拟继承
//class A
//{
//public:
//	std::string _name;
//};
//
//class B1 : virtual public A
//{
//protected:
//	int _b1;
//};
//
//class B2 : virtual public A
//{
//protected:
//	int _b2;
//};
//
//class C : public B1, public B2
//{
//protected:
//	int _c;
//};
//
//// 不推荐使用菱形虚拟继承，因为有很多坑
////class A
////{
////public:
////	A(std::string name)
////		: _name(name)
////	{}
////protected:
////	std::string _name;
////};
////
////class B1 : virtual public A
////{
////public:
////	B1(std::string name, int b1 = 0)
////		: A(name)
////		, _b1(b1)
////	{}
////protected:
////	int _b1;
////};
////
////class B2 : virtual public A
////{
////public:
////	B2(std::string name, int b2 = 0)
////		: A(name)
////		, _b2(b2)
////	{}
////protected:
////	int _b2;
////};
////
////class C : public B1, public B2
////{
////public:
////	C(std::string name1, std::string name2, std::string name3, int c = 0)
////		// 这里到底会用哪个name初始化_name？
////		: B1(name1)
////		, B2(name2)
////		, A(name3)
////		, _c(c)
////		// 先走A的构造，用name3初始化_name
////		// 然后走B1的构造，这时会跳过B1构造里A的构造，然后走B2的构造，同样会跳过
////		// 所以最终是用name3初始化_name
////		// 菱形虚拟继承中要把公共基类看成一个单独的父类，这是编译器特殊处理的结果
////	{}
////protected:
////	int _c;
////};
//
//int main()
//{
//	C c;
//	//c._name = "Bob";// 具有二义性和数据冗余的问题，解决办法是指定类域访问或者虚拟继承
//	c.B1::_name = "Bob";// 但是指定类域访问无法解决数据冗余的问题
//	c.B2::_name = "Jack";
//
//	c._name = "M";// 虚拟继承可以很好的解决问题
//	// 但如果B1和B2只有一个进行虚继承，也无法解决问题
//
//	// 这也是菱形继承，A会在E处产生二义性和数据冗余，virtual加在B和C处
//	//  		   A
//	//  		 /	 \
//	//  virtual	B     C virtual
//	//  		|	  |
//	//  		D	  |
//	//  		 \	 /
//	//  		   E
//	// 哪个类产生二义性和数据冗余，就在继承他时用虚拟继承
//
//	return 0;
//}


//int main()
//{
//	// 黑盒测试：不了解底层实现，从功能角度测试
//	// 白盒测试：了解底层实现，从代码运行逻辑角度测试
//	// 白盒测试更难
//
//	return 0;
//}


//class A
//{
//public:
//	virtual void print()
//	{
//		std::cout << "class A" << std::endl;
//	}
//};
//
//class B1 : public A
//{
//public:
//	virtual void print()
//	//void print()// 派生类也可以不加virtual
//	{
//		std::cout << "class B1" << std::endl;
//	}
//};
//
//class B2 : public A
//{
//public:
//	virtual void print()
//	{
//		std::cout << "class B2" << std::endl;
//	}
//};
//
//void func(A* a1, A& a2)
//{
//	a1->print();
//	a2.print();
//}
//
//int main()
//{
//	A a;
//	B1 b1;
//	B2 b2;
//	func(&a, a);
//	func(&b1, b1);
//	func(&b2, b2);
//
//	return 0;
//}


class A
{
public:
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }

	virtual void test() { func(); }
};

class B : public A
{
public:
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};

int main()
{
	B* p = new B;
	p->test();
	// 这里调用test，由于B没有覆盖test，所以p->test()最终调用继承来的A::test
	// 进入A::test后，this的静态类型是A*，但实际指向B对象。
	// virtual void test(A* this)
	// A中func是虚函数，B也对func完成的重写，这是由基类的指针调用虚函数
	// 所以满足运行时多态的条件
	// 运行时多态调用时，重写的函数可以看成由被重写的函数的声明和重写函数的实现组成
	// virtual void func(int val = 1) { std::cout << "B->" << val << std::endl; }
	// 这也是重写虚函数可以不写virtual的原因
	// 调用表达式先根据静态类型可见的声明确定默认实参，再动态分派到最终覆盖函数的函数体。
	// 在A::test中，func()调用点可见的是A::func(int val = 1)，所以默认实参是 1
	// 但函数体动态分派到B::func，所以输出B->1。
	// 所以虽然调用的是B类的func，但是缺省值是A的
	// 结果是B->1

	p->func();
	// 如果是直接调用func，就不构成多态了，调用的就是B类里原本的func
	// 结果是B->0

	return 0;
}