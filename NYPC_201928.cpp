#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	int cnt = 26;
	long long ans = 1;

	char before[101];
	char after[101];
	
	vector<bool> check(26, false);

	scanf("%[^\n]s", before);
	getchar();
	scanf("%[^\n]s", after);

	for (int i = 0; i < strlen(before); ++i)
	{
		if (before[i] < 97 && before[i] > 64)
		{
			before[i] += 32;
		}

		if (after[i] < 97 && after[i] > 64)
		{
			after[i] += 32;
		}
	}

	for (int i = 0; i < 16; ++i)
	{
		cout << before[i];
	}
	cout << endl;

	for (int i = 0; i < 16; ++i)
	{
		cout << after[i];
	}
	cout << endl;

	for (int i = 0; i < strlen(before); ++i)
	{
		if (before[i] < 97)
			continue;

		if (!check[after[i] - 97])
		{
			--cnt;
			cout << i << endl;
			check[after[i] - 97] = true;
		}
	}

	cout << endl;
	for (int i = cnt; i >= 1; --i)
	{
		cout << ans << endl;
		ans = ans * i % 1000000007;
	}

	cout << ans;
}
