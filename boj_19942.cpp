#include <iostream>
#include <vector>

using namespace std;

vector<int> mm(4);
vector<vector<int> > v;
vector<vector<vector<int> > > res;

int main ()
{
	int n;
	cin >> n;

	int ans = 9999;
	int pr, fa, ca, vi;

	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> mm[4];

	for (int i = 0; i < n; ++i)
	{
		int a, b, c, d, p;
		cin >> a >> b >> c >> d >> p;

		v[i].push_back(a);
		v[i].push_back(b);
		v[i].push_back(c);
		v[i].push_back(d);
		v[i].push_back(p);
	}

	for (int i = 0; i < n; ++i)
	{
		vector<vector<int> > tmpv(1, vector<int>(5));
		tmpv[0][0] = v[i][0];
		tmpv[0][1] = v[i][1];
		tmpv[0][2] = v[i][2];
		tmpv[0][3] = v[i][3];
		res.push_back(tmpv);

		for (int j = i + 1; j < n; ++j)
		{
			int sz = res[i].size();
			for (int l = 0; l < sz; ++l)
			{
				vector<int> tmp(5);

				tmp[0] = res[i][l][0] + v[j][0];
				tmp[1] += res[i][l][1] + v[j][1];
				tmp[2] += res[i][l][2] + v[j][2];
				tmp[3] += res[i][l][3] + v[j][3];
				tmp[4] += res[i][l][4] + v[j][4];

				res[i].push_back(tmp);
			}
		}
	}

	for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				if (res[i][j][0] >= mm[0] && res[i][j][1] >= mm[1] && res[i][j][2] >= mm[2] &&
				res[i][j][3] >= mm[3])
				{
					if (res[i][j][4] < ans)
					{
						ans = res[i][j][4];
						pr = res[i][j][0];
						fa = res[i][j][1];
						ca = res[i][j][2];
						vi = res[i][j][3];
					}
				}
			}
		}

		cout << ans << endl << pr << " " << fa << " " << ca << " " << vi;
}
