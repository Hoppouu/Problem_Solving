//15:24
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end());

	cout << v[m - 1] << '\n';
}