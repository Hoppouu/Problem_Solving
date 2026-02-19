#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
void sol(int r, int c)
{
	grid[r][c] = '*';
	grid[r + 1][c - 1] = grid[r + 1][c + 1] = '*';
	for(int i = 0; i < 5; i++) grid[r + 2][c + i - 2] = '*';
}

void solve(int r, int c, int n)
{
	if(n == 3)
	{
		sol(r, c);
		return;
	}
	
	solve(r, c, n / 2);
	solve(r + n / 2, c - n / 2, n / 2);
	solve(r + n / 2, c + n / 2, n / 2);
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	grid.assign(n, vector<char>(n * 2));
	solve(0, n - 1, n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n * 2; j++)
		{
			if(grid[i][j] != 0)
			{
				cout << grid[i][j];
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
}