#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	long long sum = 0;
	vector<long long> v(10, 1);

	cin >> n;
	v[0] = 0;

	for (int i = 1; i < n; ++i)
	{
		vector<long long> v_tmp(10);

		v_tmp[0] = v[1];
		v_tmp[9] = v[8];

		for (int j = 1; j <= 8; ++j)
			v_tmp[j] = (v[j - 1] + v[j + 1]) % 1000000000;

		v = v_tmp;
	}

	for (auto& i : v)
		sum += i % 1000000000;

	cout << sum % 1000000000;
}
