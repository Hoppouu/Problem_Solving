#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> cnt;
vector<bool> used;

int dfs(int x)
{
    used[x] = true;
    for(int i = 0; i < graph[x].size(); i++)
    {
        int next = graph[x][i];
        if(!used[next])
        {
            cnt[x] += dfs(next);
        }
    }

    return cnt[x] + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, R, Q;
    cin >> N >> R >> Q;
    graph.assign(N + 1, vector<int>());
    cnt.assign(N + 1, 0);
    used.assign(N + 1, false);
    for(int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(R);
    for(int i = 0; i < Q; i++)
    {
        int n;
        cin >> n;
        cout << cnt[n] + 1 << '\n';
    }
}