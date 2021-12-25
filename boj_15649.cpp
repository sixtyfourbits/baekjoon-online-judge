#include <iostream>
#include <vector>

using namespace std;

int n; int m;
int c = 0;
vector<int> ans(8);

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < cnt; ++i)
			cout << ans[i] << " ";
		cout << '\n';
		c += 1;
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		bool tmp = 0;
		for (int j = 0; j < cnt; ++j)
		{
			if (i == ans[j])
				tmp = 1;
		}

		if (tmp)
			continue;

		ans[cnt] = i;
		dfs(cnt + 1);
	}
}

int main()
{
	cin >> n >> m;

	dfs(0);

	//cout << " asd - " << c;
}
