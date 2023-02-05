#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];
	arr[n - 1] = 1;


	for (int i = n - 2; i >= 0; --i)
	{
		int max = 0;
		for (int j = i + 1; j < n; ++j)
		{
			if (v[i] < v[j] && max < arr[j])
				max = arr[j];
		}

		arr[i] = max + 1;
	}

	int ans = 1;
	for(auto& i : arr)
	{
		if (i > ans)
			ans = i;
	}

	cout << ans;
}
