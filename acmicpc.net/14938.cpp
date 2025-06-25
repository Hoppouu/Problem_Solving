// 01:10
#include <iostream>
#include <queue>
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> pi;
int n, m, r;
int items[101];
int graph[101][101];
int dist[101];
int visited[101];

void solve2(int start)
{
	priority_queue<pi, vector<pi>, greater<pi>> q;
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
		visited[i] = 0;
	}
	q.push({ 0, start });
	dist[start] = 0;

	while (!q.empty())
	{
		int cur_node = q.top().second;
		int cur_cost = q.top().first;
		q.pop();

		if (visited[cur_node])
		{
			continue;
		}
		visited[cur_node] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (graph[cur_node][i] != 0 && !visited[i])
			{
				int next_node = i;
				int next_cost = graph[cur_node][i];
				if (dist[cur_node] + next_cost < dist[next_node])
				{
					dist[next_node] = dist[cur_node] + next_cost;
					q.push({ dist[next_node], next_node });
				}
			}
		}
	}
}
int solve()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		solve2(i);
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[j] <= m)
			{
				sum += items[j];
			}
		}
		res = max(res, sum);
	}

	return res;
}
int main()
{
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		cin >> items[i];
	}

	for (int i = 0; i < r; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}

	cout << solve() << "\n";
}