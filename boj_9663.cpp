#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cnt = 0;
vector<vector<bool> > plate;
vector<bool> col;
vector<bool> row;

bool check_diag(int x, int y)
{
	for (int i = 0; i < min(n - x, y); ++i)
	{
		if (plate[y-i][x+i])
			return true;
	}

	for (int i = 0; i < min(x, y); ++i)
	{
		if (plate[y-i][x-i])
			return true;
	}
	return false;
}

void back_tracking(int a)
{
	if (a == n)
	{
		++cnt;
		return;
	}

	if (col[a] == 0)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!check_diag(a, j))
			{
				col[a], row[j] = 1;

				plate[a][j] = 1;
				back_tracking(a + 1);

				col[a], row[j] = 0;
				plate[a][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> n;

	plate = vector<vector<bool> >(n, vector<bool>(n));
	col = vector<bool>(n);
	row = vector<bool>(n);

	back_tracking(0);

	cout << cnt;
}
