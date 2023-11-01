#include <iostream>

using namespace std;

//class Solution {
//public:
//    string reverseVowels(string s) {
//        string temp = "";
//        for (int i = 0; i < s.size(); i++)
//        {
//            if ( s[i] == 'a' or s[i] == 'A' or s[i] == 'e' or s[i] == 'E' or s[i] == 'i'
//            or s[i] == 'I' or s[i] == 'o' or s[i] == 'O' or s[i] == 'u' or s[i] == 'U')
//            {
//                temp += s[i];
//                s[i] = '$';
//            }
//        }
//        for (int i = 0; i < s.size(); i++)
//        {
//            if ( s[i] == '$')
//            {
//                s[i] = temp[temp.size() - 1];
//                temp = temp.substr(0, temp.size() - 1);
//            }
//        }
//        return s;
//    }
//};

class Solution {
public:
    bool IsVowel(char c)
    {
        if (c == 'a' or c == 'A' or c == 'e' or c == 'E' or c == 'i'
        or c == 'I' or c == 'o' or c == 'O' or c == 'u' or c == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int left_iter = 0;
        int right_iter = s.size() - 1;
        while (left_iter < right_iter)
        {
            while (!IsVowel(s[left_iter]) and left_iter != right_iter)
                left_iter++;
            while (!IsVowel(s[right_iter]) and left_iter != right_iter)
                right_iter--;
            swap(s[left_iter++], s[right_iter++]);

        }
        return s;
    }
};


int main() {
    string s;
    getline(cin, s);
    Solution test;
    cout << test.reverseVowels(s);

    return 0;
}
