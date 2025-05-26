#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> isPrime;
deque<int> v;
int n;

void set()
{
	isPrime[0] = 0;
	isPrime[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i + i; j <= n; j += i)
		{
			isPrime[j] = 0;
		}
	}
}

int solve()
{
	set();
	int sum = 0, cnt = 0;
	for (int i = 0; i <= n; i++)
	{
		if (isPrime[i])
		{
			sum += i;
			v.push_back(i);
			while (sum > n)
			{
				sum -= v.front();
				v.pop_front();
			}
			if (sum == n)
			{
				cnt++;
			}
			if (v.empty())
			{

			}
		}
	}
	
	return cnt;
}
int main()
{
	cin >> n;
	isPrime.assign(n + 1, 1);
	cout << solve() << "\n";
}