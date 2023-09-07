#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long> ps(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + arr[n - 1];
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << ps[b] - ps[a - 1] << endl;
    }
}