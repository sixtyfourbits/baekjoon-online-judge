#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n;
	int a_sum = 0;
	int sum = 0;
	cin >> n;

	vector<int> v(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		a_sum += v[i];
	}
	a_sum -= v[0];


	for (int i = 1; i < n - 1; ++i)
	{
		int b_sum = 0;
		for(int j = i + 1; j < n; ++j)
		{
			b_sum += v[j];
		}

		sum = max(sum, a_sum + b_sum - v[i]);
	}

	cout << sum;
}
