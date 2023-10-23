#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    static std::vector<std::vector<int>> make_matrix(int length, std::vector<int>& mass)
    {
        std::vector<std::vector<int>> S(length, std::vector<int>(length));
        for (int i = 0; i < length; ++i)
        {
            S[i][i] = mass[i];
        }

        for (int i = 0; i < length - 1; ++i)
        {
            S[i][i + 1] = S[i][i] + S[i + 1][i + 1];
        }

        for(int j = 1; j < length; ++j)
        {
            for(int i = j; i >= 0; --i)
            {
                if(i < j)
                    S[i][j] = S[i][j - 1] + S[i + 1][j] - S[i + 1][j - 1];
            }
        }
        return S;
    }

    static int find_ansver(int length, std::vector<int>& mass, std::vector<std::vector<int>>& S)
    {
        std::vector<std::vector<int>> F(length, std::vector<int>(length));
        for (int i = 0; i < length; ++i)
        {
            F[i][i] = mass[i];
        }
        for (int i = 0; i < length; ++i)
        {
            S[i][i] = mass[i];
        }

        for (int i = 0; i < length - 1; ++i)
        {
            F[i][i + 1] = std::max(F[i][i], F[i + 1][i + 1]);
        }

        for (int j = 2; j < length; ++j)
        {
            for (int i = j - 2; i >= 0; --i)
            {
                F[i][j] = S[i][j] - std::min(F[i][j - 1], F[i + 1][j]);
            }
        }
        return F[0][length - 1];
    }
};

int main()
{
    int length;
    std::ifstream fin("input.txt");
    fin >> length;
    std::vector<int> mass(length);
    for(int i = 0; i < length; ++i)
    {
        fin >> mass[i];
    }
    fin.close();

    std::vector<std::vector<int>> S = Solution::make_matrix(length, mass);

    std::ofstream fout("output.txt");
    fout << Solution::find_ansver(length, mass, S);
    fout.close();

    return 0;
}


/*#include <iostream>
#include <fstream>
#include <algorithm>

class Solution
{
public:
    static int** make_matrix(int lenght, int* mass)
    {
        int** S = new int*[lenght];
        for (int i = 0; i < lenght; ++i)
        {
            S[i] = new int[lenght];
        } // построена матрица для промежуточных сумм

        for (int i = 0; i < lenght; ++i)
        {
            S[i][i] = mass[i];
        }

        for (int i = 0; i < lenght - 1; ++i)
        {
            S[i][i + 1] = S[i][i] + S[i + 1][i + 1];
        } // база ДП сделана

        for(int j = 1; j < lenght; ++j)
        {
            for(int i = j; i >= 0; --i)
            {
                if(i < j)
                    S[i][j] = S[i][j - 1] + S[i + 1][j] - S[i + 1][j - 1];
            }
        }

//        for (int i = 0; i < lenght; ++i)
//        {
//            for (int j = 0; j < lenght; ++j)
//            {
//                std::cout << S[i][j] << " ";
//            }
//            std::cout << "\n";
//        }

        return S;
    } // работает полностью правильно



    static int find_ansver(int lenght, int* mass, int** S)
    {
        int** F = new int*[lenght];
        for (int i = 0; i < lenght; ++i)
        {
            F[i] = new int[lenght];
        }
        for (int i = 0; i < lenght; ++i)
        {
            F[i][i] = mass[i];
        }
        for (int i = 0; i < lenght; ++i)
        {
            S[i][i] = mass[i];
        }

        for (int i = 0; i < lenght - 1; ++i)
        {
            F[i][i + 1] = std::max(F[i][i], F[i + 1][i + 1]);
        }

        // база ДП выше
        for (int j = 2; j < lenght; ++j)
        {
            for (int i = j - 2; i >= 0; --i)
            {
                F[i][j] = S[i][j] - std::min(F[i][j - 1], F[i + 1][j]);
            }
        }

//        std::cout << "\n";
//        for (int i = 0; i < lenght; ++i)
//        {
//            for (int j = 0; j < lenght; ++j)
//            {
//                std::cout << F[i][j] << " ";
//            }
//            std::cout << "\n";
//        }
        return F[0][lenght - 1];
    }
};

int main()
{
    int length;
    std::ifstream fin("input.txt");
    fin >> length;
    int* way = new int[length];
    int* mass = new int[length];
    for(int i = 0; i < length; ++i)
    {
        way[i] = INT_MIN;
        fin >> mass[i];
    }
    fin.close();

    int** S = new int*[length];
    for (int i = 0; i < length; ++i)
    {
        S[i] = new int[length - i + 1];
    }

    S = Solution::make_matrix(length, mass);

    std::ofstream fout("output.txt");
    fout << Solution::find_ansver(length, mass, S);
    fout.close();

    return 0;
}*/

