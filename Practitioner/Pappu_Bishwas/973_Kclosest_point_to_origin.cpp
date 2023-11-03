#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> maxhp;
        for (int i = 0; i < points.size(); i++)
        {
            int temp = pow(points[i][0], 2) + pow(points[i][1], 2);
            maxhp.push({temp, i});
        }
        for (int i = 0; i < k; i++)
        {
            pair<int, int> p = maxhp.top();
            maxhp.pop();
            ans.push_back({points[p.second][0], points[p.second][1]});
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    // Example usage with a vector of points and k value
    std::vector<std::vector<int>> points = {{1, 2}, {3, 4}, {5, 6}};
    int k = 2;

    std::vector<std::vector<int>> result = solution.kClosest(points, k);

    std::cout << "The " << k << " closest points are:" << std::endl;
    for (const auto &point : result)
    {
        std::cout << "(" << point[0] << ", " << point[1] << ")" << std::endl;
    }

    return 0;
}
