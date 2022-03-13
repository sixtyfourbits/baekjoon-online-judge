#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 1; i <= n; ++i)
	{
		int a = i;
		int sum = 0;

		while(a > 0)
		{
			sum += a % 10;
			a /= 10;
		}

		if (i % sum == 0)
			++cnt;
	}

	cout << cnt;
}
