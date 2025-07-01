//06:39
#include <iostream>
#include <vector>
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> graph;
vector<int> dist;
int n, m, w;
void solve()
{
	dist[1] = 0;
	for (int k = 0; k < n - 1; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			int cur_node = i;
			for (int j = 0; j < graph[cur_node].size(); j++)
			{
				int next_node = graph[cur_node][j].first;
				int next_cost = graph[cur_node][j].second;
				if (dist[cur_node] + next_cost < dist[next_node])
				{
					dist[next_node] = dist[cur_node] + next_cost;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int cur_node = i;
		for (int j = 0; j < graph[cur_node].size(); j++)
		{
			int next_node = graph[cur_node][j].first;
			int next_cost = graph[cur_node][j].second;

			if (dist[cur_node] + next_cost < dist[next_node])
			{
				cout << "YES\n";
				return;
			}
		}
	}

	cout << "NO\n";
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> w;
		graph.assign(n + 1, vector<pii>());
		dist.assign(n + 1, INF);
		int a, b, c;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			graph[a].push_back({ b, c });
			graph[b].push_back({ a, c });
		}
		for (int i = 0; i < w; i++)
		{
			cin >> a >> b >> c;
			graph[a].push_back({ b, -c });
		}
		solve();
	}
}