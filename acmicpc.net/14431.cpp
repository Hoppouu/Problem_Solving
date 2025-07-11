//17:09
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

#define INF (1 << 30)
#define N 9000
using namespace std;
using pii = pair<int, int>;

struct edge
{
	int idx; //해당 인덱스의 점까지 거리
	int dist;
};

bool isPrime[N];
vector<pii> v;
vector<vector<edge>> adj;
vector<int> dist;

int n, X1, Y1, X2, Y2;

int calc_diff(int x1, int y1, int x2, int y2)
{
	int xx = x2 - x1;
	int yy = y2 - y1;
	return sqrt(xx * xx + yy * yy);
}

void solve()
{
	priority_queue<pii, vector<pii>, greater<pii>> q;

	q.push({0, 0});
	dist[0] = 0;
	while (!q.empty())
	{
		int cur_diff = q.top().first;
		int cur_idx = q.top().second;
		q.pop();
		if (dist[cur_idx] < cur_diff)
		{
			continue;
		}

		for (int i = 0; i < adj[cur_idx].size(); i++)
		{
			int next_idx = adj[cur_idx][i].idx;
			int next_diff = adj[cur_idx][i].dist;
			if (dist[cur_idx] + next_diff < dist[next_idx])
			{
				dist[next_idx] = dist[cur_idx] + next_diff;
				q.push({ dist[next_idx], next_idx });
			}
		}
	}
}

int main()
{
	fill_n(isPrime + 2, N, true);

	for (int i = 2; i * i < N; i++)
	{
		for (int j = i * i; j < N; j += i)
		{
			isPrime[j] = false;
		}
	}

	cin >> X1 >> Y1 >> X2 >> Y2;
	cin >> n;
	adj.assign(n + 2, vector<edge>());
	dist.assign(n + 2, INF);

	v.push_back({ X1, Y1 });
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	v.push_back({ X2, Y2 });

	for (int i = 0; i < v.size(); i++)
	{
		int x1 = v[i].first, y1 = v[i].second;
		for (int j = 0; j < v.size(); j++)
		{
			int x2 = v[j].first, y2 = v[j].second;
			int diff = calc_diff(x1, y1, x2, y2);

			if (isPrime[diff])
			{
				adj[i].push_back({ j, diff });
			}
		}
	}

	solve();

	cout << (dist[n + 1] == INF ? -1 : dist[n + 1]) << "\n";
}