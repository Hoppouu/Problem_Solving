#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v, ans;
void print()
{
	for(int i = 0; i < m; i++)
	{
		cout<< ans[i] << " ";
	}
	cout << "\n";
}
void solve(int k, int x)
{
	if(k == m)
	{
		print();
		return;
	}
	
	int t = 0;
	for(int i = x; i < v.size(); i++)
	{
		if(v[i] > t)
		{
			t = v[i];
			ans[k] = v[i];
			solve(k + 1, i);
		}
	}
}
int main()
{
	cin >> n >> m;
	ans.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	solve(0, 0);
}