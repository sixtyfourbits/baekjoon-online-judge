#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> v;

	cin >> n;

	int r_cnt = 0; int b_cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		char c;
		cin >> c;

		if (c == 'R')
		{
			++r_cnt;
			if (b_cnt > 0)
				v.push_back(b_cnt);
			b_cnt = 0;
		}
		else
		{
			++b_cnt;
			if (r_cnt > 0)
				v.push_back(r_cnt);
			r_cnt = 0;
		}

		if (i == n - 1)
		{
			if (c == 'R')
				v.push_back(r_cnt);
			if (c == 'B')
				v.push_back(b_cnt);

			break;
		}
	}

	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	for (int i = 0; i < v.size() - 1; ++i)
	{
		if (i % 2 == 0)
			c1 += v[i];
		else
			c2 += v[i];
	}
	for (int i = v.size() - 1; i >= 1; --i)
	{
		if (i % 2 == 0)
			c3 += v[i];
		else
			c4 += v[i];
	}

	int res = c1;
	res = min(res, c2);
	res = min(res, c3);
	res = min(res, c4);

	cout << res;
	/*
	int case1; int case2; int case3;
	if (v.size() % 2 == 0)
	{
		case1 = a - v[0];
		case2 = b - v[v.size() - 1];
	}
	else
	{
		case1 = a - v[0];
		case2 = a - v[v.size() - 1];
	}
	case3 = b;

	int res;
	res = min(case1, case2);
	res = min (res, case3);

	cout << res;
	*/
}
