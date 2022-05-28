#include <iostream>

using namespace std;

long long trees[1000001];

int main ()
{
	long long n, m;
	long long ans;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> trees[i];

	long long r, l, mid;
	l = 0; r = 1000000000; mid = (r + l) / 2;

	while (l <= r)
	{
		long long sum = 0;
		for (int j = 0; j < n; ++j)
			if (trees[j] - mid > 0)
				sum += trees[j] - mid;

		if (sum >= m)
		{
			ans = mid;
			l = mid+1;
			mid = (r + l) / 2;
		}
		else
		{
			r = mid-1;
			mid = (r + l) / 2;
		}
	}

	cout << ans;
}
