#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	int res = 0;
	vector<string> v;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k + j < m; ++k)
			{
				if (k + i >= n)
					break;

				if (v[i][j] == v[i + k][j] && v[i][j] == v[i][j + k] && v[i][j] == v[i + k][j + k])
				{
					//cout << "i: " << i << " j: " << j << " k: " << k << endl;
					res = max(res, (k+1)*(k+1));
				}
			}

			//cout << endl;
		}
	}

	cout << res;
}
