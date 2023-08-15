#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size, n, j, k;
        size = strs.size();
        unordered_map<string, vector<string>> anagrams;
        
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagrams[sortedStr].push_back(str);
        }
        
        vector<vector<string>> result;
        for (const auto& entry : anagrams) {
            result.push_back(entry.second);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = solution.groupAnagrams(strs);
    
    for (const auto& group : groupedAnagrams) {
        cout << "[ ";
        for (const string& str : group) {
            cout << str << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
