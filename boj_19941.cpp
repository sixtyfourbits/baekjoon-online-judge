#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int ans = 0;
	int k, n;
	cin >> k >> n;

	vector<char> table(n);
	vector<vector<int> > save;
	vector<bool> check(n, false);

	for (int i = 0; i < n; ++i)
		cin >> table[i];

	for (int i = 0; i < n; ++i)
	{
		if (table[i] == 'P')
			continue;

		for (int j = i; j <= i + k; ++j)
		{
			save.push_back(vector<int>(0));

			if (j - k >= 0 && table[j - k] == 'P')
			{
				save[save.size() - 1].push_back(i);
				save[save.size() - 1].push_back(j - k);
			}
			if (j < n && table[j] == 'P')
			{
				save[save.size() - 1].push_back(i);
				save[save.size() - 1].push_back(j);
			}
		}
	}

	sort(save.begin(), save.end(), [](const vector<int> & a, const vector<int> & b){ return a.size() < b.size(); });

	for (int i = 0; i < save.size(); ++i)
	{
		for (int j = 0; j < save[i].size(); ++j)
		{
			if (!check[j])
			{
				++ans;
				check[j] = true;
				break;
			}
		}
	}


	cout << ans;
}
