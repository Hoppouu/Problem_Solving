// 08:49
#include <iostream>
#define N 10
using namespace std;

int main()
{
	int sum;
	cin >> sum;
	for (int i = 0; i < N - 1; i++)
	{
		int x;
		cin >> x;
		sum -= x;
	}

	cout << sum << "\n";
}