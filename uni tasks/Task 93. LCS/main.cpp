#include <iostream>
#include <algorithm>

class Solution
{
public:
    void static LCS(int n, int* A, int* B)
    {
        int** matrix = new int*[n + 1];
        int* wayA = new int[n + 1];
        int* wayB = new int[n + 1];

        for (int i = 0; i <= n; ++i)
        {
            matrix[i] = new int[n + 1];
        }

        for (int i = 0; i <= n; ++i)
        {
            matrix[i][0] = 0;
            matrix[0][i] = 0;
            wayA[i] = 0;
            wayB[i] = 0;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if(A[i - 1] == B[j - 1])
                {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                }
                else
                {
                   matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }

        std::cout << matrix[n][n] << "\n";

        int i = n, j = n;
        while (i != 0 && j != 0)
        {
            if (A[i - 1] == B[j - 1])
            {
                wayA[i - 1] = 1;
                wayB[j - 1] = 1;
                i--;
                j--;
            }
            else if (matrix[i - 1][j] >  matrix[i][j - 1])
                {
                    i--;
                }
                else
                    j--;
            }

        for (int i = 0; i < n; ++i)
        {
            if(wayA[i])
                std::cout << i << " ";
        }
        std::cout << "\n";

        for (int i = 0; i < n; ++i)
        {
            if(wayB[i])
                std::cout << i << " ";
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    int* A = new int[n];
    int* B = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> A[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> B[i];
    }
    Solution::LCS(n, A, B);
    return 0;
}


//        if(matrix[n - 1][n - 1])
//        {
//            std::cout << matrix[n - 1][n - 1] + 1 << "\n";
//        }
//        else
//        {
//            std::cout << matrix[n - 1][n - 1] << "\n";
//        }
