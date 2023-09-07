#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};

    int prefix[8];
    prefix[0] = 0;
    int sum = 0;
    for (int i = 1; i <= 8; i++)
    {
        sum += arr[i];
        prefix[i] = sum;
    }

    int result[8];
    for (int i = 0; i < 8 - 3; i++)
    {
        result[i] = prefix[i + 3] - prefix[i];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;
}