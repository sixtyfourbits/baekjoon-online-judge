#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int n;
	int ans = 0;
	cin >> n;

	vector<vector<int> > v(n, vector<int>(n+2));
	vector<vector<int> > sum(n, vector<int>(n+2));
	for (int i = 0; i < n; ++i)
		for (int j = 1; j <= i + 1; ++j)
			cin >> v[i][j];

	sum[0][1] = v[0][1];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= i + 1; ++j)
		{
			sum[i][j] = max(sum[i - 1][j] + v[i][j], sum[i - 1][j - 1] + v[i][j]);
		}
	}

	for (auto& i : sum[n - 1])
		ans = max(ans, i);

	cout << ans;
}
