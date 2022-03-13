#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<vector<long long> > v1(n, vector<long long>(n));
	vector<vector<long long> > v2(n, vector<long long>(n, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v1[i][j];

	v2[0][0] = 1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == n - 1 && j == n - 1)
				continue;

			int num = v1[i][j];

			if (i + num < n)
			{
				v2[i + num][j] += v2[i][j];
			}
			if (j + num < n)
			{
				v2[i][j + num] += v2[i][j];
			}
		}
	}

	cout << v2[n - 1][n - 1];
}
