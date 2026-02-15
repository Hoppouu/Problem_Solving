#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
vector<int> dist;
vector<bool> used;
int n;

void dfs(int cur, int d)
{
    used[cur] = true;
    dist[cur] = d;

    for(int i = 0; i < tree[cur].size(); i++)
    {
        int next = tree[cur][i];
        if(!used[next])
        {
            dfs(next, d + 1);
        }
    }
}

int main()
{
    cin >> n;
    tree.assign(n + 1, vector<int>());
    dist.assign(n + 1, 0);
    used.assign(n + 1, false);

    int t_a, t_b;
    cin >> t_a >> t_b;
    int x;
    cin >> x;
    for(int i = 0; i < x; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);

    }
    dfs(t_a, 0);
    if(used[t_b])
    {
        cout << dist[t_b] << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
    
}