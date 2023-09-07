#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> p;
        unordered_map<string, int> w;

        istringstream in(s);
        string word;
        int i = 0, n = pattern.size();

        for (word; in >> word; i++) {
            if (i == n || p[pattern[i]] != w[word]) {
                return false;
            }
            p[pattern[i]] = w[word] = i + 1;
        }
        return i == n;
    }
};

int main() {
    Solution solution;

    // Test cases
    string pattern1 = "abba";
    string s1 = "dog cat cat dog";
    cout << "Pattern matches: " << (solution.wordPattern(pattern1, s1) ? "true" : "false") << endl;

    string pattern2 = "abba";
    string s2 = "dog cat cat fish";
    cout << "Pattern matches: " << (solution.wordPattern(pattern2, s2) ? "true" : "false") << endl;

    string pattern3 = "aaaa";
    string s3 = "dog cat cat dog";
    cout << "Pattern matches: " << (solution.wordPattern(pattern3, s3) ? "true" : "false") << endl;

    string pattern4 = "abba";
    string s4 = "dog dog dog dog";
    cout << "Pattern matches: " << (solution.wordPattern(pattern4, s4) ? "true" : "false") << endl;

    return 0;
}
