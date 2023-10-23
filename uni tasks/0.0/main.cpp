#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::vector<int> vector;
    std::ifstream fin("input.txt");
    long int temp = 0;
    while (!fin.eof())
    {
        fin >> temp;
        vector.push_back(temp);
    }
    fin.close();
    std::sort(vector.begin(), vector.end());
    vector.erase(unique(vector.begin(), vector.end()), vector.end());
    long long res = 0;
    for(int i = 0; i < vector.size(); ++i)
    {
        res += vector[i];
    }
    std::ofstream fout("output.txt");
    fout << res;
    fout.close();
    return 0;
}