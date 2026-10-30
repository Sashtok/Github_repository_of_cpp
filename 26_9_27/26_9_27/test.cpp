#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int rand = 10;
//int main()
//{
//	// 编译报错：error C2365: “rand”: 重定义；以前的定义是“函数”
//	printf("%d\n", rand);
//	return 0;
//}

//namespace Sashtok// 这是命名空间的名字，此处以我的名字命名
//{
//}// 这里不需要加;

//namespace Sashtok
//{
//    // 命名空间中可以定义变量/函数/类型
//    int rand = 10;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//    struct Node
//    {
//        struct Node* next;
//        int val;
//    };
//}

//namespace out
//{
//    namesapce in
//    {
//    }
//}

//namespace Sashtok
//{
//    int N = 10;
//}
//int main()
//{
//    printf("%d", Sashtok::N);
//    return 0;
//}

//using Sashtok::N;
//int main()
//{
//    printf("%d", N);
//    return 0;
//}
//
//using namespace Sashtok;
//int main()
//{
//    printf("%d", N);
//    return 0;
//}
//
//int a = 0;
//std::cin >> a
//
//int a = 10;
//cout << 10 << endl;// 换行也可以用\n
//
//int a = 0;
//double b = 0;
//char c;
//std::cin >> a >> " " >> b >> " " >> c >> std::endl;
//
//int func(int a = 10)
//{
//    return a;
//}
//std::cout << func() << std::endl;// 输出10
//std::cout << func(5) << std::endl;// 输出5
//
//void func(int a = 5, double b = 10.0, char c = 'x');// 全缺省
//void func(int a, double b = 10.0, char c = 'x');// 半缺省
//
//void func(int a, int b = 10);// 声明时给缺省值，不然可能出现声明和定义的缺省值不同，而编译报错
//void func(int a, int b)
//{}
//
//// 1、参数类型不同
//int Add(int left, int right)
//{
//    std::cout << "int Add(int left, int right)" << std::endl;
//    return left + right;
//}
//
//double Add(double left, double right)
//{
//    std::cout << "double Add(double left, double right)" << std::endl;
//    return left + right;
//}
//
//// 2、参数个数不同
//void func()
//{
//    std::cout << "f()" << std::endl;
//}
//
//void func(int a)
//{
//    std::cout << "f(int a)" << std::endl;
//}
//
//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//    std::cout << "f(int a,char b)" << std::endl;
//}
//
//void f(char b, int a)
//{
//    std::cout << "f(char b, int a)" << std::endl;
//}
//
//// 返回值不同不能作为重载条件，因为调⽤时也⽆法区分
////void fc()
////{
////}
////
////int fc()
////{
////    return 0;
////}
//
//// 下⾯两个函数构成重载
//// 但是调⽤时会报错，存在歧义，编译器不知道调⽤谁
//void f1()
//{
//    std::cout << "f()" << std::endl;
//}
//
//void f1(int a = 10)
//{
//    std::cout << "f(int a)" << std::endl;
//}
//
//int a = 0;
//int& b = a;
//int& c = a;
//std::cout << &a << " " << &b << " " << &c << std::endl;// 地址是一样的
//
//// 小彩蛋
//#include<iostream>
//using namespace std;
//
//int main()
//{
//    // 在io需求⽐较⾼的地⽅，如部分⼤量输⼊的竞赛题中，加上以下3⾏代码，可以提⾼C++IO效率
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    return 0;
//}
//
//static bool sync_with_stdio(bool sync = true);
//// 属于std::ios_base的静态成员函数
//
//std::ostream* tie(std::ostream* str);
//// 属于std::basic_ios的成员函数（cin、cout都是它的对象）