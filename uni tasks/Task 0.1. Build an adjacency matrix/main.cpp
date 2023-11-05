#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Solution
{
public:
    void static Construct_an_adjacency_matrix(int& m, int& n, ifstream& fin, ofstream& fout)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            fin >> u >> v;
            matrix[u - 1][v - 1] = 1;
            matrix[v - 1][u - 1] = 1;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                fout << matrix[i][j] << " ";
            }
            fout << endl;
        }
    }
};

int main() {
    ifstream fin("input.txt");
    if(!fin.is_open())
        cerr << "Error";
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    Solution::Construct_an_adjacency_matrix(m, n, fin, fout);

    fin.close();
    fout.close();

    return 0;
}
