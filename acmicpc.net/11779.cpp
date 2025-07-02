#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<vector<pii>> graph;
vector<int> dist;
vector<bool> visited;

void solve(int start, int dest)
{
	priority_queue<pii, vector<pii>, greater<pii>> q;
	dist.assign(n + 1, INF);
	visited.assign(n + 1, false);
	q.push({ 0, start });
	dist[start] = 0;

	while (!q.empty())
	{
		int cur_node = q.top().second;
		q.pop();
		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i].first;
			int next_cost = graph[cur_node][i].second;

			if (dist[cur_node] + next_cost < dist[next_node])
			{
				cout << next_node << "\n";
				dist[next_node] = dist[cur_node] + next_cost;
				q.push({ dist[next_node], next_node });
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dist[i] << " ";
	}
	cout << "\n";
}


int main()
{
	cin >> n >> m;
	graph.assign(n + 1, vector<pii>());
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
	int start, dest;
	cin >> start >> dest;
	solve(start, dest);
}