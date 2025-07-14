//15:43
#include <iostream>
using namespace std;

int dp[101][101][2][2];
int w, h;
int main()
{
	cin >> w >> h;

	for (int i = 1; i <= w; i++)
	{
		dp[1][i][0][1] = 1;
	}

	for (int i = 1; i <= h; i++)
	{
		dp[i][1][1][1] = 1;
	}

	//{x, y, 방향(0:왼쪽에서 옴, 1: 위에서 옴), 꺽기가능(0: X, 1: O)}
	for (int i = 2; i <= h; i++)
	{
		for (int j = 2; j <= w; j++)
		{
			dp[i][j][0][0] = dp[i][j - 1][1][1];
			dp[i][j][0][1] = dp[i][j - 1][0][0] + dp[i][j - 1][0][1];
			dp[i][j][1][0] = dp[i - 1][j][0][1];
			dp[i][j][1][1] = dp[i - 1][j][1][0] + dp[i - 1][j][1][1];
			for (int k = 0; k < 2; k++)
			{
				for (int l = 0; l < 2; l++)
				{
					dp[i][j][k][l] %= 100000;
				}
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sum += dp[h][w][i][j];
			sum %= 100000;
		}
	}

	cout << sum << "\n";
}