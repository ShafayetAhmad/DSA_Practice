#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        // step 1 transpose
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        // step 2 reverse every row
        for(int i = 0;i<n;i++){
            // row is matrix[i]
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

int main() {
    Solution solution;

    // Example 3x3 matrix
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    solution.rotate(matrix);

    // Print the rotated matrix
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
