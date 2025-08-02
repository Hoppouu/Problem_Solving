//2025-08-02
#include <iostream>
using namespace std;
int arr[100001];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int minx = 1;
	int maxx = 1;
	int t_a = 1;
	int t_b = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] <= arr[i])
		{
			t_a++;
		}
		else
		{
			t_a = 1;
		}

		if (arr[i - 1] >= arr[i])
		{
			t_b++;
		}
		else
		{
			t_b = 1;
		}
		minx = max(t_a, minx);
		maxx = max(t_b, maxx);

	}

	cout << max(minx, maxx);
}