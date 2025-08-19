//15:14
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n, T;
	cin >> n >> T;
	vector<int> v;
	queue<int> q;
	for (int i = 0; i < 2 * n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}
	
	while (T--)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i] - 1; j++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ' ';
	}
}
