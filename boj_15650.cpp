#include <iostream>
#include <vector>

using namespace std;

int n; int m;
vector<int> v(8);

void back_tracking(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
			cout << v[i] <<  " ";
		cout << '\n';

		return;
	}

	for (int i = 1; i <= n; i++)
	{
		bool check = false;
		for (int j = 0; j < cnt; ++j)
		{
			if (i <= v[j])
			{
				check = true;
				break;
			}
		}

		if (check)
			continue;

		v[cnt] = i;
		back_tracking(cnt + 1);
	}

}

int main()
{
	cin >> n >> m;

	back_tracking(0);
}