// было 11.10
/*#include <iostream>
#include <fstream>
#include <algorithm>

class Solution
{
public:
    static int** make_matrix(int lenght, int* mass)
    {
        int** S = new int*[lenght];
        for (int i = 0; i < lenght; ++i)
        {
            S[i] = new int[lenght];
        } // построена матрица для промежуточных сумм

        for (int i = 0; i < lenght; ++i)
        {
            S[i][i] = mass[i];
        }

        for (int i = 0; i < lenght - 1; ++i)
        {
            S[i][i + 1] = S[i][i] + S[i + 1][i + 1];
        } // база ДП сделана

        for(int j = 1; j < lenght; ++j)
        {
            for(int i = j; i >= 0; --i)
            {
                if(i < j)
                    S[i][j] = S[i][j - 1] + S[i + 1][j] - S[i + 1][j - 1];
            }
        }
        return S;
    } // работает полностью правильно



    static int find_ansver(int lenght, int* mass, int** S)
    {
        int** F = new int*[lenght];
        for (int i = 0; i < lenght; ++i)
        {
            F[i] = new int[lenght];
        }
        for (int i = 0; i < lenght; ++i)
        {
            F[i][i] = mass[i];
        }
        for (int i = 0; i < lenght; ++i)
        {
            S[i][i] = mass[i];
        }
        for (int i = 0; i < lenght - 1; ++i)
        {
            S[i][i + 1] = std::max(S[i][i], S[i + 1][i + 1]);
        }
        // база ДП выше
        for (int j = 1; j < lenght; ++j) // вопросы с индексами
        {
            for (int i = j; i >= 0; --i)
            {
                if(i < j)
                    F[i][j] = S[i][j] - std::min(F[i][j - 1], F[i + 1][j]);
            }
        }

        return F[0][lenght - 1];
    }
};

int main()
{
    int length;
    std::ifstream fin("input.txt");
    fin >> length;
    int* way = new int[length];
    int* mass = new int[length];
    for(int i = 0; i < length; ++i)
    {
        way[i] = INT_MIN;
        fin >> mass[i];
    }
    fin.close();

    int** S = new int*[length];
    for (int i = 0; i < length; ++i)
    {
        S[i] = new int[length - i + 1];
    }
    S = Solution::make_matrix(length, mass);
    //std::cout << S[0][length - 1] << "\n\n";
    std::cout << Solution::find_ansver(length, mass, S);

    std::ofstream fout("output.txt");
    fout << Solution::find_ansver(length, mass, S);
    fout.close();

    return 0;
}*/


