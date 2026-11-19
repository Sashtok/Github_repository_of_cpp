#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>

#include"stack.h"
#include"queue.h"

//int main()
//{
//	Sashtok::stack<int> st;
//	//Sashtok::stack<int, std::vector<int>> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	st.pop();
//	std::cout << st.top() << ' ' << st.size() << std::endl;
//
//	Sashtok::queue<int> q;
//	//Sashtok::queue<int, std::list<int>> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	q.pop();
//	std::cout << q.front() << ' ' << q.back() << ' ' << q.size() << std::endl;
//
//	return 0;
//}

#include"priority_queue.h"

//int main()
//{
//	std::priority_queue<int, std::vector<int>, std::greater<int>> p;
//	p.push(1);
//	p.push(2);
//	p.push(3);
//	p.push(4);
//
//	Sashtok::priority_queue<int, std::vector<int>, greater<int>> pq;
//	pq.push(1);
//	pq.push(2);
//	pq.push(3);
//	pq.push(4);
//	pq.push(5);
//	pq.push(6);
//
//	std::cout << pq.top() << ' ' << pq.size() << std::endl;
//	
//	pq.pop();
//	pq.pop();
//	pq.pop();
//	pq.pop();
//	pq.pop();
//	pq.pop();
//
//	return 0;
//}

class A
{
	friend std::ostream& operator<<(std::ostream& os, const A& a);
public:
	A(int x = 0)
		: _a(x)
	{}
	bool operator<(const A& other) const
	{
		return _a < other._a;
	}
	bool operator>(const A& other) const
	{
		return _a > other._a;
	}
private:
	int _a;
};
std::ostream& operator<<(std::ostream& os, const A& a)
{
	os << a._a;
	return os;
}

class Aless
{
public:
	bool operator()(A* p1, A* p2)
	{
		return *p1 < *p2;
	}
};

int main()
{
	// 自己写仿函数
	// 1.类类型不支持比较大小
	// 2.支持比较大小，但是比较的逻辑不是我们想要的
	std::priority_queue<A> pq1;// A类自己重载了<、>运算符
	pq1.push(A(1));
	pq1.push(A(2));
	pq1.push(A(3));
	pq1.push(A(4));

	//std::priority_queue<A*> pq2;// 这里是按地址比较的，但是new的地址是随机的,所以结果也是随机的
	std::priority_queue<A*, std::vector<A*>, Aless> pq2;// 这里用自己写的Aless就可以解决
	pq2.push(new A(1));
	pq2.push(new A(2));
	pq2.push(new A(3));
	pq2.push(new A(4));
	std::cout << *pq2.top() << std::endl;
	pq2.pop();
	std::cout << *pq2.top() << std::endl;
	pq2.pop();
	std::cout << *pq2.top() << std::endl;
	pq2.pop();
	std::cout << *pq2.top() << std::endl;
	pq2.pop();

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

//#include<stack>
//class Solution
//{
//public:
//    bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
//    {
//        auto it1 = pushV.begin();
//        auto it2 = popV.begin();
//        while (it1 != pushV.end())
//        {
//            _st.push(*it1);
//            ++it1;
//            while (!_st.empty() && _st.top() == *it2)
//            {
//                _st.pop();
//                ++it2;
//            }
//        }
//        while (it2 != popV.end())
//        {
//            if (_st.top() != *it2)
//            {
//                return false;
//            }
//            _st.pop();
//            ++it2;
//        }
//        return _st.empty();
//    }
//private:
//    stack<int> _st;
//};

///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
// */
//class Solution
//{
//public:
//    vector<vector<int>> levelOrder(TreeNode* root)
//    {
//        if (root == nullptr)
//        {
//            return vector<vector<int>>();
//        }
//        vector<vector<int>> vv;
//        int i = 0;
//        vector<TreeNode*> v1;
//        v1.push_back(root);
//        while (!v1.empty())
//        {
//            vv.push_back(vector<int>());
//            for (auto& e : v1)
//            {
//                vv[i].push_back(e->val);
//            }
//            ++i;
//            size_t size = v1.size();
//            while (size--)
//            {
//                TreeNode* r = v1.front();
//                v1.erase(v1.begin());
//                if (r->left != nullptr)
//                {
//                    v1.push_back(r->left);
//                }
//                if (r->right != nullptr)
//                {
//                    v1.push_back(r->right);
//                }
//            }
//        }
//        return vv;
//    }
//};