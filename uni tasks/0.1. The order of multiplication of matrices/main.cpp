#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int size, temp;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> size;
    /*int* a = new int[size];
    int* b = new int[size];*/

    vector <int> a(size);
    vector <int> b(size);
    vector <int> array_k; // зачем он?

    for (int i = 0; i < size; i++)
    {
        in >> a[i] >> b[i];
    }
    int** matrix = new int* [size + 1];
    for (int i = 0; i <= size; i++)
    {
        matrix[i] = new int[size + 1];
        // здесь можно просто matrix[i][i] = 0; вместо цикла
        for (int j = 0; j <= size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i <= size; i++)
    {
        matrix[i][i] = 0;
        if (i != size)
            matrix[i][i + 1] = a[i] * b[i] * b[i + 1]; // тут ты сделал базу ДП, окей
        /*for (int j = 0; j < size; j++)
        {
          if (i==j) matrix[i][j] = 0;
          if (j == i + 1 && i != size - 1) matrix[i][j] = a[i] * b[i] * b[i + 1];
        }*/
    }

    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            out << matrix[i][j] << " ";
        }
        out << "\n";
    }
    out << "\n"; // это ты вывел матрицу с базой ДП для проверки, ок

    for (int length_of_the_matrix_group = 2; length_of_the_matrix_group <= size; length_of_the_matrix_group++)
        /* то есть мы начинаем рассматривать сначала группу из 2 матриц, потом из 3 и т д,
         * при этом поднимаясь по диагоналям выше */
    {
        for (int i = 1; i <= size - length_of_the_matrix_group + 1; i++)
            // то есть i идёт от 1 (т к база ДП уже есть) и до конца матрицы по диагонали
        {
            int j = i + length_of_the_matrix_group - 1; // то есть j c каждым циклом будет будет становиться на 1 больше
            //if (j > i && j != i + 1)
            //{
            for (int k = i; k < j; k++)
                {
                    matrix[i][j] = std::min(matrix[i][j], matrix[i][k] + matrix[k + 1][j] + (a[i - 1] * b[k] * b[j]));

                    //array_k.push_back(matrix[i][k] + matrix[k + 1][j] + a[i] * b[k] * b[j]); // или a[i - 1]
                }
                //matrix[i][j] = *min_element(array_k.begin(), array_k.end());
                //array_k.clear();
            //}
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            out << matrix[i][j] << " ";
        }
        out << "\n";
    }
    out << "\n" << matrix[0][size - 1];

    return 0;
}

//#include <fstream>
//#include <algorithm>
//
//class Solution
//{
//public:
//    int static find_ansver(int s, int* general)
//    {
//        int** matrix = new int*[s + 1];
//        for (int i = 0; i <= s; ++i)
//        {
//            matrix[i] = new int[s + 1];
//            matrix[i][i] = 0;
//        }
//
//        for (int l = 2; l <= s; ++l) // +
//        {
//            for (int i = 1; i <= s - l + 1; ++i)
//            {
//                int j = l + i - 1;
//                matrix[i][j] = INT_MAX;
//                for (int separator = i; separator < j; ++separator)
//                {
//                    matrix[i][j] = std::min(matrix[i][j],
//                                            matrix[i][separator]
//                                            + matrix[separator + 1][j]
//                                            + (general[i - 1] * general[separator] * general[j]));
//                }
//            }
//        }
//        return matrix[1][s];
//    }
//};
//
//int main() {
//    std::ifstream fin("input.txt");
//    int s;
//    fin >> s; // 2 ≤ s ≤ 100
//    int* n = new int[s];
//    int* m = new int[s];
//    for(int i = 0; i < s; ++i)
//    {
//        fin >> n[i] >> m[i]; // m[i] == n[i + 1]
//        fin.ignore();
//    }
//    fin.close();
//    int* general = new int[s + 1];
//    for(int i = 0; i < s; ++i)
//    {
//        general[i] = n[i];
//    }
//    general[s] = m[s - 1];
//
//    std::ofstream fout("output.txt");
//    fout << Solution::find_ansver(s, general);
//
//    fout.close();
//
//    delete[] n;
//    delete[] m;
//    delete[] general;
//
//    return 0;
//}
