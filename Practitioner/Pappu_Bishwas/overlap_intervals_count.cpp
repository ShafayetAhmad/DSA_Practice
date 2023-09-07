#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back({intervals[0][0], intervals[0][1]});
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < ans.back()[1]) {
                ans.back()[1] = min(ans.back()[1], intervals[i][1]);
                count++;
            } else {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return count;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> intervals = {
        {1, 3},
        {2, 4},
        {3, 5},
        {4, 6}
    };

    int result = solution.eraseOverlapIntervals(intervals);

    cout << "Number of intervals to remove: " << result << endl;

    return 0;
}
