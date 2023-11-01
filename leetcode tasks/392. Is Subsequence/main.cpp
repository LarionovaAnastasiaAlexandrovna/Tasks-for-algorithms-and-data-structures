#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) { // s <= t
        int m = s.size();
        int n = t.size();
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == m ? 1 : 0;
    }
};


int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    Solution test;
    cout << test.isSubsequence(s, t);
    return 0;
}

//        int size_s = s.size(), size_t = t.size(), i = 0, j = 0;
//        bool ansver = true;
//        while(size_s--) {
//            for(; i < size_t; i++, j++) {
//                if(t[i] == s[j] and j < size_s) continue;
//                else ansver = false;
//            }
//        }
//        return ansver;


//        while(size_s and size_t) {
//            if (s[i] == t[i]) {
//                size_s--; size_t--;
//            }
//            else size_t--;
//            i++;
//        }
//        return !size_s;


//        if(s.size() > t.size()) return false;
//        int size_s = s.size();
//        bool flag = true, flag2 = false;
//        for(int i = 0; i < size_s; i++) {
//            int j = i;
//            while (s[i] != t[j] and j < t.size()) {
//                j++; flag = false;
//            }
//            if(s[i] == t[j]) flag = true;  //if(j != s.size() - 1 and i _____) flag = true;
//            if(j == s.size() - 1)
//            if (flag == false) return false;
//        }
//        return flag;