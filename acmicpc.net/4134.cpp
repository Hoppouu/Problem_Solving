//12:46
#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned int uint;
uint solve(uint x)
{
	if (x <= 1)
	{
		x = 2;
	}
	for (uint k = x;; k++)
	{
		bool f = true;
		uint l = sqrt(k);
		for (uint i = 2; i <= l; i++)
		{
			if (k % i == 0)
			{
				f = false;
				break;
			}
		}
		if (f)
		{
			return k;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		uint x;
		cin >> x;
		cout << solve(x) << "\n";
	}
}