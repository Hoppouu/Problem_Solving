#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<int> s;
unordered_set<int> sPs;
unordered_map<int, int> sMs;


int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    for(auto i = s.begin(); i != s.end(); i++)
    {
        for(auto j = s.begin(); j != s.end(); j++)
        {
            sPs.insert(*i + *j);
        }
    }

    for(auto i = s.begin(); i != s.end(); i++)
    {
        for(auto j = s.begin(); j != s.end(); j++)
        {
            sMs.insert({*i - *j, *j});
        }
    }

    int k = 0;
    for(auto i = sMs.begin(); i != sMs.end(); i++)
    {
        if(sPs.find(i->first) != sPs.end())
        {
            k = max(k, i->first + i->second);
        }
    }

    cout << k << "\n";
}