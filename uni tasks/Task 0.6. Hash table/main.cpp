#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>

class Solution {
public:
    void static HashTableOperations(int m, int c, int n, std::ifstream& fin, std::ofstream& fout)
    {
        std::vector<int> table(m, -1);
        std::vector<int> keys(n);
        for (int i = 0; i < n; ++i)
        {
            fin >> keys[i];
        }
        std::unordered_set<int> seen;
        keys.erase(std::remove_if
                        (keys.begin(), keys.end(),
                         [&seen](const int& value)-> bool
                         {return !seen.insert(value).second;}),
                         keys.end());
        n = keys.size();

        for (int i = 0; i < n; ++i)
        {
            bool is_add = false;
            int j = 0;
            while (!is_add)
            {
                int pos = (keys[i] % m + c * j) % m;
                if (table[pos] == -1)
                {
                    table[pos] = keys[i];
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