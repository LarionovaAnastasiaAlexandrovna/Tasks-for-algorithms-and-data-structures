#include <iostream>
#include <vector>
#include <fstream>

class Solution {
public:
    void static ConstructAdjacencyList(int& n, int& m, std::ifstream& fin, std::ofstream& fout)
    {
        std::vector<std::vector<int>> adjacencyList(n + 1); // Используем вектор векторов для хранения списка смежности
        int u, v;

        for (int i = 0; i < m; ++i)
        {
            fin >> u >> v;
            adjacencyList[u].push_back(v); // Добавляем вершину v в список смежности вершины u
            adjacencyList[v].push_back(u); // Для неориентированного графа добавляем вершину u в список смежности вершины v
        }

        for (int i = 1; i <= n; ++i)
        {
            fout << adjacencyList[i].size() << " "; // Выводим количество смежных вершин
            for (int j = 0; j < adjacencyList[i].size(); ++j)
            {
                fout << adjacencyList[i][j] << " "; // Выводим номера смежных вершин
            }
            fout << std::endl;
        }
    }
};

int main() {
    std::ifstream fin("input.txt");
    if (!fin.is_open())
    {
        std::cerr << "Error";
        return 1;
    }
    std::ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    Solution::ConstructAdjacencyList(n, m, fin, fout);

    fin.close();
    fout.close();

    return 0;
}