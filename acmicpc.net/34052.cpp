//09:47
#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int n;
		cin >> n;
		sum += n;
	}

	cout << (sum <= 1500 ? "Yes" : "No");
}