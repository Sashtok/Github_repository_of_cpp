#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdlib>
#include<vector>

class max_heap
{
public:
    void input()
    {
        int x = 0;
        do
        {
            std::cin >> x;
            if (x != 0)
            {
                _max_heap.push_back(x);
            }
        } while (x);
    }
    void adjustDown(int father, int size)
    {
        int child = father * 2 + 1;
        if (child + 1 < size && _max_heap[child] < _max_heap[child + 1])
        {
            child++;
        }
        while (child < size && _max_heap[father] < _max_heap[child])
        {
            std::swap(_max_heap[father], _max_heap[child]);
            father = child;
            child = father * 2 + 1;
            if (child + 1 < _max_heap.size() && _max_heap[child] < _max_heap[child + 1])
            {
                child++;
            }
        }
    }
    void initHeap()
    {
        for (int i = _max_heap.size() / 2 - 1; i >= 0; --i)
        {
            adjustDown(i, _max_heap.size());
        }
    }
    void print()
    {
        for (int i = 0; i < _max_heap.size(); ++i)
        {
            if (i == 0)
            {
                std::cout << _max_heap[i];
            }
            else
            {
                std::cout << ',' << _max_heap[i];
            }
        }
        std::cout << std::endl;
    }
    void heapSort()
    {
        int size = _max_heap.size();
        while (size > 0)
        {
            std::swap(_max_heap[0], _max_heap[size - 1]);
            --size;
            adjustDown(0, size);
        }
    }
    std::vector<int>& vector()
    {
        return _max_heap;
    }
private:
    std::vector<int> _max_heap;
};

struct tree_node
{
    int _val;
    tree_node* _left;
    tree_node* _right;

    tree_node(int x = 0)
        : _val(x)
        , _left(nullptr)
        , _right(nullptr)
    {}
};

int count = 0;

class search_tree
{
public:
    tree_node* buyNode(int x)
    {
        tree_node* temp = new tree_node(x);
        return temp;
    }
    void insert(int x)
    {
        tree_node* temp = buyNode(x);
        tree_node* prev = _head;
        tree_node* cur = _head;
        while (1)
        {
            if (cur == nullptr)
            {
                if (x > prev->_val)
                {
                    prev->_right = temp;
                }
                else
                {
                    prev->_left = temp;
                }
                break;
            }
            else if (x == cur->_val)
            {
                break;
            }
            else if (x > cur->_val)
            {
                prev = cur;
                cur = cur->_right;
            }
            else if (x < cur->_val)
            {
                prev = cur;
                cur = cur->_left;
            }
        }
    }
    void buildTree(std::vector<int> v)
    {
        _head = buyNode(v[0]);
        for (int i = 1; i < v.size(); ++i)
        {
            insert(v[i]);
        }
    }
    void prevOrder(tree_node* head)
    {
        if (head == nullptr)
        {
            return;
        }
        if (count == 0)
        {
            std::cout << head->_val;
            ++count;
        }
        else
        {
            std::cout << ',' << head->_val;
        }
        prevOrder(head->_left);
        prevOrder(head->_right);
    }
    void inOrder(tree_node* head)
    {
        if (head == nullptr)
        {
            return;
        }
        inOrder(head->_left);
        if (count == 0)
        {
            std::cout << head->_val;
            ++count;
        }
        else
        {
            std::cout << ',' << head->_val;
        }
        inOrder(head->_right);
    }
    tree_node* head()
    {
        return _head;
    }
private:
    tree_node* _head = nullptr;
};

int main()
{
    max_heap mh;
    std::cout << "input" << std::endl;
    mh.input();
    search_tree st;
    st.buildTree(mh.vector());
    mh.initHeap();
    std::cout << "output" << std::endl;
    mh.print();
    mh.heapSort();
    mh.print();
    count = 0;
    st.prevOrder(st.head());
    std::cout << std::endl;
    count = 0;
    st.inOrder(st.head());
    std::cout << std::endl;
    std::cout << "end" << std::endl;
    system("pause");
    return 0;
}