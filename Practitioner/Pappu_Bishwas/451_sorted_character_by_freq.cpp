#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    std::string frequencySort(std::string s)
    {
        std::string st = "";
        std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::less<std::pair<int, char>>> maxHeap;
        std::unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        for (const auto &p : mp)
        {
            maxHeap.push({p.second, p.first});
        }

        while (!maxHeap.empty())
        {
            std::pair<int, char> p = maxHeap.top();
            maxHeap.pop();
            for (int i = 0; i < p.first; i++)
            {
                st += p.second;
            }
        }

        return st;
    }
};

int main()
{
    Solution solution;

    // Example usage:
    std::string input = "tree";
    std::string result = solution.frequencySort(input);

    std::cout << "Original String: " << input << std::endl;
    std::cout << "Sorted String: " << result << std::endl;

    return 0;
}
