#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int fun(int x)
{
    if (x == 0)
        return 0;
    fun(x - 1);

    cout << x << endl;
}

int main()
{
    fun(5);
    return 0;
}
