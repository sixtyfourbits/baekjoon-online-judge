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

	bool b = true;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '0')
		{
			if (b)
			{
				++cnt0;
				b = false;
			}

		}
		else
		{
			b = true;
		}
	}


	//cout << endl;
	 b = true;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '1')
		{
			if (b)
			{
				++cnt1;
				b = false;
			}
		}
		else
			b = true;
	}

	//cout << endl;

	cout << min(cnt0, cnt1);
}
