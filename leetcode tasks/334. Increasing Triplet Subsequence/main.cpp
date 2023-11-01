#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    bool increasingTriplet(vector<int>& nums) {
//        int size = nums.size();
//        int temp;
//        for(int i = 1; i < size; i++) {
//            int j = i;
//            temp = nums[i - 1];
//            while(temp >= nums[j] and j < size - 1)
//                j++;
//            if (j != size - 1) {
//                temp = nums[j++];
//                while(j < size and temp >= nums[j]) j++;
//                if (j < size) return true;
//            }
//        }
//        return false;
//    }
//};


//class Solution {
//public:
//    bool increasingTriplet(vector<int>& nums) {
//        int size = nums.size();
//        int temp;
//        for(int i = 1; i < size; i++) {
//            int j = i;
//            temp = nums[i - 1];
//            while(temp >= nums[j] and j < size - 1) j++;
//            int k = ++j;
//            if (j != size - 1) {
//                temp = nums[j];
//                while(j < size and temp >= nums[j]) j++;
//                if (j < size) return true;
//            }
//            else {
//                temp = nums[k];
//                while(j < size and temp >= nums[k]) k++;
//                if (k < size) return true;
//            }
//        }
//        return false;
//    }
//};

// не моё совсем
//class Solution {
//public:
//    bool increasingTriplet(vector<int>& nums) {
//        int n = nums.size();
//        // left_min[i] will store the minimum from left till ith
//        vector<int> left_min(n);
//        // right_max[i] will store the maximum from right till ith
//        vector<int> right_max(n);
//        // fill left_min array
//        left_min[0] = nums[0];
//        for(int i = 1; i < n; i++)
//            left_min[i] = min(left_min[i - 1], nums[i]);
//        // fill right_max array
//        right_max[n - 1] = nums[n - 1];
//        for(int i = n - 2; i >= 0; i--)
//            right_max[i] = max(right_max[i + 1], nums[i]);
//        // check that is there any element which has smaller element on left side and greater element on right side
//        for(int i = 1; i < n - 1; i++) {
//            if(left_min[i - 1] < nums[i] && nums[i] < right_max[i + 1]) {
//                return true;
//            }
//        }
//        return false;
//    }
//};


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        // first will keep track of first element of triplet
        int first = INT_MAX;
        // second will keep track of second element of triple
        int second = INT_MAX;
        // second > first
        for(int i = 0; i < n; i++){
            if(nums[i] <= first){
                first = nums[i];
            }
            else if(nums[i] <= second){
                second = nums[i];
            }
            else
                return true;
        }
        return false;
    }
};


int main() {
    int n, temp;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        nums[i] = temp;
    }
    Solution test;
    cout << test.increasingTriplet(nums);

    return 0;
}
