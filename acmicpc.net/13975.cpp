#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> q;

int T;
long long solve()
{
	long long sum = 0;
	while (q.size() > 1)
	{
		long long x1 = q.top(); q.pop();
		long long x2 = q.top(); q.pop();

		sum += x1 + x2;
		q.push(x1 + x2);
	}
	q.pop();
	return sum;
}
int main(int start, int end)
{
	int sum = 0;
	cin >> T;
	while (T--)
	{
		int t;
		sum = 0;
		cin >> t;
		for (int i = 0; i < t; i++)
		{
			int x;
			cin >> x;
			q.push(x);
		}
		cout << solve() << "\n";
	}

}