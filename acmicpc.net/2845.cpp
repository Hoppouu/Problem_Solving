// 18:10
#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] - n * m << " ";
	}
}