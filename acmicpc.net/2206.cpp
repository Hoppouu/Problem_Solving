#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 30)
using namespace std;
vector<string> map;
vector<vector<int>> used;
int n, m;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
bool flag = true;
int cnt, ans = INF;
bool check(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}

void solve(int r, int c)
{
	cnt++;
	if (r == n - 1 && c == m - 1)
	{
		ans = min(ans, cnt);
	}
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (check(nr, nc) && !used[nr][nc])
		{
			int t = cnt;
			used[nr][nc] = 1;
			if (map[nr][nc] == '0')
			{
				solve(nr, nc);
			}
			else if(flag && map[nr][nc] == '1')
			{
				map[nr][nc] = '0';
				flag = false;
				solve(nr, nc);
				flag = true;
				map[nr][nc] = '1';
			}
			cnt = t;
			used[nr][nc] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;

	map.assign(n, "");
	used.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}
	used[0][0] = 1;
	solve(0, 0);
	cout << (ans == INF ? -1 : ans) << "\n";
}