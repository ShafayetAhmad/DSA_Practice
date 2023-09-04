#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 8, 2, 0, 1, 6, 4, 2};
    int pref[9];
    pref[0] = 0;
    for (int i = 1; i < 9; i++)
    {
        pref[i] = pref[i - 1] + arr[i - 1];
    }
    for (int i = 0; i < 9; i++)
    {
        cout << pref[i] << " ";
    }
    cout << endl;
}