// 20220206

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> res;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];


	for (int i = n - 1; i >= 0; --i)
	{
		res.push_back(arr[i]);

		for (int j = res.size() - 1; j >= 1; --j)
		{
			if (res[j] >= res[j - 1])
				break;

			// 위치 바꿈
			int tmp = res[j];
			res[j] = res[j - 1];
			res [j - 1] = tmp;
		}
	}


	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << '\n';
	}
}
