#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        unordered_map<char,int> fr;
        for (int i=0;i<n;i++){
            fr[s[i]]++;
            
        }
        int l=0;
        for (int i=0;i<n;i++){
            if(fr[s[i]]%2==0) 
            {
                l+=fr[s[i]];
                fr[s[i]]=0;
            }
                
            else{
            
                l+=fr[s[i]]-1;
                fr[s[i]]=0;
            }  
        }        
        if(l<n)
            l+=1;
        return l;
    }
};

int main() {
    Solution solution;

    // Test cases
    string str1 = "abccccdd";
    int result1 = solution.longestPalindrome(str1);
    cout << "Longest palindrome length: " << result1 << endl;

    string str2 = "a";
    int result2 = solution.longestPalindrome(str2);
    cout << "Longest palindrome length: " << result2 << endl;

    return 0;
}
