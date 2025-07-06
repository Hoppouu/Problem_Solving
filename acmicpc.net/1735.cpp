//16:12
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int t = a;
		a = b;
		b = t % b;
	}

	return a;
}
int main()
{
	int n1, m1, n2, m2;
	cin >> n1 >> m1;
	cin >> n2 >> m2;
	int nn = n1 * m2 + n2 * m1;
	int mm = m1 * m2;
	int g = gcd(nn, mm);
	cout << nn / g << " " << mm / g << "\n";
}