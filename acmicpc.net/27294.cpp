#include <iostream>
using namespace std;

int main()
{
	int t, n, r;

	cin >> t >> n;
	if (n == 1 || !(t >= 12 && t <= 16))
	{
		r = 280;
	}
	else if ((t >= 12 && t <= 16) && n == 0)
	{
		r = 320;
	}
		cout << r << "\n";

}