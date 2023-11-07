#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DSU(int n) : parent(n + 1), rank(n + 1, 0)
    {
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            if (rank[x] < rank[y])
                std::swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }
};

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (!fin.is_open()) {
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    int n, m, q;
    fin >> n >> m >> q;

    DSU dsu(n);

    std::vector<std::pair<int, int>> roads(m);
    for (int i = 0; i < m; ++i)
    {
        fin >> roads[i].first >> roads[i].second;
    }

    std::vector<int> qs(q);
    std::vector<bool> is_used(m, false);

    for (int i = 0; i < q; ++i)
    {
        fin >> qs[i];
        is_used[qs[i] - 1] = true;
    }

    int components = n;

    for(int i = 0; i < m; ++i)
    {
        if(!is_used[i] && (dsu.find(roads[i].first) != dsu.find(roads[i].second)))
        {
            dsu.unite(roads[i].first, roads[i].second);
            components--;
        }
    }

    std::stack<int> results;

    for (int i = q - 1; i >= 0; --i)
    {
        results.push(components <= 1 ? 1 : 0);

        if (dsu.find(roads[qs[i] - 1].first) != dsu.find(roads[qs[i] - 1].second))
        {
            dsu.unite(roads[qs[i] - 1].first, roads[qs[i] - 1].second);
            components--;
        }
    }

    while (!results.empty())
    {
        fout << results.top();
        results.pop();
    }

    fin.close();
    fout.close();

    return 0;
}


//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <stack>
//
//class DSU {
//private:
//    std::vector<int> parent;
//    std::vector<int> rank;
//
//public:
//    DSU(int n) : parent(n + 1), rank(n + 1, 0) {
//        for (int i = 0; i <= n; ++i)
//            parent[i] = i;
//    }
//
//    int find(int x) {
//        if (x != parent[x])
//            parent[x] = find(parent[x]);
//        return parent[x];
//    }
//
//    void unite(int x, int y) {
//        x = find(x);
//        y = find(y);
//        if (x != y) {
//            if (rank[x] < rank[y])
//                std::swap(x, y);
//            parent[y] = x;
//            if (rank[x] == rank[y])
//                rank[x]++;
//        }
//    }
//};
//
//int main() {
//    std::ifstream fin("input.txt");
//    std::ofstream fout("output.txt");
//
//    if (!fin.is_open())
//    {
//        std::cerr << "Error opening the file" << std::endl;
//        return 1;
//    }
//
//    int n, m, q;
//    fin >> n >> m >> q;
//
//    DSU dsu(n + 1);
//
//    std::vector<std::pair<int, int>> roads(m + 1);
//    for (int i = 1; i <= m; ++i)
//    {
//        fin >> roads[i].first >> roads[i].second;
//    }
//
//    std::vector<int> qs(q + 1);
//    for (int i = 1; i <= q; ++i)
//    {
//        fin >> qs[i];
//    }
//
//    std::stack<int> results;
//
//    int components = n;
//
//    for(int i = q; i > 0; --i)
//    {
//        results.push(components <= 1 ? 1 : 0);
//
//        if(dsu.find(roads[qs[i]].first) != dsu.find(roads[qs[i]].second))
//        {
//            dsu.unite(roads[qs[i]].first, roads[qs[i]].second);
//            components--;
//        }
//    }
//
//    while (!results.empty())
//    {
//        fout << results.top();
//        results.pop();
//    }
//
//    fin.close();
//    fout.close();
//
//    return 0;
//}