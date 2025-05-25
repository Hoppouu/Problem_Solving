#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[2][100001];
int dp[2][100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        fill(&dp[0][0], &dp[0][0] + 100001 * 2, 0);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> arr[i][j];
            }
        }
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int x1 = dp[j][i - 2] + arr[(j + 1) % 2][i - 1];
                int x2 = dp[(j + 1) % 2][i - 1];
                int x3 = dp[(j + 1) % 2][i - 2];
                dp[j][i] = max(max(x1, x2), x3) + arr[j][i];
            }
        }
        cout << max(dp[0][n], dp[1][n]) << "\n";
    }
}