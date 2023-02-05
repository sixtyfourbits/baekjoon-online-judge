#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	int max = v[n-1];
	int cnt = 1;

	for (int i = n - 2; i >= 0; --i)
	{
		if (v[i] > max)
		{
			++cnt;
			max = v[i];
		}
	}

	cout << cnt;
}
