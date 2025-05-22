#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v;
priority_queue<int, vector<int>, greater<int>> q;

int T, sum;
void set()
{
	sort(v.begin(), v.end());
	vector<int> t;
	int start = 0;
	int end = v.size() - 1 - (v.size() % 2);
	while (start < end)
	{
		t.push_back(v[start++]);
		t.push_back(v[end--]);
	}
	if (v.size() % 2 == 1)
	{
		t.push_back(v[v.size() - 1]);
	}
	for (int i = 0; i < t.size(); i++)
	{
		v[i] = t[i];
	}
	q.push(v[0] + v[1]);
	for (int i = 2; i < v.size(); i++)
	{
		q.push(v[i]);
	}
}

int solve()
{
	while (q.size() > 1)
	{
		int x1 = q.top(); q.pop();
		int x2 = q.top(); q.pop();

		q.push(x1 + x2);
	}

	return q.top();
}
int main(int start, int end)
{
	int sum = 0;
	cin >> T;
	while (T--)
	{
		v.clear();
		int t;
		sum = 0;
		cin >> t;
		for (int i = 0; i < t; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		set();
		cout << solve() << "\n";
	}

}