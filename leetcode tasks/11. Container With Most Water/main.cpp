#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = height.size() - 1, i = 0, volume = 0;
        while(i <= j) {
            int temp_volume = min(height[i], height[j]) * (j - i);
            if(temp_volume > volume)
                volume = temp_volume;
            height[i] > height[j] ? j-- : i++;
        }
        return volume;
    }
};

int main() {

    return 0;
}
