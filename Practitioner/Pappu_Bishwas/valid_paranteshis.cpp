#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> p;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (!p.empty() && ((p.top() == '(' && s[i] == ')') || (p.top() == '{' && s[i] == '}') || (p.top() == '[' && s[i] == ']'))) {
                p.pop();
            } else {
                p.push(s[i]);
            }
        }
        return p.empty();
    }
};

int main() {
    Solution solution;

    std::string s1 = "{[()]}";
    std::string s2 = "{[(])}";
    std::string s3 = "{{[[(())]]}}";

    std::cout << s1 << " is valid: " << (solution.isValid(s1) ? "true" : "false") << std::endl;
    std::cout << s2 << " is valid: " << (solution.isValid(s2) ? "true" : "false") << std::endl;
    std::cout << s3 << " is valid: " << (solution.isValid(s3) ? "true" : "false") << std::endl;

    return 0;
}
