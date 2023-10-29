#include <iostream>
#include <fstream>
#include <vector>

class Solution
{
public:
    void static IsBinaryHeap(std::vector<int>& b, std::ofstream& fout) {
        int n = b.size();
        for (int i = 1; i < n; ++i) {
            if (2 * i < n && b[i] > b[2 * i]) {
                fout << "No";
                return;
            }
            if (2 * i + 1 < n && b[i] > b[2 * i + 1]) {
                fout << "No";
                return;
            }
        }
        fout << "Yes";
        return;
    }
};

int main() {
    std::ifstream fin("input.txt");
    int n;
    fin >> n;
    std::vector<int> bin_heap(n + 1);
    bin_heap[0] = 0;
    for (int i = 1; i <= n; ++i)
        fin >> bin_heap[i];
    fin.close();
    std::ofstream fout("output.txt");
    Solution::IsBinaryHeap(bin_heap, fout);
    return 0;
}




//void static IsBinaryHeap(std::vector<int>& b, std::ofstream& fout)
//{
//    int n = b.size()/2;
//    for (int i = 1; i <= n; ++i)
//    {
//        if(b[i] > b[2*i] || b[i] > b[2*i + 1])
//        {
//            fout << "No";
//            return;
//        }
//    }
//    fout << "Yes";
//    return;
//}