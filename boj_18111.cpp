#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int n, m, b;
	int ans = 999999999;
	int height = 0;
	cin >> n >> m >> b;

	vector<int> v(257);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int tmp; cin >> tmp;
			++v[tmp];
		}
	}

	for (int i = 0; i <= 256; ++i)
	{
		int btmp = b;
		int sec = 0;
		bool a = false;
		for (int j = 256; j >= 0; --j)
		{
			if (!v[j])
				continue;

			if (j > i)
			{
				a = true;
				sec += (j - i) * v[j] * 2;
				btmp += (j - i) * v[j];
			}
			else
			{
				if (btmp >= (i - j) * v[j])
				{
					a = true;
					sec += (i - j) * v[j];
					btmp -= (i - j) * v[j];
				}
				else
				{
					a = false;
					break;
				}
			}
		}
		//cout << sec << " " << i << endl;
		
		if (!a)
			continue;

		if (sec <= ans)
		{
			ans = sec;
			if (height < i)
				height = i;
		}
	}	

	cout << ans << " " << height;
}