#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	string s;
	cin >> s;

	int cnt0 = 0;
	int cnt1 = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '0')
		{
			for (int j = i; j < s.size(); ++j)
			{
				if (s[j] == '1')
				{
					break;
					i = j;
				}

				++cnt0;
			}
		}
	}

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '1')
		{
			for (int j = 0; j < s.size(); ++j)
			{
				if (s[j] == '0')
				{
					break;
					i = j;
				}

				++cnt1;
			}
		}
	}

	cout << min(cnt0, cnt1);
}
