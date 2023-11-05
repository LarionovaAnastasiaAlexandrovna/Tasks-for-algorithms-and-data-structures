#include <iostream>
#include <vector>
#include <fstream>

class Solution {
public:
    void static ConstructCanonicalRepresentation(int n, std::ifstream& fin, std::ofstream& fout) {
        std::vector<int> parents(n + 1, 0); // Создаем массив для хранения родителей каждой вершины
        int u, v;

        for (int i = 1; i < n; ++i)
        {
            fin >> u >> v;
            parents[v] = u; // Записываем, что вершина v имеет родителя u
        }

        for (int i = 1; i <= n; ++i) {
            fout << parents[i] << " "; // Выводим массив родителей в файл
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

    int n;
    fin >> n;

    Solution::ConstructCanonicalRepresentation(n, fin, fout);

    fin.close();
    fout.close();

    return 0;
}