#include <iostream>
#include <fstream>
#include <vector>

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DSU(int n) : parent(n + 1), rank(n + 1, 0) {
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
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

    int n, q;
    fin >> n >> q;

    DSU dsu(n);

    int components = n;

    for (int i = 0; i < q; ++i) {
        int u, v;
        fin >> u >> v;

        if (dsu.find(u) == dsu.find(v)) {
            fout << components << "\n";
        } else {
            dsu.unite(u, v);
            components--;
            fout << components << "\n";
        }
    }

    fin.close();
    fout.close();

    return 0;
}



//#include <cstdio>
//#include <algorithm>
//
//class DSU {
//private:
//    int *parent;
//    int *rank;
//
//public:
//    DSU(int n)
//    {
//        parent = new int[n + 1];
//        rank = new int[n + 1]();
//        for (int i = 0; i <= n; ++i)
//            parent[i] = i;
//    }
//
//    int find(int x)
//    {
//        if (x != parent[x])
//            parent[x] = find(parent[x]);
//        return parent[x];
//    }
//
//    void unite(int x, int y)
//    {
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
//
//    ~DSU()
//    {
//        delete[] parent;
//        delete[] rank;
//    }
//};
//
//int main() {
//    FILE *fin = fopen("input.txt", "r");
//    FILE *fout = fopen("output.txt", "w");
//
//    int n, q;
//    fscanf(fin, "%d %d", &n, &q);
//
//    DSU dsu(n + 1);
//
//    int components = n;
//
//    for (int i = 0; i < q; ++i)
//    {
//        int u, v;
//        fscanf(fin, "%d %d", &u, &v);
//        if(dsu.find(u) == dsu.find(v))
//        {
//            fprintf(fout, "%d\n", components);
//        }
//        else
//        {
//            dsu.unite(u, v);
//            components--;
//            fprintf(fout, "%d\n", components);
//        }
//    }
//
//    fclose(fin);
//    fclose(fout);
//
//    return 0;
//}



//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <sstream>
//
//int main() {
//    std::ifstream fin("input.txt");
//    std::ofstream fout("output.txt");
//    if (!fin.is_open()) {
//        std::cerr << "Error opening the file" << std::endl;
//        return 1;
//    }
//
//    std::string str;
//    std::getline(fin, str);
//    std::stringstream ss(str);
//    int n, connectAmount;
//    ss >> n >> connectAmount;
//
//    std::vector<int> list(n + 1, -1);
//    int connections = n;
//
//    for (int i = 0; i < connectAmount; i++)
//    {
//        std::getline(fin, str);
//        std::stringstream ss(str);
//        int first, second;
//        ss >> first >> second;
//
//        while (list[first] >= 0)
//        {
//            first = list[first];
//        }
//        while (list[second] >= 0)
//        {
//            second = list[second];
//        }
//        if (second == first)
//        {
//            fout << connections << std::endl;
//        }
//        else
//        {
//            if (std::abs(list[first]) > std::abs(list[second]))
//            {
//                list[first] += list[second];
//                list[second] = first;
//            }
//            else
//            {
//                list[second] += list[first];
//                list[first] = second;
//            }
//            connections--;
//            fout << connections << std::endl;
//        }
//    }
//
//    fin.close();
//    fout.close();
//    return 0;
//}



//#include <cstdio>
//#include <vector>
//#include <iostream>
//
//class DSU {
//private:
//    std::vector<int> parent;
//    std::vector<int> rank;
//
//public:
//    DSU(int n) {
//        parent.resize(n);
//        rank.assign(n, 0);
//        for (int i = 0; i < n; ++i)
//            parent[i] = i;
//    }
//
//    int find(int x) {
//        if (x != parent[x])
//            parent[x] = find(parent[x]); // Path Compression
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
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(NULL);
//    FILE *fin = fopen("input.txt", "r");
//    FILE *fout = fopen("output.txt", "w");
//
//    int n, q;
//    fscanf(fin, "%d %d", &n, &q);
//
//    DSU dsu(n + 1);
//
//    for (int i = 0; i < q; ++i) {
//        int u, v;
//        fscanf(fin, "%d %d", &u, &v);
//        dsu.unite(u, v);
//
//        int components = 0;
//        for (int j = 1; j <= n; ++j) {
//            if (dsu.find(j) == j)
//                components++;
//        }
//        fprintf(fout, "%d\n", components);
//    }
//
//    fclose(fin);
//    fclose(fout);
//
//    return 0;
//}
