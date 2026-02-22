#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int max_l = -1, min_r = -1;
    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int l = 0, r = v.size() - 1;
    int res = (1 << 31) - 1;
    int pre = res;
    int memo_l, memo_r;
    int idx = 0;
    while(l < r)
    {
        int t = v[l] + v[r];
        if(abs(t) <= res)
        {
            memo_l = v[l];
            memo_r = v[r];
            res = abs(t);
        }
        if (abs(t) > pre)
        {
            pre = (1 << 31) - 1;
            l++;
            r++;
        }
        else
        {
            pre = abs(t);
            r--;
        }

    }

    cout << memo_l << " " << memo_r << '\n';
}