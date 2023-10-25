#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0, i = 0;
        while(i < chars.size()) {
            int group_lenght = 1;
            while(i + group_lenght < chars.size() and chars[i] == chars[i + group_lenght])
                group_lenght++;
            chars[res++] = chars[i];
            if (!group_lenght - 1) continue;
            else {
                for ( char s : to_string(group_lenght)) chars[res++] = s;
            }
            i+= group_lenght;
        }
        return res;
    }
};


//ansver
//class Solution {
//public:
//    int compress(vector<char>& chars) {
//        int i = 0, res = 0;
//        while (i < chars.size()) {
//            int groupLength = 1;
//            while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i]) {
//                groupLength++;
//            }
//            chars[res++] = chars[i];
//            if (groupLength > 1) {
//                for (char c : to_string(groupLength)) {
//                    chars[res++] = c;
//                }
//            }
//            i += groupLength;
//        }
//        return res;
//    }
//};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
