#include <iostream>
#include <vector>

using namespace std;
int main ()
{
	int n;
	long long rtl_sum = 0;
	long long ltr_sum = 0;
	vector<bool> v;

	cin >> n;
	vector<int> rtl(n);
	vector<int> ltr(n);
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		if (tmp % 2 == 0)
			v.push_back(0);
		else
			v.push_back(1);
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i])
			++cnt;

		ltr[i] = cnt;
	}

	cnt = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (v[i])
			++cnt;

		rtl[i] = cnt;
	}

	for (int i = 0; i < n; ++i)
	{
		if (!v[i])
			ltr_sum += ltr[i];
	}

	for (int i = n - 1; i >= 0; --i)
	{
		if (!v[i])
			rtl_sum += rtl[i];
	}

	//cout << ltr_sum << " " << rtl_sum << endl;
	cout << min(ltr_sum, rtl_sum);
}
