#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int sumOfDigits(int num)
{
    int rem = num % 10;
    num = num / 10;
    return num + sumOfDigits(num);
}

int addDigits(int num)
{
    while (num / 10 != 0)
    {
        num = sumOfDigits(num);
    }
    return num;
}

int main()
{
    int num;
    cin >> num;
    cout << addDigits(num) << endl;
    return 0;
}