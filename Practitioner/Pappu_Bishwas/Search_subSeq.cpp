#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return false;

        int left = INT_MAX;
        int mid = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] > mid)
                return true;
            else if (nums[i] > left && nums[i] < mid)
                mid = nums[i];
            else if (nums[i] < left)
                left = nums[i];
        }

        return false;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 3, 4, 5};

    bool result = solution.increasingTriplet(nums);

    if (result) {
        cout << "There is an increasing triplet subsequence." << endl;
    } else {
        cout << "There is no increasing triplet subsequence." << endl;
    }

    return 0;
}
