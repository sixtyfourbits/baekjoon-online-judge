#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int l;
	cin >> l;

	vector<int> v(l);
	for (int i = 0; i < l; ++i) {cin >> v[i];}
	sort(v.begin(), v.end());

	int n;
	cin >> n;

	int ans = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = n; j <= v[(int)v.size() - 1]; ++j)
		{
			bool tmp = true;
			for (int k = 0; k < l; ++k)
			{
				if (i <= v[k] && j >= v[k])
				{
					tmp = false;
					break;
				}
			}

			if (tmp)
				++ans;
		}
	}

	if (ans)
		cout << ans - 1;
	else
		cout << 0;
}
