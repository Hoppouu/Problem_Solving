#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<vector<int>> dp;
int main()
{
    int n;
    cin >> n;

    v.assign(n, vector<int>(3));
    dp.assign(n, vector<int>(3));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
        }
    }

    int res = (1 << 31) - 1;
    for(int pivot = 0; pivot < 3; pivot++)
    {
        dp.assign(n, vector<int>(3, (1 << 31) - 1));
        for(int i = 0; i < 3; i++)
        {
            if(pivot == i)
            {
                dp[0][i] = v[0][i];
            }
            else
            {
                dp[0][i] = (1 << 30);
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int t1 = (j + 1) % 3, t2 = (j + 2) % 3;
                if(i == n - 1 && j == pivot)
                {
                    continue;
                }
                dp[i][j] = v[i][j] + min(dp[i - 1][t1], dp[i - 1][t2]);
            }
        }
        for(int i = 0; i < 3; i++)
        {
            res = min(res, dp[n - 1][i]);
        }
    }

    cout << res << "\n";
}