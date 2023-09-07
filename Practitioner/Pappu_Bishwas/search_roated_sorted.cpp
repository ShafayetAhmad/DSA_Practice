#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (target == nums[mid])
                return mid;
            else if (nums[start] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[start])
                    end = mid - 1;
                else
                    start = mid + 1;
            } else if (nums[mid] < nums[start]) {
                if (target < nums[mid] || target >= nums[start])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = solution.search(nums, target);

    if (result != -1) {
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found." << endl;
    }

    return 0;
}
