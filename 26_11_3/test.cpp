#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

//int main()
//{
//    // 可以用于两个链表
//    std::list<int> mylist1;
//    std::list<int> mylist2;
//    std::list<int>::iterator it;
//    for (int i = 1; i <= 4; ++i)
//    {
//        mylist1.push_back(i);// mylist1: 1 2 3 4
//    }
//    for (int i = 1; i <= 3; ++i)
//    {
//        mylist2.push_back(i * 10);// mylist2: 10 20 30
//    }
//    it = mylist1.begin();
//    ++it;// points to 2
//    mylist1.splice(it, mylist2);// mylist1: 1 10 20 30 2 3 4
//                                // mylist2 (empty)
//                                // "it" still points to 2 (the 5th element)
//
//    // 也可以用于同一个链表，调整节点的位置
//    std::list<int> li;
//    for (int i = 1; i <= 6; ++i)
//    {
//        li.push_back(i);
//    }
//    int x = 0;
//    std::cin >> x;
//    it = find(li.begin(), li.end(), x);
//    if (it != li.end())
//    {
//        li.splice(li.begin(), li, it);// 把x的位置调整到最前面
//    }
//
//	return 0;
//}

int main()
{
	//Sashtok::test1();
	//Sashtok::test2();
	//Sashtok::test3();
	Sashtok::test4();
	return 0;
}