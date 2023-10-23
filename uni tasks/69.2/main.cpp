#include <iostream>
#include <algorithm>

class Solution
{
public :
    static long long The_Frogs_Way (int* mass, int size, int* check_way)
    {
        if (size == 1)
        {
            std::cout << mass[0] << "\n";
            return 1;
        }
        if(size == 2)
        {
            return -1;
        }
        long long* way = new long long[size];
        way[0] = mass[0];
        way[1] = INT_MIN;
        way[2] = mass[2] + way[0];
        check_way[0] = 1;
        for(int i = 3; i < size; ++i) // 2 замена на 3
        {
            way[i] = std::max(way[i - 2], way[i - 3]) + mass[i];
        }
        int res = way[size - 1];
        check_way[size - 1] = 1;
        for(int i = size - 1; i > 0; )
        {
            if(way[i - 2] > way[i - 3])
            {
                check_way[i - 2] = 1;
                i -= 2;
            }
            else
            {
                check_way[i - 3] = 1;
                i -= 3;
            }
        }
        return res;
    }
};

int main() {
    int size;
    std::cin >> size;
    int* mass = new int[size];
    int* check_way = new int[size];
    for(int i = 0; i < size; ++i)
    {
        std::cin >> mass[i];
        check_way[i] = 0;
    }
    std::cout << Solution::The_Frogs_Way(mass, size, check_way) << "\n";
    for(int i = 0; i < size; ++i)
    {
        if(check_way[i] == 1)
            std::cout << i + 1 << " ";
    }

    delete[] mass;
    return 0;
}


//моё решение
//#include <iostream>
//#include <algorithm>
//
//class Solution
//{
//public :
//    static long long The_Frogs_Way (int* mass, int size, int* check_way)
//    {
//        if(size <= 2)
//        {
//            return -1;
//        }
//        long long* way = new long long[size];
//        way[0] = mass[0];
//        way[1] = INT_MIN;
//        check_way[0] = 1;
//        for(int i = 2; i < size; ++i)
//        {
//            way[i] = std::max(way[i - 2], way[i - 3]) + mass[i];
//        }
//        check_way[size - 1] = 1;
//        for(int i = 5; i < size; ) //2 or 3
//        {
//            if(way[i - 2] > way[i - 3])
//            {
//                check_way[i - 2] = 1;
//                i += 2;
//            }
//            else
//            {
//                check_way[i - 3] = 1;
//                i += 3;
//            }
//        }
//        return way[size - 1];
//    }
//};
//
//
//
//int main() {
//    //std::ifstream fin("input.txt");
//    int size;
//    std::cin >> size;
//    int* mass = new int[size];
//    for(int i = 0; i < size; ++i)
//    {
//        std::cin >> mass[i];
//    }
//    //fin.close();
//    int* check_way = new int[size];
//    for(int i = 1; i < size; ++i)
//    {
//        check_way[i] = 0;
//    }
//
//    //std::ofstream fout("output.txt");
//    std::cout << Solution::The_Frogs_Way(mass, size, check_way) << "\n";
//    for(int i = 0; i < size; ++i)
//    {
//        if(check_way[i] == 1)
//            std::cout << i + 1 << " ";
//    }
//    //fout.close();
//
//    delete[] mass;
//    return 0;
//}








//#include <iostream>
//#include <fstream>
//#include <vector>
//
//void The_Frogs_Way (std::vector<int>& vector)
//{
//    int size = vector.size();
//    if(size == 0 || size == 2)
//    {
//        std::ofstream fout("output.txt");
//        fout << "-1";
//        fout.close();
//    }
//    if(size == 1)
//    {
//        std::ofstream fout("output.txt");
//        fout << vector[0] << '\n' << "1";
//        fout.close();
//    }
//
//
//}
//
//int main() {
//    std::ifstream fin("input.txt");
//    int size, element;
//    fin >> size;
//    std::vector<int> vector(size);
//    for(int i = 0; i < size; ++i)
//    {
//        fin >> element;
//        vector.push_back(element);
//    }
//
//
//
//    fin.close();
//
//    std::ofstream fout("output.txt");
//
//    fout.close();
//    return 0;
//}







//#include <iostream>
//#include <fstream>
//#include <vector>
//
//void The_Frogs_Way (std::vector<int>& vector)
//{
//    int size = vector.size();
//    if(size == 0 || size == 2)
//    {
//        std::ofstream fout("output.txt");
//        fout << "-1";
//        fout.close();
//    }
//    if(size == 1)
//    {
//        std::ofstream fout("output.txt");
//        fout << vector[0] << '\n' << "1";
//        fout.close();
//    }
//
//
//}
//
//int main() {
//    std::ifstream fin("input.txt");
//    int size, element;
//    fin >> size;
//    std::vector<int> vector(size);
//    for(int i = 0; i < size; ++i)
//    {
//        fin >> element;
//        vector.push_back(element);
//    }
//
//
//
//    fin.close();
//
//    std::ofstream fout("output.txt");
//
//    fout.close();
//    return 0;
//}