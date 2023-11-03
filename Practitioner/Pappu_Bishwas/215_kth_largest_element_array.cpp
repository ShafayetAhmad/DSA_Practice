#include <iostream>
#include <queue>
#include <vector>

class Solution
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= k && nums[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
            else if (i < k)
            {
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {3, 1, 4, 2, 5};
    int k = 3;

    int kthLargest = solution.findKthLargest(nums, k);

    std::cout << "The " << k << "th largest element is: " << kthLargest << std::endl;

    return 0;
}
