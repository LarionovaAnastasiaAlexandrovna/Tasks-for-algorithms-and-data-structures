#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int static largestAltitude(vector<int>& gain) {
        int compar = 0;
        int real_high = 0;
        for(int i : gain) {
            real_high += i;
            compar = max(compar, real_high);
        }
        return compar;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> gain(n);
    for(int i = 0; i < n; ++i)
        cin >> gain[i];
    cout << Solution::largestAltitude(gain);
    return 0;
}

//5
//-5 1 5 0 -7

//7
//-4 -3 -2 -1 4 3 2