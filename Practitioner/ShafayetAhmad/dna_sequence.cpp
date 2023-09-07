#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    unordered_map<string, int> m;
    vector<string> ans;
    if (s.size() <= 10)
        return ans;
    for (int i = 0; i <= s.size() - 10; i++)
    {
        string str = s.substr(i, 10);
        m[str]++;
        if (m[str] == 2)
            ans.push_back(str);
    }
    return ans;
}

int main()
{
    string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    return 0;
}