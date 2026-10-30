#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//#include<cstdlib>
//
//class Perm
//{
//public:
//	void Input();
//	void dfs(int pos);
//private:
//	int x = 1;
//	int a[20];
//	int n = 0;
//	int path[20];
//	bool used[20] = { false };
//};
//
//void Perm::Input()
//{
//	while (x)
//	{
//		std::cin >> x;
//		if (x)
//		{
//			a[n++] = x;
//		}
//	}
//	std::sort(a, a + n);
//}
//
//void Perm::dfs(int pos)
//{
//	if (pos == n)
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			if (i == 0)
//			{
//				std::cout << path[i];
//			}
//			else
//			{
//				std::cout << "," << path[i];
//			}
//		}
//		std::cout << std::endl;
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		if (!used[i])
//		{
//			used[i] = true;
//			path[pos] = a[i];
//			dfs(pos + 1);
//			used[i] = false;
//		}
//	}
//}
//
//int main()
//{
//	Perm p;
//	std::cout << "input" << std::endl;
//	p.Input();
//	std::cout << "output" << std::endl;
//	p.dfs(0);
//	std::cout << "end" << std::endl;
//	system("pause");
//	return 0;
//}