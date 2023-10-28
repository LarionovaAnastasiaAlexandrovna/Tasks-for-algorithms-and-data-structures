#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

//class Solution {
//public:
//    string reverseWords(string s) {
//        vector<string> words;
//        string res = "";
//        while(' ' == s[0])
//            s.erase(0, 1);
//        while(' ' == s[s.size() - 1])
//            s = s.substr(0, s.size() - 1);
//        while(s.size())
//        {
//            words.push_back(s.substr(0, s.find_first_of(' ')));
//            s.erase(0, s.find_first_of(' '));
//            while(' ' == s[0])
//                s.erase(0, 1);
//        }
//        for(int i = words.size() - 1; i > 0; i--)
//            res += words[i] + " ";
//        res += words[0];
//        return res;
//    }
//};

//class Solution {
//public:
//    string reverseWords(string s) {
//        vector<string> words;
//        string res = "";
//        while(' ' == s[0])
//            s.erase(0, 1);
//        while(' ' == s[s.size() - 1])
//            s = s.substr(0, s.size() - 1);
//        while(s.size())
//        {
//            words.push_back(s.substr(0, s.find_first_of(' ')));
//            s.erase(0, s.find_first_of(' '));
//            while(' ' == s[0])
//                s.erase(0, 1);
//        }
//        for(int i = words.size() - 1; i > 0; i--)
//            res += words[i] + " ";
//        res += words[0];
//        return res;
//    }
//};

//class Solution {
//public:
//    string reverseWords(string &s){
//        stringstream ss(s);
//        string word, ans;
//        while(ss >> word){
//            ans = word + " " + ans;
//        }
//        return ans.substr(0, ans.size()-1);
//    }
//};

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        stack<string> stack;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') continue;
            string word = "";
            while(i < s.size() and s[i] != ' ') {
                word += s[i];
                i++;
            }
            stack.push(word);
        }
        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
            if(!stack.empty()) {
                res += " ";
            }
        }
        return res;
    }
};


int main() {
    string s;
    getline(cin, s);
    Solution test;
    cout << test.reverseWords(s);

    return 0;
}
