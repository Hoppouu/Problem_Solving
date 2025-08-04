//23:44
#include <iostream>
#include <vector>
using namespace std;
int n;

int main()
{
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		x = (x % 7 == 0 ? 7 : x);
		v.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += v[(i + j) % n];
			if (sum % 7 == 4)
			{
				cout << "YES\n";
				return 0;
			}
		}
	}

	cout << "NO\n";
	
}