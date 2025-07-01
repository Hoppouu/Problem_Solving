//17:56
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr, brr, crr, cnt;
int n, m;

void solve()
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (cnt[arr[i]] == 0)
		{
			arr[i] = -1;
		}
	}

	int idx_a = 0, idx_b = 0, t;
	for (int i = 0; i < arr.size(); i++)
	{
		int max_a = -1;
		bool first = true;
		for (int j = idx_a; j < arr.size(); j++)
		{
			if (max_a < arr[j])
			{
				if (first)
				{
					t = idx_a;
					first = false;
				}
				if (cnt[arr[j]] > 0)
				{
					max_a = arr[j];
					idx_a = j;
				}
				else
				{
					arr[j] = -1;
				}
			}
		}
		if (max_a != -1)
		{
			arr[idx_a] = -1;
		}

		bool f = true;
		for (int j = idx_b; j < brr.size(); j++)
		{
			if (brr[j] == max_a)
			{
				crr.push_back(max_a);
				idx_b = j + 1;
				cnt[max_a]--;
				f = false;
				break;
			}
		}
		if (f && max_a != -1)
		{
			cnt[max_a] = 0;
			idx_a = t;
		}
	}
	cout << crr.size() << "\n";
	for (int i = 0; i < crr.size(); i++)
	{
		cout << crr[i] << " ";
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}

	cnt.assign(101, 0);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		brr.push_back(x);
		cnt[x]++;
	}
	solve();
}