#include <iostream>
#include <vector>
#include <fstream>

class Solution {
public:
    void static HashTableOperations(int m, int c, int n, std::ifstream& fin, std::ofstream& fout)
    {
        std::vector<int> table(m, -1);

        for (int i = 0; i < n; ++i)
        {
            int key;
            fin >> key;
            bool is_add = false;
            int j = 0;
            while (!is_add)
            {
                int pos = (key % m + c * j) % m;
                if (table[pos] == -1)
                {
                    table[pos] = key;
                    is_add = true;
                }
                j++;
            }
        }

        for (int i = 0; i < m; ++i)
        {
            fout << table[i] << " ";
        }
    }
};

int main()
{
    std::ifstream fin("input.txt");
    if (!fin.is_open())
    {
        std::cerr << "Error";
        return 1;
    }
    std::ofstream fout("output.txt");

    int m, c, n;
    fin >> m >> c >> n;

    Solution::HashTableOperations(m, c, n, fin, fout);

    fin.close();
    fout.close();

    return 0;
}