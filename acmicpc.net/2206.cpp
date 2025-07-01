// 13:10
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define INF (1 << 30)
using namespace std;
vector<string> map;
int used[1001][1001][2];

int n, m;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int ans;
bool check(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}

//make_tuple
//get<0>(tuple t)
int solve()
{
	queue<tuple<int, int, int, int>> q;
	q.push({ 0, 0, 1, 0 });
	used[0][0][0] = 1;
	while (!q.empty())
	{
		int r = get<0>(q.front());
		int c = get<1>(q.front());
		int l = get<2>(q.front());
		int f = get<3>(q.front());
		q.pop();

		if (r == n - 1 && c == m - 1)
		{
			return l;
		}
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (!check(nr, nc))
			{
				continue;
			}

			if (map[nr][nc] == '0' && !used[nr][nc][f])
			{
				used[nr][nc][f] = 1;
				q.push({ nr, nc, l + 1, f });
			}
			else if (map[nr][nc] == '1' && f == 0 && !used[nr][nc][1])
			{
				used[nr][nc][1] = 1;
				q.push({ nr, nc, l + 1, 1 });
			}
		}
	}

	return -1;
}

int main()
{
	cin >> n >> m;

	map.assign(n, "");
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	cout << solve() << "\n";
}