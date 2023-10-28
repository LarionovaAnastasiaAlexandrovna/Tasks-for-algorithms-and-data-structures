#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0){
                if((i == 0 or flowerbed[i - 1] == 0) and
                   (i == flowerbed.size() - 1 or flowerbed[i + 1] == 0)){
                    flowerbed[i] = 1;
                    --n;
                    if(!n) return true;
                }
            }
        }
        return n <= 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
