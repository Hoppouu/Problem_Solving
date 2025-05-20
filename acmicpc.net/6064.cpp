#include <iostream>


int n, m, x, y;

int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int solve()
{
	if (gcd(n, m) != 1)
	{
		return -1;
	}

}
int main()
{

}