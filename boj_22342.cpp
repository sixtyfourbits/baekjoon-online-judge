#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int weight[2001][2001];
int save[2001][2001];

int func (int i, int j)
{
	int sum = 0;

	for(int a = 0; a < n; ++a)
	{
		for (int b = 0; b < m; ++b)
		{
			if (b < j && abs(i - a) <= j - b)
				sum = max(sum, save[a][b] + weight[a][b]);
		}
	}


	save[i][j] = max(save[i][j], sum);
	return save[i][j];
}

int main ()
{
	cin >> m >> n;

	int mx = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%1d", &weight[i][j]);

	for (int j = 0; j < m; ++j)
		for (int i = 0 ; i < n; ++i)
			mx = max(mx, func(i, j));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << save[i][j] << " ";
		}
		cout << endl;
	}
	//cout << mx;
}
