//11:55
#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<vector<pii>> graph;
vector<int> dist, route, ans;
vector<bool> visited;

void solve(int start, int dest)
{
	priority_queue<pii, vector<pii>, greater<pii>> q;
	dist.assign(n + 1, INF);
	route.assign(n + 1, 0);
	visited.assign(n + 1, false);
	q.push({ 0, start });
	dist[start] = 0;

	while (!q.empty())
	{
		int cur_node = q.top().second;
		q.pop();
		if (visited[cur_node])
		{
			continue;
		}
		visited[cur_node] = true;

		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i].first;
			int next_cost = graph[cur_node][i].second;

			if (dist[cur_node] + next_cost < dist[next_node])
			{
				route[next_node] = cur_node;
				dist[next_node] = dist[cur_node] + next_cost;
				q.push({ dist[next_node], next_node });
			}
		}
	}

	ans.push_back(dest);
	int i = dest;
	while ((i = route[i]) != 0)
	{
		ans.push_back(i);
	}
}

void print(int start, int dest)
{
	cout << dist[dest] << "\n";
	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i] << " ";
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
	print(start, dest);
}