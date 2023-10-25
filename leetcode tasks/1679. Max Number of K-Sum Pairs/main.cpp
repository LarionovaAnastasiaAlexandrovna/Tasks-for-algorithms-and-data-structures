#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int maxOperations(vector<int>& nums, int k) {
//        for(int i = 0; i < nums.size(); i++)
//            if(nums[i] > k) nums[i] = INT_MAX/2;
//        int q = nums.size()/2, i = 0, j = nums.size() - 1, count = 0;
//        while (q--) {
//            for(; i < nums.size(); i++) {
//                while (nums[i] == INT_MAX/2) i++;
//                while (i <= j) {
//                    while (nums[j] == INT_MAX/2) j--;
//                    if(nums[i] + nums[j] == k) {
//                        count++;
//                        nums[i] = INT_MAX/2;
//                        nums[j] = INT_MAX/2;
//                    }
//                    j--;
//                }
//            }
//            j = nums.size() - 1;
//        }
//        return count;
//    }
//};

//class Solution {
//public:
//    int maxOperations(vector<int>& nums, int k) {
//        for(int i = 0; i < nums.size(); i++)
//            if(nums[i] > k) nums[i] = INT_MAX/2;
//        int q = nums.size()/2, i = 0, j = nums.size() - 1, count = 0;
//        while (q--) {
//            for(; i < nums.size(); i++) {
//                while (i <= j) {
//                    while (nums[i] == INT_MAX/2) i++;
//                    while (nums[j] == INT_MAX/2) j--;
//                    while (nums[i] + nums[j] == k) {
//                        count++;
//                        nums[i++] = INT_MAX/2;
//                        nums[j--] = INT_MAX/2;
//                    }
//                    j--;
//                }
//                j = nums.size() - 1;
//            }
//        }
//        return count;
//    }
//};

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > k) nums[i] = INT_MAX/2;
        for(int i = 0, j = nums.size() - 1; i < j;) {
            if(nums[i] + nums[j] > k) j--;
            if(nums[i] + nums[j] < k) i++;
            while (nums[i] + nums[j] == k and i < j) {
                        count++;
                        nums[i++] = INT_MAX/2;
                        nums[j--] = INT_MAX/2;
                    }
        }
        return count;
    }
};

int main() {
    int n, k;
    cin >> k >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution test;
    cout << test.maxOperations(nums, k);

    return 0;
}
// 3 20
//2 5 4 4 1 3 4 4 1 4 4 1 2 1 2 2 3 2 4 2


// 3 20
//_ 5 4 4 _ 3 4 4 1 4 4 1 _ _ 2 2 3 2 4 2

