#include <iostream>
#include <vector>
using namespace std;

int n, m;

void solve()
{
	int x = n;
	int c = 0;
	while (x != 0)
	{
		c += x / m;
		x /= m;
	}
	cout << c << "\n";
}

int main()
{
	cin >> n >> m;
	
	solve();
}