//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstdlib>
//#include<cstring>
//#include<cassert>
//#include<string>
//
//template<class T>
//class stack
//{
//public:
//    stack() = default;
//    void swap(stack<T>& other)
//    {
//        std::swap(_a, other._a);
//        std::swap(_size, other._size);
//        std::swap(_capacity, other._capacity);
//    }
//    stack(const stack<T>& other)
//    {
//        reserve(other._capacity);
//        memcpy(_a, other._a, sizeof(T) * other._size);
//        _size = other._size;
//    }
//    ~stack()
//    {
//        delete[] _a;
//        _a = nullptr;
//        _size = 0;
//        _capacity = 0;
//    }
//    stack<T> operator=(stack<T> other)
//    {
//        swap(other);
//        return *this;
//    }
//    size_t size()
//    {
//        return _size;
//    }
//    size_t capacity()
//    {
//        return _capacity;
//    }
//    void reserve(size_t n)
//    {
//        if (n > _capacity)
//        {
//            T* temp = new T[n];
//            memcpy(temp, _a, sizeof(T) * _size);
//            delete[] _a;
//            _a = temp;
//            _capacity = n;
//        }
//    }
//    void push(const T& x)
//    {
//        if (_size == _capacity)
//        {
//            reserve(_capacity == 0 ? 4 : 2 * _capacity);
//        }
//        _a[_size++] = x;
//    }
//    void pop()
//    {
//        assert(_size > 0);
//        --_size;
//    }
//    T& top()
//    {
//        assert(_size > 0);
//        return _a[_size - 1];
//    }
//    bool empty()
//    {
//        return _size == 0;
//    }
//private:
//    T* _a = nullptr;
//    size_t _size = 0;
//    size_t _capacity = 0;
//};
//
//int calculate(int left, char op, int right)
//{
//    switch (op)
//    {
//    case '*':
//        return left * right;
//    case '/':
//        return left / right;
//    case '+':
//        return left + right;
//    case '-':
//        return left - right;
//    }
//    return 0;
//}
//
//int main()
//{
//    std::string s;
//    std::cout << "input" << std::endl;
//    std::cin >> s;
//    stack<int> nums;
//    stack<char> ops;
//    for (auto x : s)
//    {
//        if (x >= '0' && x <= '9')
//        {
//            nums.push(x - '0');
//        }
//        else if (x == '(')
//        {
//            ops.push(x);
//        }
//        else if (x == ')')
//        {
//            while (ops.top() != '(')
//            {
//                int right = nums.top();
//                nums.pop();
//                int left = nums.top();
//                nums.pop();
//                char op = ops.top();
//                ops.pop();
//                nums.push(calculate(left, op, right));
//            }
//            ops.pop();
//        }
//        else
//        {
//            while (!ops.empty() && ops.top() != '(' &&
//                ((x == '+' && (ops.top() == '*' || ops.top() == '/' || ops.top() == '-' || ops.top() == '+')) ||
//                    (x == '-' && (ops.top() == '*' || ops.top() == '/' || ops.top() == '-' || ops.top() == '+')) ||
//                    (x == '/' && (ops.top() == '*' || ops.top() == '/')) ||
//                    (x == '*' && (ops.top() == '*' || ops.top() == '/'))))
//            {
//                int right = nums.top();
//                nums.pop();
//                int left = nums.top();
//                nums.pop();
//                char op = ops.top();
//                ops.pop();
//                nums.push(calculate(left, op, right));
//            }
//            ops.push(x);
//        }
//    }
//    while (!ops.empty())
//    {
//        int right = nums.top();
//        nums.pop();
//        int left = nums.top();
//        nums.pop();
//        char op = ops.top();
//        ops.pop();
//        nums.push(calculate(left, op, right));
//    }
//    std::cout << "output" << std::endl;
//    std::cout << '=' << nums.top() << std::endl;
//    std::cout << "end" << std::endl;
//    system("pause");
//    return 0;
//}