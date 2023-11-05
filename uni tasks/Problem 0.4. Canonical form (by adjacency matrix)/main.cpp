#include <iostream>
#include <vector>
#include <fstream>

class Solution {
public:
    void static ConstructCanonicalRepresentation(int n, std::ifstream& fin, std::ofstream& fout)
    {
        std::vector<std::vector<int>> adjacencyMatrix(n, std::vector<int>(n, 0));

        std::vector<int> parents(n + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                fin >> adjacencyMatrix[i][j];
                if (adjacencyMatrix[i][j] == 1)
                {
                    parents[j + 1] = i + 1;
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            fout << parents[i] << " ";
        }
    }
};

int main() {
    std::ifstream fin("input.txt");
    if (!fin.is_open()) {
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
