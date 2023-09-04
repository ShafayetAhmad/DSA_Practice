#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        int n = s.length();
        if (n != t.length())
            return false;
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++) {
            if (freq[t[i]] == 0)
                return false;
            else
                freq[t[i]]--;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "anagram";
    string t1 = "nagaram";
    bool result1 = solution.isAnagram(s1, t1);
    cout << "Is anagram: " << result1 << endl;

    string s2 = "rat";
    string t2 = "car";
    bool result2 = solution.isAnagram(s2, t2);
    cout << "Is anagram: " << result2 << endl;

    return 0;
}
