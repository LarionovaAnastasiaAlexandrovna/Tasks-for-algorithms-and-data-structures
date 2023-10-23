#include <iostream>
#include <algorithm>
#include <fstream>

class Solution
{
public:
    void static Palindrom(int lenght, int& res_length, std::string S, std::string& res_S)
    {
        int** matrix = new int*[lenght + 1];
        int* way = new int[lenght + 1];
        std::string reverse_S = S;
        std::reverse(reverse_S.begin(), reverse_S.end());

        for (int i = 0; i <= lenght; ++i)
        {
            matrix[i] = new int[lenght + 1];
        }

        for (int i = 0; i <= lenght; ++i)
        {
            matrix[i][0] = 0;
            matrix[0][i] = 0;
            way[i] = 0;
        }

        for (int i = 1; i <= lenght; ++i)
        {
            for (int j = 1; j <= lenght; ++j)
            {
                if(S[i - 1] == reverse_S[j - 1])
                {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                }
                else
                {
                    matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }

        int i = lenght, j = lenght;
        while (i != 0 && j != 0)
        {
            if (S[i - 1] == reverse_S[j - 1])
            {
                way[i - 1] = 1;
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

        for (int i = 0; i < lenght; ++i)
        {
            if(way[i])
            {
                res_S += S[i];
                res_length++;
            }
        }
    }
};

int main() {
    std::string S;
    std::ifstream fin("input.txt");
    if(!fin.is_open())
        std::cerr << "Error open input.txt";
    fin >> S;
    fin.close();
    int res_length = 0;
    std::string res_S = "";
    Solution::Palindrom(S.length(), res_length, S, res_S);
    std::ofstream fout("output.txt");
    fout << res_length << "\n" << res_S;

    return 0;
}



//#include <fstream>
//#include <iostream>
//#include <string>
//
//class Soluton
//{
//public:
//    void static Palindrom(int lenght, int& res_length, std::string S, std::string& res_S)
//    {
//
//    }
//
//};
//
//int main() {
//    std::string S;
//    std::ifstream fin("input.txt");
//    if(!fin.is_open())
//        std::cerr << "Error open input.txt";
//    fin >> S;
//
//
//
//    return 0;
//}
