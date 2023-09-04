#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v1, v2;
        v1.push_back(1);

        for (int i = 1; i <= rowIndex; i++) {
            v2.push_back(1);
            for (int j = 1; j < v1.size(); j++) {
                v2.push_back(v1[j - 1] + v1[j]);
            }
            v2.push_back(1);
            v1 = v2;
            v2.clear();
        }
        return v1;
    }
};

int main() {
    Solution solution;

    int rowIndex = 4;
    vector<int> row = solution.getRow(rowIndex);

    std::cout << "Row " << rowIndex << ": ";
    for (int num : row) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
