#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto p : mp)
        {
            minHeap.push({p.second, p.first});
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        while (!minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }


        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> topK = solution.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int num : topK)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
