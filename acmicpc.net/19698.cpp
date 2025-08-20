//09:43
#include <iostream>
using namespace std;

int main()
{
	int n, w, h, l;
	cin >> n >> w >> h >> l;

	int t = (w - w % l) * (h - h % l) / (l * l);
	if (t > n)
	{
		t = n;
	}

	cout << t << '\n';
}