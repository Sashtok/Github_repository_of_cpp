#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstdlib>
//
//class Sorter
//{
//public:
//    void Input()
//    {
//        while (_x && _n < 18)
//        {
//            std::cin >> _x;
//            if (_x && _n < 18)
//            {
//                _a[_n++] = _x;
//            }
//        }
//    }
//    void Swap(int& x, int& y)
//    {
//        int t = x;
//        x = y;
//        y = t;
//    }
//    void Output()
//    {
//        for (int i = 0; i < _n; ++i)
//        {
//            if (i == 0)
//            {
//                std::cout << _a[i];
//            }
//            else
//            {
//                std::cout << "," << _a[i];
//            }
//        }
//        std::cout << std::endl;
//    }
//    void BubbleSort();
//    void InsertSort();
//    void SelectSort();
//private:
//    int _a[18] = { 0 };
//    int _n = 0;
//    int _x = 1;
//};
//
//void Sorter::BubbleSort()
//{
//    std::cout << "bubble sort" << std::endl;
//    for (int i = 0; i < _n - 1; ++i)
//    {
//        for (int j = 0; j < _n - 1 - i; ++j)
//        {
//            if (_a[j] > _a[j + 1])
//            {
//                Swap(_a[j], _a[j + 1]);
//            }
//        }
//    }
//}
//
//void Sorter::InsertSort()
//{
//    std::cout << "insert sort" << std::endl;
//    for (int j = 1; j < _n; ++j)
//    {
//        int key = _a[j];
//        int i = 0;
//        for (i = j; i > 0; --i)
//        {
//            if (_a[i - 1] < key)
//            {
//                break;
//            }
//            _a[i] = _a[i - 1];
//        }
//        _a[i] = key;
//    }
//}
//
//void Sorter::SelectSort()
//{
//    std::cout << "select sort" << std::endl;
//    int left = 0;
//    int right = _n - 1;
//    while (left <= right)
//    {
//        int min = left;
//        int max = min;
//        for (int i = left; i <= right; ++i)
//        {
//            if (_a[min] > _a[i])
//            {
//                min = i;
//            }
//            if (_a[max] < _a[i])
//            {
//                max = i;
//            }
//        }
//        Swap(_a[left], _a[min]);
//        if (max == left)
//        {
//            max = min;
//            Swap(_a[right], _a[max]);
//        }
//        else
//        {
//            Swap(_a[right], _a[max]);
//        }
//        ++left;
//        --right;
//    }
//}
//
//int main()
//{
//    Sorter s;
//    std::cout << "input" << std::endl;
//    s.Input();
//    std::cout << "1-bubble sort,2-insert sort,3-select sort" << std::endl;
//    int flag = 0;
//    std::cin >> flag;
//    std::cout << "output" << std::endl;
//    switch (flag)
//    {
//    case 1:
//        s.BubbleSort();
//        break;
//    case 2:
//        s.InsertSort();
//        break;
//    case 3:
//        s.SelectSort();
//        break;
//    default:
//        break;
//    }
//    s.Output();
//    std::cout << "end" << std::endl;
//    system("pause");
//    return 0;
//}