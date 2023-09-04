#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        if (n == 1)
            return 1;
        int i = 0, m = trust.size();
        std::unordered_map<int, int> mp;
        std::unordered_map<int, int> fr;
        while (i < m) {
            mp[trust[i][1]]++;
            fr[trust[i][0]]++;
            i++;
        }
        for (auto p : mp) {
            if (p.second == (n - 1) && fr[p.first] == 0)
                return p.first;
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Example trust relationships
    std::vector<std::vector<int>> trust = {{1, 2}, {2, 3}, {3, 1}, {4, 3}, {4, 2}};

    int n = 4; // Number of people

    int judge = solution.findJudge(n, trust);

    if (judge != -1) {
        std::cout << "The judge is person " << judge << std::endl;
    } else {
        std::cout << "There is no judge in the town." << std::endl;
    }

    return 0;
}
