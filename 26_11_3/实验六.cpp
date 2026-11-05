//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstdlib>
//#include<string>
//#include<vector>
//#include<queue>
//
//static size_t count = 0;
//
//struct treeNode
//{
//    char _val;
//    treeNode* _left;
//    treeNode* _right;
//};
//
//class binaryTree
//{
//public:
//    void prevOrder(treeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        if (count == 0)
//        {
//            std::cout << node->_val;
//        }
//        else
//        {
//            std::cout << ',' << node->_val;
//        }
//        count++;
//        prevOrder(node->_left);
//        prevOrder(node->_right);
//    }
//    void midOrder(treeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        midOrder(node->_left);
//        if (count == 0)
//        {
//            std::cout << node->_val;
//        }
//        else
//        {
//            std::cout << ',' << node->_val;
//        }
//        count++;
//        midOrder(node->_right);
//    }
//    void backOrder(treeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        backOrder(node->_left);
//        backOrder(node->_right);
//        if (count == 0)
//        {
//            std::cout << node->_val;
//        }
//        else
//        {
//            std::cout << ',' << node->_val;
//        }
//        count++;
//    }
//    int numbers(treeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//        return numbers(node->_left) + numbers(node->_right) + 1;
//    }
//    int height(treeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return 0;
//        }
//        int x = height(node->_left);
//        int y = height(node->_right);
//        return (x > y ? x : y) + 1;
//    }
//    treeNode* buyNode(char val)
//    {
//        treeNode* temp = new treeNode;
//        temp->_val = val;
//        temp->_left = nullptr;
//        temp->_right = nullptr;
//        return temp;
//    }
//    void buildTree(std::string s)
//    {
//        std::vector<treeNode*> v;
//        for (size_t i = 0; i < s.size(); ++i)
//        {
//            v.push_back(buyNode(s[i] + 'a' - 'A'));
//        }
//        _head = v[0];
//        for (size_t i = 0; i < v.size() / 2; ++i)
//        {
//            if (2 * i + 1 < v.size())
//            {
//                v[i]->_left = v[2 * i + 1];
//            }
//            if (2 * i + 2 < v.size())
//            {
//                v[i]->_right = v[2 * i + 2];
//            }
//        }
//    }
//    void destroy(treeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        destroy(node->_left);
//        destroy(node->_right);
//        delete node;
//    }
//    ~binaryTree()
//    {
//        destroy(_head);
//    }
//    treeNode* head()
//    {
//        return _head;
//    }
//private:
//    treeNode* _head = nullptr;
//};
//
//class tree
//{
//public:
//    void prevOrder(treeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        if (count == 0)
//        {
//            std::cout << node->_val;
//        }
//        else
//        {
//            std::cout << ',' << node->_val;
//        }
//        count++;
//        prevOrder(node->_left);
//        prevOrder(node->_right);
//    }
//    void midOrder(treeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        midOrder(node->_left);
//        if (count == 0)
//        {
//            std::cout << node->_val;
//        }
//        else
//        {
//            std::cout << ',' << node->_val;
//        }
//        count++;
//        midOrder(node->_right);
//    }
//    void backOrder(treeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        backOrder(node->_left);
//        backOrder(node->_right);
//        if (count == 0)
//        {
//            std::cout << node->_val;
//        }
//        else
//        {
//            std::cout << ',' << node->_val;
//        }
//        count++;
//    }
//    void levelOrder()
//    {
//        std::queue<treeNode*> q;
//        q.push(_head);
//        while (!q.empty())
//        {
//            treeNode* temp = q.front();
//            if (temp != nullptr)
//            {
//                if (count == 0)
//                {
//                    std::cout << temp->_val;
//                }
//                else
//                {
//                    std::cout << ',' << temp->_val;
//                }
//                ++count;
//                q.push(temp->_left);
//                q.push(temp->_right);
//            }
//            q.pop();
//        }
//    }
//    treeNode* buyNode(char val)
//    {
//        treeNode* temp = new treeNode;
//        temp->_val = val;
//        temp->_left = nullptr;
//        temp->_right = nullptr;
//        return temp;
//    }
//    auto transTree(std::string s)
//    {
//        std::vector<treeNode*> v;
//        for (size_t i = 0; i < s.size(); ++i)
//        {
//            v.push_back(buyNode(s[i] + 'a' - 'A'));
//        }
//        return v;
//    }
//    void buildVector(std::string prevs, std::string mids)
//    {
//        _prev = transTree(prevs);
//        _mid = transTree(mids);
//    }
//    void _build(treeNode*& head, int flag, int begin, int end)
//    {
//        if (begin == end)
//        {
//            return;
//        }
//        int i = 0;
//        for (i = begin; i < end; ++i)
//        {
//            if (_mid[i]->_val == _prev[flag]->_val)
//            {
//                head = _mid[i];
//                break;
//            }
//        }
//        _build(head->_left, flag + 1, begin, i);
//        _build(head->_right, flag + i - begin + 1, i + 1, end);
//    }
//    void buildTree()
//    {
//        _build(_head, 0, 0, _mid.size());
//    }
//    void destroy(treeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//        destroy(node->_left);
//        destroy(node->_right);
//        delete node;
//    }
//    ~tree()
//    {
//        destroy(_head);
//    }
//    treeNode* head()
//    {
//        return _head;
//    }
//private:
//    treeNode* _head = nullptr;
//    std::vector<treeNode*> _prev;
//    std::vector<treeNode*> _mid;
//};
//
//
//int main()
//{
//    std::cout << "input1" << std::endl;
//    std::string s;
//    std::cin >> s;
//
//    std::cout << "output1" << std::endl;
//    binaryTree btree;
//    btree.buildTree(s);
//    count = 0;
//    btree.prevOrder(btree.head());
//    std::cout << std::endl;
//    count = 0;
//    btree.midOrder(btree.head());
//    std::cout << std::endl;
//    count = 0;
//    btree.backOrder(btree.head());
//    std::cout << std::endl;
//    std::cout << btree.numbers(btree.head());
//    std::cout << std::endl;
//    std::cout << btree.height(btree.head());
//    std::cout << std::endl;
//
//    std::cout << "input2" << std::endl;
//    std::string prevs;
//    std::string mids;
//    std::cin >> prevs >> mids;
//    tree t;
//    t.buildVector(prevs, mids);
//    t.buildTree();
//
//    std::cout << "output2" << std::endl;
//    count = 0;
//    t.backOrder(t.head());
//    std::cout << std::endl;
//    count = 0;
//    t.levelOrder();
//    std::cout << std::endl;
//
//    std::cout << "end" << std::endl;
//    system("pause");
//    return 0;
//}