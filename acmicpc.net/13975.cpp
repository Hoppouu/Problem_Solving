#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> r;
int T, sum;

//인덱스의 범위를 받는다.
int solve(int start, int end)
{
	int diff = end - start;
	if (diff == 0)
	{
		return v[start];
	}
	else if (diff == 1)
	{
		cout << v[start] + v[end] << "\n";
		sum += v[start] + v[end];
		return v[start] + v[end];
	}
	int mid = (start + end) / 2;
	sum += solve(start, mid) + solve(mid + 1, end);
	return sum;
}
void set()
{
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
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
		r.assign(v.size(), 0);
		set();
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		//solve(0, v.size() - 1);
		//cout << sum << "\n";
		cout << solve(0, v.size() - 1);
	}

}