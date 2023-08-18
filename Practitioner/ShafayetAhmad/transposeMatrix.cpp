#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mat[3][3] =
        {{1, 2, 3},  // 1 4 7    00 10 20
         {4, 5, 6},  // 2 5 8    01 11 21
         {7, 8, 9}}; // 3 6 9    02 12 22
    // vector<vector<int>> mat2(mat[0].size(), vector<int>(mat.size()));
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}