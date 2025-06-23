#include <iostream>
#include <vector>

#define INF ((1 << 30) - 1)
using namespace std;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> dist;
int n, m;

// 18:24
void solve() {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				dist[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			int next = graph[i][j].first;
			int cost = graph[i][j].second;
			dist[i][next] = min(dist[i][next], cost);
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
}


int main()
{
	cin >> n >> m;
	graph.assign(n + 1, vector<pair<int, int>>());
	dist.assign(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
	solve();


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";
		}
		cout << "\n";
	}
}