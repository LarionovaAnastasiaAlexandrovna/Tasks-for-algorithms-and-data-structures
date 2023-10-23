#include <iostream>

class Solution{
public:
    bool static binary_search(int const mass[], int size, int desired_element) // ==
    {
        int begin = 0;
        int end = size; // -1
        int median;
        while (begin < end)
        {
            median =  begin + (end - begin) / 2;  //(begin + end) / 2;
            if (desired_element == mass[median])
                return true;
            else if (desired_element < mass[median])
                end = median;
            else
                begin = median + 1;
        }
        return false;
    }

    int static index_of_the_first_element_greater_tha_nor_equal_to_x(int const mass[], int size, int desired_element) // >=
    {
        int begin = 0;
        int end = size; // -1
        int median;
        while (begin < end)
        {
            median =  begin + (end - begin) / 2;  //(begin + end) / 2;
            if(desired_element > mass[median])
                begin = median + 1;
            else
                end = median;
        }
        return begin;
    }

    int static index_of_the_first_element_greater_than_x(int const mass[], int size, int desired_element) // >
    {
        int begin = 0;
        int end = size; // -1
        int median;
        while (begin < end)
        {
            median =  begin + (end - begin) / 2;  //(begin + end) / 2;
            if (desired_element >= mass[median])
                begin = median + 1;
            else
                end = median;
        }
        return end;
    }
};

int main() {
    //1
    int size;
    std::cin >> size;
    //2
    int* mass = new int[size];
    for(int i = 0; i < size; ++i)
    {
        std::cin >> mass[i];
    }
    //3
    int count_requests;
    std::cin >> count_requests;
    //4
    int* requests = new int[count_requests];
    for(int i = 0; i < count_requests; ++i)
    {
        std::cin >> requests[i];
    }
    for(int i = 0; i < count_requests; ++i)
    {
        std::cout << (int)Solution::binary_search(mass, size, requests[i])
           << " " << (int)Solution::index_of_the_first_element_greater_tha_nor_equal_to_x(mass, size, requests[i])
           << " " << (int)Solution::index_of_the_first_element_greater_than_x(mass, size, requests[i]) << " " << "\n";
    }
    delete[] mass;
    delete[] requests;
    return 0;
}