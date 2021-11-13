#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int	n;
	cin >> n;

	int a; int b;
	int sum = 0;
	vector<int> v(10, 1); // vector

	v[0] = 0; //
	a = 8;
	b = 1;

	for (int i = 2; i <= n; ++i)
	{
		a = 0; b = 0;

		 for (int j = 1; j <= 8; ++j)
		 	b += v[j];

		for (int j = 1; j <= 9; ++j)
		{
			v[j] = v[j + 1] + v[j - 1];
			a += v[j];
		}

		sum = (a * 2 + b) % 1000000000;
	}

	cout << sum;


}
