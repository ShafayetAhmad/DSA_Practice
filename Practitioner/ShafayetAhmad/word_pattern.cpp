#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<string> strToVct(string s)
{
    string temp = "";
    vector<string> str;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            temp += s[i];
        }
        else
        {
            str.push_back(temp);
            temp = "";
        }
    }
    str.push_back(temp);
    return str;
}

int main()
{
    string s = "abba";
    string t = "dog dog dog dog";
    vector<string> str = strToVct(t);
    if (s.size() != str.size())
    {
        cout << "false" << endl;
        return 0;
    }
    map<char, string> pToStr;
    map<string, char> strToP;
    for (int i = 0; i < s.size(); i++)
    {
        if (pToStr.find(s[i]) == pToStr.end())
        {
            pToStr[s[i]] = str[i];
        }
        else
        {
            if (pToStr[s[i]] != str[i])
            {
                cout << "false" << endl;
                return 0;
            }
        }
    }

    cout << "true" << endl;
    return 0;
}