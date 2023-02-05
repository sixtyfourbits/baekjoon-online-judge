#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
string zero(int a)
{
	string s;

	for (int i = 0; i < a; ++i)
		s.push_back('0');

	return s;
}

int main ()
{
	int n;
	cin >> n;

	vector<string> pre;
	pre.push_back("1");

	for (int i = 2; i <= n; ++i)
	{
		vector<string> v;

		for (int j = 0; j < pre.size(); ++j)
		{
			if (j == 0)
				v.push_back(pre[j] + "1");

			if (v[v.size() - 1] != pre[j] + "1")
				v.push_back(pre[j] + "1");
			if (v[v.size() - 1] != "1" + pre[j])
				v.push_back("1" + pre[j]);
		}

		if (i % 2 == 0)
			v.push_back(zero(i));

		pre = v;
	}

	cout << pre.size();
}
*/

int main ()
{
	int n;
	cin >> n;

	long long a1 = 1;
	long long a2 = 2;
	long long sum;

	for(int i = 2; i < n; ++i)
	{
		sum = a1 + a2;

		a1 = a2;
		a2 = sum;
	}

	cout << sum % 15746;
}
