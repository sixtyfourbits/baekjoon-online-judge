#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int ans;
	int cnt;

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	ans = v[n-1];
	cnt = 1;


	for (int i = n - 1; i >= 0;)
	{
		cout << i << '\n' << ans << '\n';

		if (cnt <= 1)
		{
			if (v[i-1] > v[i-2])
			{
				ans += v[i - 1];
				--i;
				++cnt;
			}
			else
			{
				ans += v[i - 2];
				i -= 2;
				cnt = 1;
			}
		}
		else
		{
			ans += v[i - 2];
			cnt = 1;
			i -= 2;
		}
	}

	cout << ans;
}
