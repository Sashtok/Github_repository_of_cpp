//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstdlib>
//#include<vector>
//
//class UnionFind
//{
//public:
//    UnionFind(size_t n)
//    {
//        parent.resize(n + 1);
//        for (size_t i = 1; i < n + 1; ++i)
//        {
//            parent[i] = i;
//        }
//    }
//    size_t find(size_t x)
//    {
//        return parent[x];
//    }
//    void unite(size_t classA, size_t classB)
//    {
//        size_t temp = find(classB); 
//        for (auto& x : parent)
//        {
//            if (x == temp)
//            {
//                x = find(classA);
//            }
//        }
//    }
//    void Output(size_t n)
//    {
//        std::vector<std::vector<size_t>> vv(n + 1, std::vector<size_t>());
//        for (size_t i = 1; i <= n; ++i)
//        {
//            vv[find(i)].push_back(i);
//        }
//        for (size_t i = 1; i <= n; ++i)
//        {
//            if (!vv[i].empty())
//            {
//                std::cout << '(';
//                for (size_t j = 0; j < vv[i].size(); ++j)
//                {
//                    if (j == 0)
//                    {
//                        std::cout << vv[i][j];
//                    }
//                    else
//                    {
//                        std::cout << ',' << vv[i][j];
//                    }
//                }
//                std::cout << ')' << std::endl;
//            }
//        }
//    }
//private:
//    std::vector<size_t> parent;
//};
//
//int main()
//{
//    std::cout << "input" << std::endl;
//    size_t n = 0;
//    std::cin >> n;
//    UnionFind uf(n);
//
//    std::cout << "input" << std::endl;
//    size_t r = 0;
//    std::cin >> r;
//    while (r--)
//    {
//        char op1;
//        size_t A = 0;
//        char op2;
//        size_t B = 0;
//        char op3;
//        std::cin >> op1 >> A >> op2 >> B >> op3;
//        uf.unite(A, B);
//    }
//
//    std::cout << "output" << std::endl;
//    uf.Output(n);
//
//    std::cout << "end" << std::endl;
//    system("pause");
//    return 0;
//}