// было до 05.10
//#include <iostream>
//#include <fstream>
//#include <list>
//
//int find_max_you(std::list<int>& list)
//{
//    int temp_begin = list.front();
//    int max_element = temp_begin;
//    auto i = list.end(); --i;
//
//    int temp_end = *i;
//    if(temp_begin < temp_end)
//    {
//        max_element = temp_end;
//        list.pop_back();
//    }
//    else if (temp_begin == temp_end)
//    {
//        auto iter_begin = list.begin();
//        iter_begin++;
//        auto iter_end = list.end();
//        iter_end--; iter_end--;
//        if(*iter_begin < *iter_end)
//        {
//            list.pop_front();
//        }
//        else
//        {
//            list.pop_back();
//        }
//    }
//    else
//    {
//        list.pop_front();
//    }
//    return max_element;
//}
//
//int find_max_my(std::list<int>& list)
//{
//    int temp_begin = list.front();
//    int max_element = temp_begin;
//    auto i = list.end(); --i;
//
//    int temp_end = *i;
//    if(temp_begin < temp_end)
//    {
//        max_element = temp_end;
//        list.pop_back();
//    }
//    else if (temp_begin == temp_end)
//    {
//        auto iter_begin = list.begin();
//        iter_begin++;
//        auto iter_end = list.end();
//        iter_end--; iter_end--;
//        if(*iter_begin > *iter_end)
//        {
//            list.pop_front();
//        }
//        else
//        {
//            list.pop_back();
//        }
//    }
//    else
//    {
//        list.pop_front();
//    }
//    return max_element;
//}
//
//long long find_result(std::list<int>& list)
//{
//    long long result = 0;
//    while (!list.empty())
//    {
//        result += find_max_my(list);
//        if(list.empty()) return result;
//        find_max_you(list);
//    }
//    return result;
//}
//
//int main() {
//    std::list<int> list;
//    std::ifstream fin("input.txt");
//    int size = 0, element = 0;
//    fin >> size;
//    for(int i = 0; i < size; ++i)
//    {
//        fin >> element;
//        list.push_back(element);
//    }
//    fin.close();
//    long long result = find_result(list);
//    std::ofstream fout("output.txt");
//    fout << result;
//    fout.close();
//    return 0;
//}








