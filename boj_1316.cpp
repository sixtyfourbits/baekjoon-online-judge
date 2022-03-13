#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	int ans;

	cin >> n;
	ans = 0;

	for (int i = 0; i < n; ++i)
	{
		++ans;

		bool check = false;
		string s;
		string ban;

		cin >> s;
		ban.push_back(s[0]);

		for (int i = 1; i < s.size(); ++i)
		{
			if (check)
				break;

			if (s[i] == s[i - 1])
				continue;

			else
			{
				for(auto& j : ban)
				{
					if (j == s[i])
					{
						--ans;
						check = true;
						break;
					}
				}

				ban.push_back(s[i]);
			}
		}
	}

	cout << ans;
}
