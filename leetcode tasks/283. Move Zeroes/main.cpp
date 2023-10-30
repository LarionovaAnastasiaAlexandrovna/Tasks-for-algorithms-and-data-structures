#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0)
                nums[pos++] = nums[i];
        }
        for(; pos < nums.size(); pos++)
            nums[pos] = 0;
    }
//    void static moveZeroes(vector<int>& nums) {
//        for (int i = 0; i < nums.size(); i++) {
//            int stop = (int)nums.size() - 1;
//            if (nums[i] == 0) {
//                if(nums[i - 1] != 0) {
//                    swap(nums[i - 1], nums[i]);
//                    continue;
//                }
//                int k = i;
//                while (i < stop--)
//                {swap(nums[k], nums[k + 1]); k++;}
//            }
//        }
//    }
};

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for(int i = 0; i < size; i++)
        cin >> nums[i];
    Solution test;
    test.moveZeroes(nums);
    for(int i = 0; i < size; i++)
        cout << nums[i] << " ";
    return 0;
}
