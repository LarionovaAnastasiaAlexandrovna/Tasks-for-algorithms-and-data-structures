#include <iostream>

class Solution {
public:

    unsigned long long static counting_B_using_Fermat_small_theorem(unsigned long long B, unsigned long long degree) // p - 2 !!!!
    {
        if (degree == 0)
            return 1;
        if (degree == 1)
            return B;
        if (degree % 2 == 0)
        {
            unsigned long long res = counting_B_using_Fermat_small_theorem(B, degree / 2);
            return res * res % 1000000007;
        }
        else
        {
            unsigned long long res = counting_B_using_Fermat_small_theorem(B, (degree - 1) / 2);
            return B * res % 1000000007 * res % 1000000007;
        }

    }
    int static calculates_the_number_of_binary_strings_of_length_N_in_which_there_are_exactly_K_units(int N, int K)
    {
        if (K == 0 || N == 0 || N == K) return 1;
        unsigned long long res = 1, A = 1, B = 1;
        if (K > N / 2)
        {
            for (int i = 1; i <= N - K; ++i)
            {
                A = ((A % 1000000007) * (K + i) % 1000000007) % 1000000007;
                B = ((B % 1000000007) * (i) % 1000000007) % 1000000007;
            }
            res = (A * counting_B_using_Fermat_small_theorem(B, 1000000005)) % 1000000007;
        }
        else
        {
            for (int i = 0; i < K; ++i)
            {
                A = ((A % 1000000007) * (N - i) % 1000000007) % 1000000007;
                B = ((B % 1000000007) * (i + 1) % 1000000007) % 1000000007;
            }
            res = (A * counting_B_using_Fermat_small_theorem(B, 1000000005)) % 1000000007;
        }
        return res;
    }
};

int main() {
    int N, K;
    std::cin >> N >> K;
    std::cout << Solution::calculates_the_number_of_binary_strings_of_length_N_in_which_there_are_exactly_K_units(N, K);
    return 0;
}

//#include <iostream>
//
//class Solution{
//public:
//
//    unsigned long long static counting_B_using_Fermat_small_theorem(unsigned long long B, unsigned long long degree) // p - 2 !!!!
//    {
//        if (degree == 0)
//            return 1;
//        if(degree == 1)
//            return B;
//        if(degree % 2 == 0)
//        {
//            unsigned long long res = counting_B_using_Fermat_small_theorem(B, degree / 2);
//            return res * res % 1000000007;
//        }
//        else
//        {
//            unsigned long long res = counting_B_using_Fermat_small_theorem(B, (degree - 1) / 2);
//            return res * res * B % 1000000007;
//        }
//
//    }
//    int static calculates_the_number_of_binary_strings_of_length_N_in_which_there_are_exactly_K_units(int N, int K)
//    {
//        if(K == 0 || N == 0 || N == K) return 1;
//        unsigned long long res = 1, A = 1, B = 1;
//        if(K > N/2)
//        {
//            for(int i = 1; i <= N - K; ++i)
//            {
//                A = ((A % 1000000007) * (K + i) % 1000000007) % 1000000007;
//                B = ((B % 1000000007) * (i) % 1000000007) % 1000000007;
//            }
//            res = (A * counting_B_using_Fermat_small_theorem(B, 1000000005)) % 1000000007;
//        }
//        else
//        {
//            for(int i = 0; i < K; ++i)
//            {
//                A = ((A % 1000000007) * (N - i) % 1000000007) % 1000000007;
//                B = ((B % 1000000007) * (i + 1) % 1000000007) % 1000000007;
//            }
//            res = (A * counting_B_using_Fermat_small_theorem(B, 1000000005)) % 1000000007;
//        }
//        return res;
//    }
//};
//
//int main() {
//    int N, K;
//    std::cin >> N >> K;
//    std::cout << Solution::calculates_the_number_of_binary_strings_of_length_N_in_which_there_are_exactly_K_units(N, K);
//    return 0;
//}



//        double res = 1;
//        int j = N - K;
//        if(K == 0) return 1;
//        int C = N - K;
//        for (int c = 1; c <= C; c++)
//        {
//            res *= (K + c);
//
//        }



//        double res = 1;
//        int size_overflow = 1000000007;
//        int C = N - K;
//        int c = 1;
//        // res = n! / (k! * (n - k)!)
//        if (K == 0)
//        {
//            return 1;
//        }
//        for(int n = N; n > 0; --n)
//        {
//            res *= n;
//            if (c <= C)
//            {
//                res /= c;
//                res /= (N - c);
//                c++;
//            }
//        }
//        while (res > size_overflow)
//        {
//            res -= size_overflow;
//        }
//        return res;