#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<char> st;
        string str = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ')' || s[i] == '(') {
                if (s[i] == ')' && !st.empty()) {
                    str += ")";
                    st.pop();
                } else if (s[i] == '(') {
                    str += "(";
                    st.push('(');
                }
            } else {
                str += s[i];
            }
        }
        while (!st.empty()) {
            str.erase(str.find_last_of('('), 1);
            st.pop();
        }
        return str;
    }
};

int main() {
    Solution solution;
    string input = "lee(t(c)o)de)";
    string result = solution.minRemoveToMakeValid(input);
    cout << "Original string: " << input << endl;
    cout << "Modified string: " << result << endl;
    return 0;
}
