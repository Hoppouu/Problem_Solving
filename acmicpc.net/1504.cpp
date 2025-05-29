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
    q.push({ 0, x });
    dist.assign(n + 1, INF);
    dist[x] = 0;
    while (!q.empty())
    {
        int cur = q.top().second;
        int cur_cost = q.top().first;
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].second;
            int next_cost = graph[cur][i].first;

            if (dist[next] > next_cost + dist[cur])
            {
                dist[next] = next_cost + dist[cur];
                q.push({ next_cost, next });
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    graph.assign(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ c, b });
        graph[b].push_back({ c, a });
    }

    int a, b;
    cin >> a >> b;

    int sum = INF;
    if (dist[n] == INF || dist[a] == INF || dist[b] == INF)
    {
        sum = -1;
    }
    else
    {
        int t = 0;
        int q;
        int arr[2] = { a, b };
            solve(1);
        for (int i = 0; i < 2; i++)
        {
            q = arr[i];
            int w = a + b - q;
            t += dist[q];
            solve(q);
            t += dist[w];
            solve(w);
            t += dist[n];
            cout << t << "\n";
            sum = min(sum, t);
        }
    }

    cout << sum << "\n";
}