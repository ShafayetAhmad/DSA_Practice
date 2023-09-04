#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m, n, i, j;
        m = matrix.size();
        n = matrix[0].size();
        for (i = 0; i < m && i < n; i++) {
            if (target >= matrix[i][i] && target <= matrix[i][n - 1]) {
                int s, e;
                s = i;
                e = n - 1;
                while (s <= e) {
                    int med = (s + e) / 2;
                    if (target == matrix[i][med])
                        return true;
                    else if (target > matrix[i][med])
                        s = med + 1;
                    else
                        e = med - 1;
                }
            }
            if (target >= matrix[i][i] && target <= matrix[m - 1][i]) {
                int s, e;
                s = i;
                e = m - 1;
                while (s <= e) {
                    int med = (s + e) / 2;
                    if (target == matrix[med][i])
                        return true;
                    else if (target > matrix[med][i])
                        s = med + 1;
                    else
                        e = med - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target = 5;
    bool result = solution.searchMatrix(matrix, target);

    if (result) {
        cout << "Element " << target << " found in the matrix." << endl;
    } else {
        cout << "Element " << target << " not found in the matrix." << endl;
    }

    return 0;
}
