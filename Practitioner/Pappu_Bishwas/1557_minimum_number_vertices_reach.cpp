#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> mp(n, 0);
        vector<int> ans;
        for (int i = 0; i < edges.size(); i++) {
            mp[edges[i][1]]++;
        }
        for (int i = 0; i < n; i++) {
            if (mp[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};

    vector<int> result = solution.findSmallestSetOfVertices(n, edges);

    cout << "Smallest set of vertices: ";
    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
