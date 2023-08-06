#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> curRow;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    curRow.push_back(1);
                }
                else
                {
                    curRow.push_back(result[j - 1][i - 1] + result[j - 1][i]);
                }
            }
            result.push_back(curRow);
        }

        return result;
    }

    int main()
    {
        generate(5);
    }
};