#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int count = 0, len, i, j, k;
        len = s.length();
        vector<int> v;
        unordered_map<char, pair<int, int>> mp;
        for (i = 0; i < len; i++)           
        {
            if (mp[s[i]].first == 0)
            {
                mp[s[i]].first = i + 1; 
            }
            else
            {
                mp[s[i]].second = i + 1; 
            }
        }
        vector<vector<int>> intervals;

        for (const auto &entry : mp)
        {

            intervals.push_back({entry.second.first, entry.second.second});
        }
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back({intervals[0][0], intervals[0][1]});
        int n = intervals.size();
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= ans.back()[1])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
            {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        for ( i = 0; i < ans.size(); i++)
        {

            v.push_back(ans[i][1]-ans[i][0]+1);
        }
        

        return v;
    }
};

int main()
{
    Solution solution;

    // Test case
    string input = "abacccd";
    vector<int> result = solution.partitionLabels(input);

    cout << "Partition Labels: ";
    for (int length : result)
    {
        cout << length << " ";
    }
    cout << endl;

    return 0;
}
