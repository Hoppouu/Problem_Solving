#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<bool> used;

int N, S, res = 0;
void solve(int sum, int next, int n, int k)
{
    if(n == k)
    {
        if(sum == S)
        {
            res++;
        }
        return;
    }
    if(used[k])
    {
        return;
    }
    for(int i = next; i < N; i++)
    {
        used[k] = true;
        solve(v[i] + sum, i + 1, n, k + 1);
        used[k] = false;
    }
}

int main()
{
    cin >> N >> S; 
    used.assign(N, false);
    v.assign(N, 0);
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    for(int i = 1; i <= N; i++)
    {
        solve(0, 0, i, 0);
    }
    cout << res << '\n';
}