#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n;
	vector<int> v;

	cin >> n;

	int tmp = n;
	while (tmp != 0)
	{
		v.push_back(tmp % 10);
		tmp /= 10;
	}

	//cout << "A";

	for (int i = 0; i < v.size() - 1; ++i)
	{
		int a = 1, b = 1;

		for (int j = 0; j <= i; ++j)
		{
			a *= v[j];
		}
		for (int j = i + 1; j < v.size(); ++j)
		{
			b *= v[j];
		}

		if (a == b)
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
}
