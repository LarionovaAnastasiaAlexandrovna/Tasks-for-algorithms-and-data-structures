#include <iostream>
#include_next <vector>

using namespace std;

//class Solution {
//public:
//    vector<int> productExceptSelf(vector<int>& nums) {
//        int size = nums.size();
//        vector<int> left_side(size);
//        vector<int> right_side(size);
//        vector<int> ansver(size);
//        left_side[0] = 1;
//        right_side[4] = 1;
//        for(int i = 1; i < size; i++)
//            left_side[i] = left_side[i - 1] * nums[i - 1];
//        for (int i = size - 2; i >= 0; i--)
//            right_side[i] = right_side[i + 1] * nums[i + 1];
//        for(int i = 0; i < size; i++)
//            ansver[i] = left_side[i] * right_side[i];
//        return ansver;
//    }
//};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);
        res[0] = 1;
        for(int i = 1; i < size; i++)
            res[i] = res[i - 1] * nums[i - 1];
        int right = 1;
        for(int i = size - 1; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};


int main() {
    vector<int> nums, res;
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q;
        nums.push_back(q);
    }
    Solution test;
    res = test.productExceptSelf(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
