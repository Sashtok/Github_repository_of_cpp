#define _CRT_SECURE_NO_WARNINGS 1


//#include<vector>
//class MinStack
//{
//public:
//    MinStack() = default;
//    void push(int value)
//    {
//        _stack.push_back(value);
//        if (_min == -1)
//        {
//            _min = 0;
//        }
//        else
//        {
//            if (_stack[_min] > value)
//            {
//                _min = _stack.size() - 1;
//            }
//        }
//    }
//    void pop()
//    {
//        _stack.pop_back();
//        if (_min == _stack.size())
//        {
//            _min = 0;
//            for (int i = 0; i < _stack.size(); ++i)
//            {
//                if (_stack[_min] > _stack[i])
//                {
//                    _min = i;
//                }
//            }
//        }
//    }
//
//    int top()
//    {
//        return _stack.back();
//    }
//
//    int getMin()
//    {
//        return _stack[_min];
//    }
//private:
//    vector<int> _stack;
//    size_t _min = -1;
//};