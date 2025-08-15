//07:52
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> v, dp;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int dfs(int r, int c)
{
    if(dp[r][c])
    {
        return dp[r][c];
    }
    dp[r][c] = 1;

    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(0 <= nr && nr < n && 0 <= nc && nc < n)
        {
            if(v[r][c] < v[nr][nc])
            {
                dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1);
            }
        }
    }

    return dp[r][c];
}

int solve()
{
    int mx = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mx = max(mx, dfs(i, j));
        }
    }

    return mx;
}
int main()
{
    cin >> n;
    v.assign(n, vector<int>(n, 0));
    dp.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << solve() << '\n';
}