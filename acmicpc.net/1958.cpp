#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<vector<pii>> graph;
vector<int> dist;
vector<int> used;
int n;

void dfs(int node)
{
    for(int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i].first;
        int cost = graph[node][i].second;
        if(!used[next])
        {
            dist[next] = cost + dist[node];
            used[next] = 1;
            dfs(next);
        }
    }
}

void solve()
{
    dist.assign(n + 1, 0);
    used.assign(n + 1, 0);
    used[1] = 1;
    dfs(1);
    int m = 0;
    int idx = 0;
    for(int i = 1; i <= n; i++)
    {
        if(m < dist[i])
        {
            m = dist[i];
            idx = i;
        }
    }
    dist.assign(n + 1, 0);
    used.assign(n + 1, 0);
    used[idx] = 1;
    dfs(idx);

    int mm = 0;
    for(int i = 1; i <= n; i++)
    {
        mm = max(mm, dist[i]);
    }

    cout << mm << "\n";

}

int main()
{
    cin >> n;
    graph.assign(n + 1, vector<pii>());

    for(int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    solve();
}