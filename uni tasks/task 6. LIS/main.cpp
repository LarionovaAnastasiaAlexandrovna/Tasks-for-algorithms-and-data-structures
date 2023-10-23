#include <iostream>
#include <fstream>
#include <algorithm>

class Solution
{
public:
    void static LIS(int n, int* A, int& res)
    {
        int* f = new int[n + 1];
        f[0] = INT_MIN;
        for (int i = 1; i <= n; ++i)
        {
            f[i] = INT_MAX;
        }
        for (int i = 0; i < n; ++i) {
            int temp = std::lower_bound(f, f + n, A[i]) - f;
            f[temp] = A[i];
        }
        for (int i = 0; i <= n; ++i)
        {
            if (f[i] == INT_MAX)
            {
                break;
            }
            if (f[res] < f[i])
            {
                res = i;
            }
        }
        if (n == 1)
        {
            res = 1;
        }
    }
};

int main() {
    int res = 0, n;
    std::ifstream fin ("input.txt");
    if (!fin.is_open())
        std::cerr << "Error open input.txt";
    fin >> n;
    int* A = new int[n];
    for (int i = 0; i < n; ++i)
    {
        fin >> A[i];
    }
    fin.close();

    Solution::LIS(n, A, res);

    std::ofstream fout ("output.txt");
    fout << res;
    fout.close();

    return 0;
}

/*#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    void static LIS(std::vector<int> vec, int& res)
    {
        int n = vec.size();
        std::vector<int> f(n);
//        for (int i = 0 ; i < n; ++i)
//        {
//            f[i] = 1;
//        }
        f[0] = vec[0];
        for (int i = 1; i < n; ++i)
        {
            int j = std::upper_bound(vec.begin(), vec.end() *//*vec.begin() + vec[i]*//*, vec[i]) - vec.begin();
            f[j] = vec[i];
//            int temp = 0;
//            for (int j = 0; j < i; ++j)
//            {
//                if (vec[i] > vec[j])
//                    temp = std::max(temp, f[j]);
//            }
//            f[i] = temp + 1;
                f[i] = f[j] + 1;
            res = std::max(res, j);
        }
        res--;
    }
};

int main() {
    int res = 0, n;
    std::ifstream fin ("input.txt");
    if (!fin.is_open())
        std::cerr << "Error open input.txt";
    fin >> n;
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        fin >> vec[i];
    }
    fin.close();

    Solution::LIS(vec, res);

    std::ofstream fout ("output.txt");
    fout << res;
    fout.close();

    return 0;
}*/


/*#include <iostream>
#include <fstream>
#include <algorithm>

class Solution
{
public:
    void static LIS(int n, int* A, int& res)
    {
        int* f = new int[n];
        int* path = new int[n]; // зачем он? это искомая подпоследовательность
        int len = 1; // это длина разобранного пути
        path[0] = A[0];
        f[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            if (A[i] > path[len - 1])
            {
                path[len] = A[i];
                len++;
                f[i] = len;
            }
            else
            {
                int pos = std::upper_bound(path, path + len, A[i]) - path;
                path[pos] = A[i];
                f[i] = pos + 1;
            }
            res = std::max(res, f[i]);
        }
    }
};

int main() {
    int res = 0, n;
    std::ifstream fin ("input.txt");
    if (!fin.is_open())
        std::cerr << "Error open input.txt";
    fin >> n;
    int* A = new int[n];
    for (int i = 0; i < n; ++i)
    {
        fin >> A[i];
    }
    fin.close();

    Solution::LIS(n, A, res);

    std::ofstream fout ("output.txt");
    fout << res;
    fout.close();

    return 0;
}*/

/*
#include <iostream>
#include <fstream>
#include <algorithm>

class Solution
{
public:
    void static LIS(int n, int* A, int& res)
    {
        int* f = new int[n];
        f[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            int *temp = std::upper_bound(A, A + i, A[i]);
            if (A[i] > A[(temp - A - 1)])
            {
                f[i] = f[temp - A - 1] + 1;
            }
            res = std::max(res, f[i]);
        }
    }
};

int main() {
    int res = 0, n;
    std::ifstream fin ("input.txt");
    if (!fin.is_open())
        std::cerr << "Error open input.txt";
    fin >> n;
    int* A = new int[n];
    for (int i = 0; i < n; ++i)
    {
        fin >> A[i];
    }
    fin.close();

    Solution::LIS(n, A, res);

    std::ofstream fout ("output.txt");
    fout << res;
    fout.close();

    return 0;
}
*/
