#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > v;
vector<int> save;
vector<vector<int> > arr;

void back_tracking(int cnt)
{
	if (cnt == n/2)
	{
		for (int i = 0; i < cnt; ++i)
		{
			arr.push_back(save);
			//cout << save[i];
		}
		//cout << '\n';
		return;
	}

	int a;
	if (cnt == 0)
		a = 0;
	else
		a = cnt - 1;

	for (int i = save[a]; i < n; ++i)
	{
		bool tmp = false;

		for (int j = 0; j < cnt; ++j)
		{
			if (i == save[j])
				tmp = true;
		}

		if (tmp)
			continue;

		save[cnt] = i;
		back_tracking(cnt + 1);
	}
}

int main()
{
	int min = 99999999;

	cin >> n;

	v = vector<vector<int> >(n, vector<int>(n));
	save = vector<int>(n/2);
	arr = vector<vector<int> >(0);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];

	back_tracking(0);

	int size = static_cast<int>(arr.size());

	for (int i = 0; i < size / 2; ++i)
	{
		int a = 0;
		int b = 0;

		for (int j = 0; j < n / 2; ++j)
		{
			for (int k = 0; k < n / 2; ++k)
			{
				if (j == k)
					continue;

				a += v[arr[i][j]][arr[i][k]];
				b += v[arr[size - i - 1][j]][arr[size - i - 1][k]];
			}
		}

		if (abs(a - b) < min)
			min = abs(a - b);
	}

	cout << min;
}
