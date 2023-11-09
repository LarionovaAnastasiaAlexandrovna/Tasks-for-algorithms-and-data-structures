#include <iostream>
#include <fstream>
#include <vector>

class Solution
{
public:
    void static some_fun(long long n, std::vector<long long>& some_vector, std::ofstream& fout)
    {
        long long i = 0;
        while (n)
        {
            if(n & 1)
            {
                some_vector[i] = 1;
            }
            i++;
            n >>= 1;
        }
        for(int j = 0; j < some_vector.size(); ++j)
        {
            if(some_vector[j])
                fout << j << "\n";
        }
    }
};

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    long long n, i = 0;
    std::vector<long long> some_vector(100, 0);

    fin >> n;

    Solution::some_fun(n, some_vector, fout);
    return 0;
}