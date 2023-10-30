#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> static findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        bool flag = false;
        if(nums1.size() < nums2.size())
            swap(nums1, nums2); flag = true;
        int j = 0;
        for(auto it : nums1) {
            if(it == nums2[j]) {
                remove(nums1.);
            }
        }
        // чёрт возьми как пройтись по двум векторам за один for удаляя одинаковые элементы?????

        if(flag) swap(nums1, nums2);
        vector<vector<int>> res = {nums1, nums2};
        return res;
    };
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for(int i = 0; i < n; ++i)
        cin >> nums1[i];
    for(int i = 0; i < m; ++i)
        cin >> nums2[i];
    vector<vector<int>> res = Solution::findDifference(nums1, nums2);
    for(int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

//5
//-5 1 5 0 -7

//7
//-4 -3 -2 -1 4 3 2


