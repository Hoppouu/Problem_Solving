//12:30
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int t = a * b - c;
	cout << (t >= 0? t : 0) << "\n";
}