//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstdlib>
//#include<vector>
//#include<queue>
//
//struct graph_node
//{
//    size_t _key;
//    int _weight;
//
//    graph_node(size_t key = 0, int weight = 0)
//        : _key(key)
//        , _weight(weight)
//    {}
//};
//
//class graph
//{
//    using node = graph_node;
//public:
//    graph(size_t v = 0, size_t e = 0, int noEdge = 0)
//        : _v(v)
//        , _e(e)
//        , _noEdge(noEdge)
//    {
//        _a.resize(_v + 1);
//        for (auto& x : _a)
//        {
//            x.resize(_v + 1);
//        }
//        for (size_t i = 1; i <= _v; ++i)
//        {
//            for (size_t j = 1; j <= _v; ++j)
//            {
//                _a[i][j]._key = _noEdge;
//            }
//        }
//    }
//    void insertEdge(size_t begin = 0, size_t end = 0, int weight = 0)
//    {
//        _a[begin][end]._key = 1;
//        _a[end][begin]._key = 1;
//        _a[begin][end]._weight = weight;
//        _a[end][begin]._weight = weight;
//    }
//    void bfs(size_t v, std::vector<bool> reach)
//    {
//        std::queue<size_t> q;
//        q.push(v);
//        reach[v] = false;
//        bool flag = true;
//        while (!q.empty())
//        {
//            int temp = q.front();
//            if (flag)
//            {
//                std::cout << temp;
//                flag = false;
//            }
//            else
//            {
//                std::cout << ',' << temp;
//            }
//            for (size_t j = 1; j <= _v; ++j)
//            {
//                if (_a[temp][j]._key == 1 && reach[j])
//                {
//                    q.push(j);
//                    reach[j] = false;
//                }
//            }
//            q.pop();
//        }
//    }
//    void dfs(size_t v, std::vector<bool>& reach, bool flag = true)
//    {
//        reach[v] = false;
//        if (flag)
//        {
//            std::cout << v;
//        }
//        else
//        {
//            std::cout << ',' << v;
//        }
//        for (size_t j = 1; j <= _v; ++j)
//        {
//            if (_a[v][j]._key == 1 && reach[j])
//            {
//                dfs(j, reach, false);
//            }
//        }
//    }
//private:
//    size_t _v = 0;
//    size_t _e = 0;
//    std::vector<std::vector<node>> _a;
//    int _noEdge = 0;
//};
//
//int main()
//{
//    std::cout << "input" << std::endl;
//    size_t n = 0;
//    size_t m = 0;
//    char c;
//    std::cin >> n >> c >> m;
//    graph g(n, m);
//    while (m--)
//    {
//        size_t b = 0;
//        size_t e = 0;
//        int w = 0;
//        std::cin >> b >> c >> e >> c >> w;
//        g.insertEdge(b, e, w);
//    }
//    std::cout << "output" << std::endl;
//    std::vector<bool> reach(n + 1, true);
//    g.bfs(1, reach);
//    std::cout << std::endl;
//    g.dfs(1, reach);
//    std::cout << std::endl;
//    //std::cout << g.minPath(1, n) << std::endl;
//    std::cout << "end" << std::endl;
//    system("pause");
//    return 0;
//}