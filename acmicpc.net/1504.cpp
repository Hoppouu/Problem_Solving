#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 30)
using namespace std;

vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
vector<int> dist;
int n, m;
void solve(int x)
{
    q.push({0, x});
    dist.assign(n + 1, INF);
    dist[x] = 0;
    while(!q.empty())
    {
        int cur = q.top().second;
        int cur_cost = q.top().first;
        q.pop();
        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].second;
            int next_cost = graph[cur][i].first;

            if(dist[next] > next_cost + dist[cur])
            {
                dist[next] = next_cost + dist[cur];
                q.push({next_cost, next});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    graph.assign(n + 1, vector<pair<int, int>>());
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    int a, b;
    cin >> a >> b;

    int sum = 0;
    solve(1);
    for(int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
    int q;
    if(dist[a] < dist[b])
    {
        q = a;
    }
    else
    {
        q = b;
    }
    int w = a + b - q;
    cout << q << " " << w << "\n";
    sum += dist[q];
    solve(w);
        for(int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
    sum += dist[w];
    solve(w);
        for(int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
    sum += dist[n];
    cout << sum << "\n";
}

/*
5 5
1 2 1
2 5 2
2 3 2
2 4 4
1 4 1
3 4
*/