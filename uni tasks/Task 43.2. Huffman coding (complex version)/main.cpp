#include <iostream>
#include <fstream>
#include <vector>

class Solution
{
public:
    void static Huffman(std::vector<long long>& h1, long long& res)
    {
        int i = 2, j = 0;
        long long temp;
        int n = h1.size() - 1;
        std::vector<long long> h2(n, LLONG_MAX);
        h2[0] = h1[0] + h1[1];
        int count = 1;
        for(int x = 0; x < n - 1; ++x)
        {
            if (i >= n + 1)
            {
                h2[count++] = h2[j + 1] + h2[j];
                j += 2;
            }
            else if(h1[i] < h2[j])
            {
                temp = h1[i];
                i++;
                if((i < n + 1) && h1[i] < h2[j])
                {
                    h2[count++] = temp + h1[i];
                    i++;
                }
                else
                {
                    h2[count++] = temp + h2[j];
                    j++;
                }
            }
            else
            {
                temp = h2[j];
                j++;
                if((i < n + 1) && h1[i] < h2[j])
                {
                    h2[count++] = temp + h1[i];
                    i++;
                }
                else
                {
                    h2[count++] = temp + h2[j];
                    j++;
                }
            }
        }
        for (int j = 0; j < count; ++j)
        {
            res += h2[j];
        }
    }
};

int main() {
    std::ifstream fin("huffman.in");
    if(!fin.is_open())
        std::cerr << "Error";
    long long n, res = 0;
    fin >> n;
    std::vector<long long> h1(n);
    for (int i = 0; i < n; ++i)
        fin >> h1[i];
    fin.close();
    std::ofstream fout("huffman.out");
    Solution::Huffman(h1, res);
    fout << res;
    fout.close();
    return 0;
}



//int i = 2, j = 0, number_of_iterations = h1.size() - 2;
//std::vector<long long> h2(h1.size() - 1, LLONG_MAX);
//h2[0] = h1[0] + h1[1];
//while (number_of_iterations--)
//{
//if(i == h2.size())
//{
//h2[j + 1] = h1[i] + h2[j];
//}
//else if (h1[i] <= h2[j] && h1[i + 1] <= h2[j])
//{
//h2[j + 1] = h1[i] + h1[i + 1];
//i += 2;
//j += 1;
//}
//else if (h1[i] <= h2[j] && h1[i + 1] > h2[j])
//{
//h2[j + 1] = h1[i] + h2[j];
//i += 1;
//j += 1;
//}
//else if (h1[i] > h2[j] && h1[i] > h2[j - 1])
//{
//h2[j + 1] = h2[j] + h2[j - 1];
//j += 1;
//}
//}
//for(int i = 0; i < h1.size() - 1; ++i)
//res += h2[i];
//return;
//}

//        int j = 0, i = 2, n = huff1.size() - 1;
//        std::vector<long long> huff2(n);
//        huff2[0] = huff1[0] + huff1[1];
//        for (int x = 0; x < n; ++x)
//        {
//            if(i == n)
//            {
//                huff2[j + 1] = huff1[i] + huff2[j];
//                break;
//            }
//            else if (huff1[i] <= huff2[j] && huff1[i + 1] <= huff2[j])
//            {
//                huff2[j + 1] = huff1[i] + huff1[i + 1];
//                j++;
//                i += 2;
//            }
//            else if (huff1[i] <= huff2[j] && huff1[i + 1] > huff2[j])
//            {
//                huff2[j + 1] = huff1[i] + huff2[j];
//                i++;
//                j++;
//            }
//            else if( huff1[i] > huff2[j])
//            {
//                huff2[j + 1] = huff2[j] + huff2[j - 1];
//                j++;
//            }
//        }
//        for(int i = 0; i < n - 1; ++i)
//            res += huff2[i];
//        return;



//        for(int i = 2; i < huff1.size(); ) // - 1?
//        {
//            if (huff1[i] < huff2[j])
//            {
//                if(huff1[i + 1] < huff2[j])
//                {
//                    temp = huff2[j + 1] = huff1[i] + huff1[i + 1];
//                    i += 2;
//                }
//                else //
//                {
//                    temp = huff2[j + 1] = huff1[i]
//                }
//                temp = huff1[i] + huff1[i + 1];
//                huff1[i] = huff1[i + 1] = INT_MAX;
//                i++;
//                huff2[j + 1] = temp;
//            }
//            else if (huff1[i] > huff2[j])
//            {
//
//                temp = huff2[j] + huff2[j + 1];
//                huff1[i] = huff1[i + 1] = INT_MAX;
//                j++;
//                huff2[j + 1] = temp;
//            }
//            else if (huff1[i] == huff2[j])
//            {
//                temp = huff2[j + 1] = huff1[i] + huff2[j];
//                res += temp;
//                i++; j++;
//
//            }
//        }