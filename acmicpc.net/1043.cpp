#include <iostream>
#include <vector>
using namespace std;
vector<int> state;
vector<vector<int>> party;
int n, m;
int main()
{
	cin >> n >> m;
	party.assign(m, vector<int>(51, 0));
	state.assign(51, 0);
	int t, x;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> x;
		state[x] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		for (int j = 0; j < t; j++)
		{
			cin >> x;
			party[i][x] = 1;
		}
	}

	for(int k = 0; k < m; k++)
	{
		for (int i = 0; i < m; i++)
		{
			bool f = false;
			for (int j = 1; j <= n; j++)
			{
				if(party[i][j] && state[j])
				{
					f = true;
					break;
				}
			}
			if(f)
			{
				for(int j = 1; j <= n; j++)
				{
					if(party[i][j])
					{
						state[j] = 1;
					}
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		bool f = true;
		for (int j = 1; j <= n; j++)
		{
			if(party[i][j] && state[j])
			{
				f = false;
				break;
			}
		}
		if(f)
		{
			cnt++;
		}
	}

	cout << cnt << "\n";
}