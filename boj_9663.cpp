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
	for (int i = 1; i < min(n - x, y + 1); ++i)
	{
		if (plate[y-i][x+i])
			return false;
	}

	for (int i = 1; i < min(x + 1, y + 1); ++i)
	{
		if (plate[y-i][x-i])
			return false;
	}
	return true;
}

void back_tracking(int a)
{
	if (a == n)
	{
		++cnt;
		return;
	}

	for (int j = 0; j < n; ++j)
	{
		if (!col[j])
		{
			if (check_diag(j, a))
			{
				col[j] = 1;

				plate[a][j] = 1;
				back_tracking(a + 1);

				col[j] = 0;
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
