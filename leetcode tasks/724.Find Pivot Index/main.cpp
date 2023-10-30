#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int static pivotIndex(vector<int>& nums) {
//        int left_sum = 0, right_sum = 0;
//        int left_it = 0, right_it = nums.size() - 1;
//        if(nums[0] < nums[nums.size() - 1])
//            left_sum += nums[left_it++];
//        else if(nums[0] > nums[nums.size() - 1])
//            right_sum += nums[right_it--];
//        while(left_it < right_it) {
//            if(left_sum < right_sum )
//                left_sum += nums[left_it++];
//            else if(left_sum > right_sum)
//                right_sum += nums[right_it--];
//            else if(left_sum == right_sum) {
//                left_sum += nums[left_it++];
//                if(left_it < right_it) return -1;
//                right_sum += nums[right_it--];
//            }
//        }
//        if(left_sum == right_sum)
//            return left_it;
//        else
//            return -1;
//    }
//};

//class Solution {
//public:
//    int static pivotIndex(vector<int>& nums) {
//        int sum = 0;
//        int left_it = 0, right_it = nums.size() - 1;
//        while(left_it < right_it) {
//            if(sum == 0) {
//                if(nums[left_it] > nums[right_it])
//                    sum += nums[left_it++];
//                else
//                    sum -= nums[right_it--];
//            }
//            if(sum > 0)
//                sum -= nums[right_it--];
//            if(sum < 0)
//                sum += nums[left_it++];
//        }
//        if(sum == 0)
//            return left_it;
//        else
//            return -1;
//    }
//};


class Solution {
public:
    int static pivotIndex(vector<int>& nums) {
        int sum = 0;
        int left_it = 0, right_it = nums.size() - 1;
        for(int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        while(sum) {
            sum -= nums[right_it--];
        }
        if(left_it < right_it and sum == 0)
            return right_it - 1;
        else
            return -1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << Solution::pivotIndex(nums);
    return 0;
}

//6
//1 7 3 6 5 6

//