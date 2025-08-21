//19:03
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	int aa = a * d + b * e;
	int bb = c * max(d, e) * 2;
	if (d > e)
	{
		bb = min(bb, a * (d - e) + c * e * 2);
	}
	else
	{
		bb = min(bb, c * d * 2 + b * (e - d));
	}

	cout << min(aa, bb) << '\n';
}