#include <iostream>

using namespace std;

int main ()
{
	int n, k;
	int ans = 0;
	cin >> n >> k;

	char table[20001];
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	for (int i = 0; i < n; ++i)
	{
		if (table[i] != 'P')
			continue;

		for (int j = i - k; j <= i + k; ++j)
		{
			if (j >= 0 && j < n)
			{
				if (table[j] == 'H')
				{
					//cout << j << " " << i << endl;
					++ans;
					table[j] = 'N';
					break;
				}
			}
		}
	}

	cout << ans;
}
