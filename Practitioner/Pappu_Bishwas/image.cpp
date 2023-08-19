#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n=matrix.size(),i,j,start,end,temp,curr,next;
        start=0;
        end=n-1;
        while (start<end)
        {
            j=start;
            while (j<end)
            {
            curr=matrix[start][start];
            for ( i = start; i < end; i++)
            {
                
                next=matrix[start][i+1];
            
                matrix[start][i+1]=curr;
                curr=next;

            }

            for ( i = start; i < end; i++)
            {
                
                next=matrix[i+1][end];
            
                matrix[i+1][end]=curr;
                curr=next;

            }
            for ( i = end; i > start; i--)
            {
                
                next=matrix[end][i-1];
            
                matrix[end][i-1]=curr;
                curr=next;

            }
            for ( i = end; i > start; i--)
            {
                
                next=matrix[i-1][start];
            
                matrix[i-1][start]=curr;
                curr=next;

            }      
            j++;     
            }
            
            start++;
            end--;
            
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