//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//void find_max_element(int mass[],int& begin_iter, int& end_iter, int& res)
//{
//    int max_element = mass[begin_iter];
//    if(max_element < mass[end_iter])
//    {
//        max_element = mass[end_iter];
//        end_iter--;
//    }
//    else
//    {
//        begin_iter++;
//    }
//    if(mass[begin_iter] < mass[end_iter])
//    {
//        end_iter--;
//    }
//    else
//    {
//        begin_iter++;
//    }
//    res+= max_element;
//}
//
//int find_res(int mass[], int size, int& begin_iter, int& end_iter)
//{
//    int res = 0;
//    if( begin_iter == end_iter)
//    {
//        return res;
//    }
//    return find_max_element(mass[size], begin_iter, end_iter, res);
//}
//
//int main()
//{
//    ifstream fin("input.txt");
//    int size = 0;
//    fin >> size;
//    int mass[size];
//    for(int i = 0; i < size; ++i)
//    {
//        fin >> mass[i];
//    }
//    fin.close();
//
//
//    //long long result = find_result(list);
//    ofstream fout("output.txt");
//    //fout << result;
//    fout.close();
//
//    return 0;
//}
//
//
////2
////#include <iostream>
////#include <fstream>
////#include <list>
////
////int find_max_you(std::list<int>& list)
////{
////    int temp_begin = list.front();
////    int max_element = temp_begin;
////    auto i = list.end(); --i;
////
////    int temp_end = *i;
////    if(temp_begin < temp_end)
////    {
////        max_element = temp_end;
////        list.pop_back();
////    }
////    else if (temp_begin == temp_end)
////    {
////        auto iter_begin = list.begin();
////        iter_begin++;
////        auto iter_end = list.end();
////        iter_end--; iter_end--;
////        if(*iter_begin < *iter_end)
////        {
////            list.pop_front();
////        }
////        else
////        {
////            list.pop_back();
////        }
////    }
////    else
////    {
////        list.pop_front();
////    }
////    return max_element;
////}
////
////int find_max_my(std::list<int>& list)
////{
////    int temp_begin = list.front();
////    int max_element = temp_begin;
////    auto i = list.end(); --i;
////
////    int temp_end = *i;
////    if(temp_begin < temp_end)
////    {
////        max_element = temp_end;
////        list.pop_back();
////    }
////    else if (temp_begin == temp_end)
////    {
////        auto iter_begin = list.begin();
////        iter_begin++;
////        auto iter_end = list.end();
////        iter_end--; iter_end--;
////        if(*iter_begin > *iter_end)
////        {
////            list.pop_front();
////        }
////        else
////        {
////            list.pop_back();
////        }
////    }
////    else
////    {
////        list.pop_front();
////    }
////    return max_element;
////}
////
////long long find_result(std::list<int>& list)
////{
////    long long result = 0;
////    while (!list.empty())
////    {
////        result += find_max_my(list);
////        if(list.empty()) return result;
////        find_max_you(list);
////    }
////    return result;
////}
////
////int main() {
////    std::list<int> list;
////    std::ifstream fin("input.txt");
////    int size = 0, element = 0;
////    fin >> size;
////    for(int i = 0; i < size; ++i)
////    {
////        fin >> element;
////        list.push_back(element);
////    }
////    fin.close();
////    long long result = find_result(list);
////    std::ofstream fout("output.txt");
////    fout << result;
////    fout.close();
////    return 0;
////}
//
//
//
//
////1
////#include <iostream>
////#include <fstream>
////#include <list>
////
////int find_max_my(std::list<int>& list)
////{
////    int temp_begin = list.front();
////    int max_element = temp_begin;
////    auto i = list.end(); --i;
////
////    int temp_end = *i;
////    if(temp_begin < temp_end)
////    {
////        max_element = temp_end;
////        list.pop_back();
////    }
////    else if (temp_begin == temp_end)
////    {
////        auto iter_begin = list.begin();
////        iter_begin++;
////        auto iter_end = list.end();
////        iter_end--; iter_end--;
////        if(*iter_begin < *iter_end)
////        {
////            max_element = *iter_begin;
////            list.pop_front();
////        }
////        else
////        {
////            max_element =*iter_end;
////            list.pop_back();
////        }
////    }
////    else
////    {
////        max_element = temp_begin;
////        list.pop_front();
////    }
////    return max_element;
////}
////
////int find_max(std::list<int>& list)
////{
////    int temp_begin = list.front();
////    int max_element = temp_begin;
////    auto i = list.end(); --i;
////
////    int temp_end = *i;
////    if(temp_begin < temp_end)
////    {
////        max_element = temp_end;
////        list.pop_back();
////    }
////    else if (temp_begin == temp_end)
////    {
////        auto iter_begin = list.begin();
////        iter_begin++;
////        auto iter_end = list.end();
////        iter_end--; iter_end--;
////        if(*iter_begin > *iter_end)
////        {
////            max_element = *iter_begin;
////            list.pop_front();
////        }
////        else
////        {
////            max_element =*iter_end;
////            list.pop_back();
////        }
////    }
////    else
////    {
////        max_element = temp_begin;
////        list.pop_front();
////    }
////    return max_element;
////}
////
////long long find_result(std::list<int>& list)
////{
////    long long result = 0;
////    while (!list.empty())
////    {
////        result += find_max_my(list);
////        if(list.empty()) return result;
////        find_max(list);
////    }
////    return result;
////}
////
////int main() {
////    std::list<int> list;
////    std::ifstream fin("input.txt");
////    int size = 0, element = 0;
////    fin >> size;
////    for(int i = 0; i < size; ++i)
////    {
////        fin >> element;
////        list.push_back(element);
////    }
////    fin.close();
////    long long result = find_result(list);
////    std::ofstream fout("output.txt");
////    fout << result;
////    fout.close();
////    return 0;
////}