#pragma once
#include<iostream>

namespace key
{
	template<class K>
	struct binary_search_tree_node
	{
		K _key;
		binary_search_tree_node* _left;
		binary_search_tree_node* _right;

		binary_search_tree_node(const K& key)
			: _key(key)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};

	template<class K>
	class binary_search_tree
	{
		//typedef binary_search_tree_node<K> node;
		using node = binary_search_tree_node<K>;
	public:
		bool insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new node(key);
				return true;
			}
			node* parent = _root;
			node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			if (key > parent->_key)
			{
				parent->_right = new node(key);
			}
			else
			{
				parent->_left = new node(key);
			}
			return true;
		}
		void inOrder()
		{
			_inOrder(_root);
		}
		bool find(const K& key)
		{
			node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}
			return false;
		}
		bool erase(const K& key)
		{
			node* parent = _root;
			node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else
					{
						node* rParent = cur->_right;
						node* rCur = cur->_right;
						while (rCur->_left)
						{
							rParent = rCur;
							rCur = rCur->_left;
						}
						cur->_key = rCur->_key;
						if (rParent != rCur)
						{
							rParent->_left = rCur->_right;
						}
						else
						{
							cur->_right = rCur->_right;
						}
						delete rCur;
					}
					return true;
				}
			}
			return false;
		}
		~binary_search_tree()
		{
			destroy(_root);
		}
		binary_search_tree() = default;
		binary_search_tree(const binary_search_tree<K>& t)
		{
			_root = copy(t._root);
		}
		binary_search_tree<K> operator=(binary_search_tree<K> t)
		{
			std::swap(_root, t._root);
			return *this;
		}
	private:
		void _inOrder(node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_inOrder(root->_left);
			std::cout << root->_key << ' ';
			_inOrder(root->_right);
		}
		void destroy(node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			destroy(root->_left);
			destroy(root->_right);
			delete root;
		}
		node* copy(node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			node* temp = new node(root->_key);
			temp->_left = copy(root->_left);
			temp->_right = copy(root->_right);
			return temp;
		}
	private:
		node* _root = nullptr;
	};
}

namespace key_value
{
	template<class K, class V>
	struct binary_search_tree_node
	{
		K _key;
		V _val;
		binary_search_tree_node* _left;
		binary_search_tree_node* _right;

		binary_search_tree_node(const K& key, const V& val)
			: _key(key)
			, _val(val)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};

	template<class K, class V>
	class binary_search_tree
	{
		//typedef binary_search_tree_node<K, V> node;
		using node = binary_search_tree_node<K, V>;
	public:
		bool insert(const K& key, const V& val)
		{
			if (_root == nullptr)
			{
				_root = new node(key, val);
				return true;
			}
			node* parent = _root;
			node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			if (key > parent->_key)
			{
				parent->_right = new node(key, val);
			}
			else
			{
				parent->_left = new node(key, val);
			}
			return true;
		}
		void inOrder()
		{
			_inOrder(_root);
		}
		node* find(const K& key)
		{
			node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}
		bool erase(const K& key)
		{
			node* parent = _root;
			node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else
					{
						node* rParent = cur->_right;
						node* rCur = cur->_right;
						while (rCur->_left)
						{
							rParent = rCur;
							rCur = rCur->_left;
						}
						cur->_key = rCur->_key;
						if (rParent != rCur)
						{
							rParent->_left = rCur->_right;
						}
						else
						{
							cur->_right = rCur->_right;
						}
						delete rCur;
					}
					return true;
				}
			}
			return false;
		}
		~binary_search_tree()
		{
			destroy(_root);
		}
		binary_search_tree() = default;
		binary_search_tree(const binary_search_tree<K, V>& t)
		{
			_root = copy(t._root);
		}
		binary_search_tree<K, V> operator=(binary_search_tree<K, V> t)
		{
			std::swap(_root, t._root);
			return *this;
		}
	private:
		void _inOrder(node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_inOrder(root->_left);
			std::cout << root->_key << ':' << root->_val << ' ';
			_inOrder(root->_right);
		}
		void destroy(node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			destroy(root->_left);
			destroy(root->_right);
			delete root;
		}
		node* copy(node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			node* temp = new node(root->_key, root->_val);
			temp->_left = copy(root->_left);
			temp->_right = copy(root->_right);
			return temp;
		}
	private:
		node* _root = nullptr;
	};
}