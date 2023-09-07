#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int r, m;
        r = ransomNote.length();
        m = magazine.length();
        unordered_map<char, int> fr;
        for (int i = 0; i < m; i++) {
            fr[magazine[i]]++;
        }
        for (int i = 0; i < r; i++) {
            if (fr[ransomNote[i]] == 0)
                return false;
            fr[ransomNote[i]]--;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Test cases
    string ransomNote1 = "a";
    string magazine1 = "b";
    bool result1 = solution.canConstruct(ransomNote1, magazine1);
    cout << "Can construct: " << result1 << endl;

    string ransomNote2 = "aa";
    string magazine2 = "aab";
    bool result2 = solution.canConstruct(ransomNote2, magazine2);
    cout << "Can construct: " << result2 << endl;

    return 0;
}
