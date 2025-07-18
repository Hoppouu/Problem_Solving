//14:23
#include <iostream>
#include <vector>
using namespace std;

int calc(char a, char b)
{
	return (a - '0') * 10 + b - '0';
}
int main()
{
	string str;
	cin >> str;
	
	vector<int> dp(str.length(), 0);
	//1000000

	dp[0] = (str[0] != '0' ? 1 : 0);
	for (int i = 1; i < str.length(); i++)
	{
		int t = calc(str[i - 1], str[i]);
		if (str[i - 1] != '0')
		{
			if (2 <= t && t <= 26)
			{
				if (i < 2)
				{
					dp[i]++;
				}
				else
				{
					dp[i] += dp[i - 2];
				}
				dp[i] %= 1000000;
			}
		}
		else if (str[i - 1] == '0' && t == 0)
		{
			break;
		}
		if (str[i] != '0')
		{
			dp[i] += dp[i - 1];
			dp[i] %= 1000000;
		}
	}

	cout << dp[str.length() - 1] << "\n";
}