#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // Your code here
        queue<int> q;
        int arr[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            q.push(i);
            arr[ch - 'a']++;
            while (!q.empty()) {
                if (arr[s[q.front()] - 'a'] > 1)
                    q.pop();
                else
                    break;
            }
        }
        if (q.empty())
            return -1;
        return q.front();
    }
};

int main() {
    Solution solution;
    
    // Test cases
    string input1 = "leetcode";
    int result1 = solution.firstUniqChar(input1);
    cout << "First unique character in '" << input1 << "': " << result1 << endl;
    
    string input2 = "loveleetcode";
    int result2 = solution.firstUniqChar(input2);
    cout << "First unique character in '" << input2 << "': " << result2 << endl;
    
    return 0;
}
