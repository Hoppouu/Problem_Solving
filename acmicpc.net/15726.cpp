//20:20
#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int r = 1.0 * a * b / c;
	int rr = 1.0 * a / b * c;

	cout << max(r, rr) << "\n";
}