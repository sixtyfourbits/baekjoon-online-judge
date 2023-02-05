#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n; int m;
	cin >> n >> m;

	int arr[51][2]; // arr[][0] -> 6개 패키지 가격
					// arr[][1] -> 낱개 가격
	for (int i = 0; i < m; ++i) cin >> arr[i][0] >> arr[i][1];

	int min1 = 1001; // 낱개 최저가
	int min2 = 1001; //패키지 최저가

	for (int i = 0; i < m; ++i)
	{
		if (min1 > arr[i][1])
			min1 = arr[i][1];

		if (min2 > arr[i][0])
			min2 = arr[i][0];
	}

	//cout << min1 << " " << min2 << endl;
	int ans = min2 * ceil(n / 6.0);
	//cout << ans << endl;

	if (ans > min1 * n)
		ans = min1 * n;
	//cout << ans << endl;

	if (ans > min2 * (n/6) + min1 * n - (n/6))
		ans = min2 * (n/6) + min1 * n - (n/6);

	cout << ans;
}
