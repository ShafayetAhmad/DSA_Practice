#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ps;
        vector<int> v1, v2;
        v1.push_back(1);
        ps.push_back(v1);
        for (int i = 1; i < numRows; i++) {
            v2.push_back(1);
            for (int j = 1; j < v1.size(); j++) {
                v2.push_back(v1[j - 1] + v1[j]);
            }
            v2.push_back(1);
            ps.push_back(v2);
            v1 = v2;
            v2.clear();
        }
        return ps;
    }
};

int main() {
    Solution solution;

    int numRows = 5;
    vector<vector<int>> pascalTriangle = solution.generate(numRows);

    for (const auto& row : pascalTriangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
