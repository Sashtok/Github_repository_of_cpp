#define _CRT_SECURE_NO_WARNINGS 1

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