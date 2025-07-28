//11:43
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;

int min_element(int t)
{
	int e = 1 << 30;
	for (int i = t; i < n; i++)
	{
		if (v[i] == 0)
		{
			break;
		}
		if (e > v[i])
		{
			e = v[i];
		}
	}

	return e;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	int c = 0;

	while (true)
	{
		bool f = true;
		int t;
		for (t = 0; v[t] == 0; t++);
		int e = min_element(t);
		for (int i = t; i < n; i++)
		{
			if (v[i] == 0)
			{
				f = true;
				break;
			}

			if (f)
			{
				c++;
				f = false;
			}
			if (v[i] > 0)
			{
				v[i] -= e;
			}
		}

		f = true;
		for (int i = 0; i < n; i++)
		{
			if (v[i] != 0)
			{
				f = false;
				break;
			}
		}
		if (f)
		{
			cout << c << "\n";
			break;
		}
	}
}