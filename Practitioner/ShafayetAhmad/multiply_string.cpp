#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string multiply(string num1, string num2)
{
    int size1 = num1.size() - 1, size2 = num2.size();
    int ans = 1, mul = 1;
    while (size1 > 0)
    {
        ans *= num1[size1--];
        ans *= mul;
        mul *= 10;
    }
    mul = 1;
    while (size2 > 0)
    {
        ans *= num2[size2--];
        ans *= mul;
        mul *= 10;
    }
    return to_string(ans);
}

int main()
{
    string s1 = "123", s2 = "456";
    string ans = multiply(s1, s2);
    return 0;
}