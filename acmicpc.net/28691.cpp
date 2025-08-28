//20:21
#include <iostream>
using namespace std;
int main()
{
	string str;
	cin >> str;
	string r;
	if (str == "M")
	{
		r = "MatKor";
	}
	else if(str == "W")
	{
		r = "WiCys";
	}
	else if (str == "C")
	{
		r = "CyKor";
	}
	else if (str == "A")
	{
		r = "AlKor";
	}
	else if (str == "$")
	{
		r = "$clear";
	}

	cout << r << '\n';
}