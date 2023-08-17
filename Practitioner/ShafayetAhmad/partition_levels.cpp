#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> partitionLabels(string s)
{
    unordered_map<char, int> lastOcc;
    vector<int> ans;

    for (int i = 0; i < s.size(); i++)
    {
        lastOcc[s[i]] = i;
    }
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++)
    {
        end = max(end, lastOcc[s[i]]);
        if (i == end)
        {
            ans.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return ans;
}

int main()
{

    string s = "ababcbacadefegdehijhklij";
    vector<int> ans = partitionLabels(s);
    return 0;
}