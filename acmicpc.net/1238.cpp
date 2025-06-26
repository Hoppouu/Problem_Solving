// 03:07

#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> pii;

int n, m, x;
vector<vector<pii>> graph;
vector<int> dist, home;

void solve1(int k)
{
	priority_queue<pii, vector<pii>, greater<pii>> q;
	dist.assign(n + 1, INF);
	q.push({ 0, k });
	dist[k] = 0;

	while (!q.empty())
	{
		int cur_node = q.top().second;
		int cur_cost = q.top().first;
		q.pop();
		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i].first;
			int next_cost = graph[cur_node][i].second;

			if (next_cost + dist[cur_node] < dist[next_node])
			{
				dist[next_node] = next_cost + dist[cur_node];
				q.push({ dist[next_node], next_node });
			}
		}
	}
}

int t = 0;
void solve()
{
	solve1(x);
	for(int i = 1; i <= n; i++)
	{
		home[i] = dist[i];
	}
	for(int i = 1; i <= n; i++)
	{
		solve1(i);
		t = max(t, home[i] + dist[x]);
	}
	
}
int main()
{
	cin >> n >> m >> x;
	
	graph.assign(n + 1, vector<pii>());
	dist.assign(n + 1, INF);
	home.assign(n + 1, INF);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
	solve();
	cout << t << "\n";
}