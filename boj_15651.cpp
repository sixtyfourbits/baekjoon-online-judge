#include <iostream>
#include <vector>

using namespace std;

int n; int m;
vector<int> ans(8);

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < cnt; ++i)
			cout << ans[i] << " ";
		cout << '\n';

		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		ans[cnt] = i;
		dfs(cnt + 1);
	}
}

int main()
{
	cin >> n >> m;

	dfs(0);
}
