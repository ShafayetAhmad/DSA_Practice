#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll size;
    cin >> size;
    vector<int> nums;
    for (int i = 1; i < size; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= size; i++)
    {
        if (nums[i - 1] != i)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}