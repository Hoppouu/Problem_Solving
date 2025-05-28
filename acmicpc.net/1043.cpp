#include <iostream>
#include <vector>
using namespace std;
vector<int> known;
vector<vector<int>> party, graph;
int n, m;
int main()
{
	cin >> n >> m;
	party.assign(m, vector<int>());
	graph.assign(n + 1, vector<int>(n + 1, 0));
	int t, x;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> x;
		known.push_back(x);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		for (int j = 0; j < t; j++)
		{
			cin >> x;
			party[i].push_back(x);
		}
	}


}