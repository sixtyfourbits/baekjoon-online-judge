#include <iostream>

using namespace std;

int main ()
{
	int k, n;
	int ans = 0;
	cin >> k >> n;

	int line[1000001];
	for (int i = 0; i < k; ++i)
		cin >> line[i];

	long long l, r, m;
	l = 0; r = 2147483647; m = (l + r) / 2;

	while (l <= r)
	{
		int num = 0;
		for (int i = 0; i < k; ++i)
			num += line[i] / m;

		if (num >= n)
		{
			ans = m;
			l = m + 1;
			m = (l + r) / 2;
		}
		else
		{
			r = m - 1;
			m = (l + r) / 2;
		}
	}

	cout << ans;
}
