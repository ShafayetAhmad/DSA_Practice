#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int col, row, i, k, j, tm;
        col = num1.length();
        row = num2.length();
        vector<int> v1;
        vector<int> v2;
        for (i = 0; i < col; i++)
        {
            tm = (num1[i] - 48);
            v1.push_back(tm);
        }
        for (i = 0; i < row; i++)
        {
            tm = (num2[i] - 48);
            v2.push_back(tm);
        }
        std::vector<std::vector<int>> mul(row, std::vector<int>(col + row, 0));

        i = row - 1;
        tm = col + row - 1;

        int t = 0,temp;
        while (i >= 0)
        {
            j = col - 1;
            k = tm;
            temp=0;
            while (j >= 0)
            {
                mul[t][k] = v2[i] * v1[j]+temp;
                if(mul[t][k]>9){
                    temp=mul[t][k];
                    mul[t][k]=mul[t][k]%10;
                    temp=temp/10;
                }else
                temp=0;
                k--;
                j--;
            }
            if(temp>0)
                mul[t][k]=temp;
            i--;
            tm--;
            t++;
        }

        i = row + col - 1;
        tm = col + row - 1;

        int sum = 0;
        string st;
        while (i >= 0)
        {
            j = 0;
            while (j < row)
            {
                sum += mul[j][i];
                j++;
            }
            if (sum > 9)
            {
                    int mod = sum % 10;
                    string s = to_string(mod);
                    st = s + st;
                    sum = sum / 10;

            }
            else
            {
                string s = to_string(sum);
                st = s + st;
                sum = 0;
            }
            i--;
        }

        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col + row; j++)
            {
                cout << mul[i][j] << " ";
            }
            cout << endl;
        }
        if(st[0]=='0')
        st.erase(0,1);
        return st;
    }
};

int main()
{
    Solution solution;
    string num1 = "123";
    string num2 = "456";

    string result = solution.multiply(num1, num2);
    cout << "Result: " << result << endl;

    return 0;
}
