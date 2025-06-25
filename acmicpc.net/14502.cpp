// 22:27
#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 30)
using namespace std;

int map[8][8];
int isVisited[8][8];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
vector<pair<int, int>> v;
int n, m, cnt, all, ans;

bool check(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}

void bfs()
{
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (check(nr, nc) && map[nr][nc] == 0 && !isVisited[nr][nc])
			{
				q.push({ nr, nc });
				isVisited[nr][nc] = 1;
				cnt++;
			}
		}
	}
}
void set()
{
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			isVisited[i][j] = 0;
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		q.push({ v[i].first, v[i].second });
	}
}
void solve(int r, int c, int k)
{
	if (k == 3)
	{
		set();
		bfs();
		int t = all - 3 - cnt;
		ans = max(t, ans);
		return;
	}


	for (int i = r + c / m; i < n; i++)
	{
		for (int j = (i == (r + c / m) ? c % m : 0); j < m; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 3;
				solve(i, j + 1, k + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				v.push_back({ i, j });
			}
			else if (map[i][j] == 0)
			{
				all++;
			}
		}
	}
	solve(0, 0, 0);
	cout << ans << "\n";
}