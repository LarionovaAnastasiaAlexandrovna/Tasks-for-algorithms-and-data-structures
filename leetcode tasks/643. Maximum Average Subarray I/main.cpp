#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//1
//class Solution {
//public:
//    double findMaxAverage(vector<int>& nums, int k) {
//        int count = nums.size() - k + 1;
//        int average = INT_MIN;
//        for(int i = 0; i < count; i++) {
//            int j = k;
//            int temp = 0;
//            while (j--) {
//                temp += nums[i + j];
//            }
//            if(average < temp) average = temp;
//        }
//        return average/(double)k;
//    }
//};

//2
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double average = INT_MIN;
        if(nums.size() == 1)
            average = nums[0];
        for(int i = 1; i < k; i++)
            nums[i] += nums[i - 1];
        for(int i = k; i < nums.size(); i++)
            nums[i] += nums[i - 1] - nums[i - k] + nums[i - k - 1];
        for(int i = k - 1; i < nums.size(); i++)
            average = max(average, (double)nums[i]);
        return average/(double)k;
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    Solution test;
    cout << test.findMaxAverage(nums, k);
    return 0;
}
// 10 7
// 7 4 5 8 8 3 9 8 7 6