#include <iostream>
#include <string>

using namespace std;
/*
string s;
int ans = 3;

void pal(int r, int l, int acc)
{
	if (r >= l)
	{
		ans = min(ans, acc);
		return;
	}

	if (s[r] != s[l])
	{
		if (acc == 1)
		{
			ans = min(ans, 2);
			return;
		}

		if (s[r] == s[l - 1] && s[r + 1] == s[l])
		{
			pal(r+1, l, acc + 1);
			pal(r, l - 1, acc + 1);
			return;
		}

		if (s[r] == s[l - 1])
		{
			pal(r, l - 1, acc + 1);
			return;
		}
		else if (s[r + 1] == s[l])
		{
			pal(r + 1, l, acc + 1);
			return;
		}
		else
		{
			ans = min(ans, 2);
			return;
		}
	}

	pal(r+1, l-1, acc);
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> s;
		pal(0, s.size() - 1, 0);
		cout << ans;
		ans = 3;
	}
}
*/

string s;

int fl(int r, int l)
{
	for (int i = r; i < s.size() / 2; ++i)
	{
		if (s[r] != s[l])
			return 0;
	}

	return 1;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> s;

		int r, l;
		for (int j = 0; j < s.size() / 2; ++j)
		{
			r = j;
			l = s.size() - j - 1;

			if (s[r] != s[l])
			{
				if (fl(r + 1, l))
				{
					cout << 1;
					break;
				}

				if (fl(r, l -1))
				{
					cout << 1;
					break;
				}
				else
				{
					cout << 2;
					break;
				}

				if(!fl(r + 1, l))
				{
					cout << 2;
					break;
				}
			}

			if (j == s.size() / 2 - 1)
			{
				cout << 0;
				break;
			}
		}
	}
}
