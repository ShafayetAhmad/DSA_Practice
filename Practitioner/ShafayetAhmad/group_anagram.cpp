#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<string>> group_anagram(vector<string> strs)
{
    vector<vector<string>> ans;
    for (int i = 0; i < strs.size(); i++)
    {
        vector<string> tempVct;
        string test = strs[i];
        tempVct.push_back(test);
        sort(test.begin(), test.end());
        for (int j = i + 1; j < strs.size(); j++)
        {
            string check = strs[j];
            sort(check.begin(), check.end());
            if (test == check)
            {
                tempVct.push_back(strs[j]);
                strs.erase(strs.begin() + j);
            }
        }
        ans.push_back(tempVct);
    }
    return ans;
}

int main()
{
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = group_anagram(str);
    return 0;
}