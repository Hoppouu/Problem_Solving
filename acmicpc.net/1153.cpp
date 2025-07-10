//17:53
#include <iostream>
#include <vector>
#define N 1000001

using namespace std;

int n;
bool isPrime[N];
vector<int> v;

void solve()
{
	bool even;
	if (n % 2 == 0)
	{
		even = true;
		n -= 4;
	}
	else
	{
		even = false;
		n -= 5;
	}

	if (n < 4)
	{
		cout << "-1";
		return;
	}


	for (int i = 0; i < v.size(); i++)
	{
		if (isPrime[n - v[i]])
		{
			if (even)
			{
				cout << "2 2 ";
			}
			else
			{
				cout << "2 3 ";
			}
			cout << v[i] << " " << n - v[i] << "\n";
			return;
		}
	}

	cout << "-1\n";
}
int main()
{
	fill_n(isPrime + 2, N, true);
	for (int i = 2; i * i < N; i++)
	{
		if (!isPrime[i])
		{
			continue;
		}
		for (int j = i * i; j < N; j += i)
		{
			isPrime[j] = false;
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (isPrime[i])
		{
			v.push_back(i);
		}
	}

	cin >> n;
	
	solve();
}