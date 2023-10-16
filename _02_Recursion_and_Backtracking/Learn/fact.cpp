#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int fact(int x)
{

    if (x <= 1)
        return 1;
    return x * fact(x - 1);
}

int main()
{
    int num;
    cin >> num;
    cout << fact(num) << endl;
    return 0;
}