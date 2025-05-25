#include <iostream>
#include <vector>
#include <queue>
#define INF ((1 << 31) - 1)
using namespace std;

vector<pair<int, int>> graph[20001];
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int n, m, s;

void solve(int x)
{
    q.push({0, x});
    dist[x] = 0;
    while(!q.empty())
    {
        int cur_cost = q.top().first;
        int cur = q.top().second; q.pop();
        if(dist[cur] < cur_cost)
        {
            continue;
        }
        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int price = graph[cur][i].second;
            //next까지 거리 > 현재(cur)까지의 거리 + 현재에서 next까지의 가중치
            if(dist[next] > dist[cur] + price)
            {
                dist[next] = dist[cur] + price;
                q.push({dist[next], next});
            }
        }
    }
}
void print()
{
    for(int i = 1; i <= n; i++)
    {
        cout << (dist[i] == INF ? "INF" : to_string(dist[i])) << "\n";
    }
}

int main()
{
    cin >> n >> m >> s;
    dist.assign(n + 1, INF);
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    solve(s);
    print();
}