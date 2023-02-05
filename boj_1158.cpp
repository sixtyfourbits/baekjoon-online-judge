#include <iostream>
#include <vector>

using namespace std;
/*
int main ()
{
	int n, k;
	cin >> n >> k;
	vector<int> v;
	vector<int> ans;

	for (int i = 1; i <= n; ++i)
		v.push_back(i);

	int i = 0;
	int cnt = 1;
	while (true)
	{
		int a = 0;
		for (int l = 0; l < n; ++l)
		{
			if (v[l] == 0)
				++a;
		}

		if (a == n)
			break;

		if (i >= n - 1)
			i = 0;
		else
			++i;

		if (v[i] != 0)
			++cnt;
		if (v[i] != 0 && cnt == k)
		{
			ans.push_back(v[i]);
			cnt = 0;
			v[i] = 0;
		}
	}

	cout << "<";
	for (int i = 0; i < n; ++i)
	{
		if (i == n - 1)
			cout << ans[i] << ">";

		else
			cout << ans[i] << ", ";
	}
}
*/

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v;
	vector<int> ans;

	if (k == 1)
	{
		cout << "<";
		for (int i = 1; i <= n; ++i)
		{
			if (i == n)
				cout << i << ">";
			else
			cout << i << ", ";
		}

		return 0;
	}
	for (int i = 0; i < n; ++i)
		v.push_back(i + 1);

	int i = -1;
	int cnt = 0;
	while (v.size() > 0)
	{
		++i;
		if (i >= v.size())
			i = 0;

		++cnt;

		if (cnt == k)
		{
			ans.push_back(v[i]);
			v.erase(v.begin() + i, v.begin() + i + 1);
			cnt = 1;

			if (i >= v.size())
				cnt = 0;
		}
	}

	cout << "<";
	for (int i = 0; i < n; ++i)
	{
		if (i == n - 1)
			cout << ans[i] << ">";

		else
			cout << ans[i] << ", ";
	}

}
