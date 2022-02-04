#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int max = -100000;
	int ans = -100000;


	int n; int k;

	cin >> n >> k;


	vector<int> share_card(n);
	vector<int> team_card(n);

	for (int i = 0; i < n; ++i)
		cin >> share_card[i];
	for (int i = 0; i < n; ++i)
		cin >> team_card[i];

	//sort(team_card.begin(), team_card.end(), compare);
	/*
	for (int l = 0; l < n - k; ++l)
	{
		for (int i = 0; i < static_cast<int>(share_card.size()); ++i)
		{
			for (int j = 0; j < static_cast<int>(team_card.size()); ++j)
			{
				if (j >= l && j < l + k - 1)
					continue;

				if (share_card[i] * team_card[j] > max)
					max = share_card[i] * team_card[j];
			}

			cout << endl;
		}
	}
*/

	int out_l;
	for (int i = 0; i < k; ++i)
	{
		max = -100000;

		for (int j = 0; j < static_cast<int>(share_card.size()); ++j)
		{
			for (int l = 0; l < static_cast<int>(team_card.size()); ++l)
			{
				if (team_card[l] == 10002)
					continue;

				if (share_card[j] * team_card[l] > max)
				{
					max = share_card[j] * team_card[l];
					out_l = l;
				}
			}
		}
		//team_card.erase(team_card.begin() + out_l - 1);
		team_card[out_l] = 10002;
		//cout << out_l << endl;
	}

	for (int i = 0; i < static_cast<int>(share_card.size()); ++i)
	{
		for (int j = 0; j < static_cast<int>(team_card.size()); ++j)
		{
			if (team_card[j] == 10002)
				continue;

			if (share_card[i] * team_card[j] > ans)
			{
				ans = share_card[i] * team_card[j];
			}
		}
	}

	cout << ans;

	exit(0);
}
