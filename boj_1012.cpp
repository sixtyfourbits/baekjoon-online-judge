#include <iostream>
#include <vector>

using namespace std;

int n; int m;
int ans = 0;
vector<vector<int> > g;

void dfs(int start_x, int start_y)
{
	if (start_x == m - 1)
		return;
	if (start_y == n - 1)
		return;


	for (int i = start_y; i < n; ++i)
	{
		for (int j = start_x; j < m; ++j)
		{
			if (g[i][j] == 1)
			{
				g[i][j] = 2;

				if (i < n - 1)
					dfs(start_x, start_y + 1);

				if (i > 0)
					dfs(start_x, start_y - 1);

				if (j < m - 1)
					dfs(start_x + 1, start_y);

				if (j > 0)
					dfs(start_x - 1, start_y);
			}
			else
			{
				return;
			}
		}
	}
}


int main()
{
	int t;
	cin >> t;
	cin >> m >> n;

	for (int c = 0; c < t; ++c)
	{
		int k;
		cin >> k;

		g = vector<vector<int> >(n, vector<int>(m, 0));
		for (int i = 0; i < k; ++i)
		{
			int tmp1; int tmp2;
			cin >> tmp1 >> tmp2;
			g[tmp1][tmp2] = 1;
		}

		dfs(0, 0);

		cout << ans << '\n';
		ans = 0;
	}
}
