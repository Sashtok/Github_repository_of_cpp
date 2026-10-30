#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstdlib>
//
//class SingleList
//{
//public:
//    typedef struct ListNode
//    {
//        int _value;
//        ListNode* _next;
//    }LNode, * pLNode;
//    void Input();
//    pLNode BuyNode(int x)
//    {
//        pLNode temp = new LNode;
//        temp->_value = x;
//        temp->_next = nullptr;
//        return temp;
//    }
//    void Output() const;
//    void Merge(SingleList& sl1, SingleList& sl2);
//    bool IsNull()
//    {
//        return _list == nullptr;
//    }
//    pLNode GetHead()
//    {
//        return _list;
//    }
//    void Insert(int x);
//    int Find(int x) const
//    {
//        pLNode cur = _list;
//        int pos = 1;
//        while (cur)
//        {
//            if (cur->_value == x)
//            {
//                return pos;
//            }
//            cur = cur->_next;
//            pos++;
//        }
//        return 0;
//    }
//    void Erase();
//    ~SingleList()
//    {
//        if (_list != nullptr)
//        {
//            pLNode cur = _list;
//            while (cur)
//            {
//                pLNode next = cur->_next;
//                delete cur;
//                cur = next;
//            }
//        }
//    }
//private:
//    pLNode _list = nullptr;
//    int _x = 0;
//};
//
//void SingleList::Input()
//{
//    std::cin >> _x;
//    while (_x)
//    {
//        Insert(_x);
//        std::cin >> _x;
//    }
//}
//
//void SingleList::Output() const
//{
//    if (_list == nullptr)
//    {
//        std::cout << "(nul)" << std::endl;
//    }
//    else
//    {
//        bool flag = true;
//        pLNode cur = _list;
//        while (cur)
//        {
//            if (flag)
//            {
//                std::cout << cur->_value;
//                flag = false;
//            }
//            else
//            {
//                std::cout << "," << cur->_value;
//            }
//            cur = cur->_next;
//        }
//        std::cout << std::endl;
//    }
//}
//
//void SingleList::Merge(SingleList& sl1, SingleList& sl2)
//{
//    pLNode cur1 = sl1.GetHead();
//    pLNode cur2 = sl2.GetHead();
//    pLNode tail = _list;
//    while (cur1 != nullptr && cur2 != nullptr)
//    {
//        if (cur1->_value < cur2->_value)
//        {
//            if (_list == nullptr)
//            {
//                _list = cur1;
//                tail = _list;
//            }
//            else
//            {
//                tail->_next = cur1;
//                tail = tail->_next;
//            }
//            cur1 = cur1->_next;
//        }
//        else
//        {
//            if (_list == nullptr)
//            {
//                _list = cur2;
//                tail = _list;
//            }
//            else
//            {
//                tail->_next = cur2;
//                tail = tail->_next;
//            }
//            cur2 = cur2->_next;
//        }
//    }
//    while (cur1 != nullptr)
//    {
//        if (_list == nullptr)
//        {
//            _list = cur1;
//            tail = _list;
//        }
//        else
//        {
//            tail->_next = cur1;
//            tail = tail->_next;
//        }
//        cur1 = cur1->_next;
//    }
//    while (cur2 != nullptr)
//    {
//        if (_list == nullptr)
//        {
//            _list = cur2;
//            tail = _list;
//        }
//        else
//        {
//            tail->_next = cur2;
//            tail = tail->_next;
//        }
//        cur2 = cur2->_next;
//    }
//    sl1._list = nullptr;
//    sl2._list = nullptr;
//}
//
//void SingleList::Insert(int x)
//{
//    pLNode temp = BuyNode(x);
//    if (_list == nullptr)
//    {
//        _list = temp;
//    }
//    else
//    {
//        pLNode cur = _list;
//        if (temp->_value < _list->_value)
//        {
//            temp->_next = _list;
//            _list = temp;
//        }
//        else
//        {
//            while (cur->_next)
//            {
//                if (temp->_value <= cur->_next->_value)
//                {
//                    temp->_next = cur->_next;
//                    cur->_next = temp;
//                    break;
//                }
//                cur = cur->_next;
//            }
//            if (cur->_next == nullptr)
//            {
//                cur->_next = temp;
//            }
//        }
//    }
//}
//
//void SingleList::Erase()
//{
//    std::cin >> _x;
//    pLNode cur = _list;
//    pLNode prev = _list;
//    while (cur)
//    {
//        if (cur->_value == _x)
//        {
//            if (cur == _list)
//            {
//                _list = _list->_next;
//            }
//            else if (cur->_next == nullptr)
//            {
//                prev->_next = nullptr;
//            }
//            else
//            {
//                prev->_next = cur->_next;
//            }
//            delete cur;
//            Output();
//            return;
//        }
//        prev = cur;
//        cur = cur->_next;
//    }
//    std::cout << "(nul)" << std::endl;
//}
//
//int main()
//{
//    SingleList sl1;
//    SingleList sl2;
//    std::cout << "input1" << std::endl;
//    sl1.Input();
//    std::cout << "output1" << std::endl;
//    sl1.Output();
//    std::cout << "input2" << std::endl;
//    sl2.Input();
//    std::cout << "output2" << std::endl;
//    sl2.Output();
//    std::cout << "mergence" << std::endl;
//    SingleList sl;
//    sl.Merge(sl1, sl2);
//    sl.Output();
//    std::cout << "insert" << std::endl;
//    std::cout << "insertion" << std::endl;
//    int x = 0;
//    std::cin >> x;
//    sl.Insert(x);
//    sl.Output();
//    std::cout << "delete" << std::endl;
//    std::cout << "deletion" << std::endl;
//    sl.Erase();
//    std::cout << "find" << std::endl;
//    std::cout << "position" << std::endl;
//    std::cin >> x;
//    std::cout << sl.Find(x) << std::endl;
//    std::cout << "end" << std::endl;
//    system("pause");
//    return 0;
//}