#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, l, r, x;

int main()
{
	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int i = 0, j = 0;
	int sum = v[i], answer = 0;

	while (i < n - 1 && j < n - 1)
	{
		cout << sum << "\n";
		if (!(l <= sum && sum <= r))
		{
			j++;
			sum += v[j];
			continue;
		}

		if (!((v[j] - v[i]) >= x))
		{
			sum -= v[i];
			i++;
			continue;
		}

		sum += pow(2, j - i + x) - 1;
	}

	cout << sum << "\n";
}