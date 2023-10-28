#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        for (int i = 0; i < min(word1.size(), word2.size()); ++i)
        {
            result += word1[i];
            result += word2[i];
        }
        if(word1.size() == word2.size())
            return result;
        (word1.size() >= word2.size())
        ? result += word1.substr(word2.size(), word1.size() - word2.size())
        :  result += word2.substr(word1.size(), word2.size() - word1.size());
        return result;

    }
};

int main() {
    string word1, word2;
    getline(cin, word1);
    getline(cin, word2);
    Solution test;
    cout << test.mergeAlternately(word1, word2);

    return 0;
}
