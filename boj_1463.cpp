#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	cin >> n;

	vector<int> dp(n + 1); // 1 ~ n 까지 연산의 최소 횟수를 저장하는 배열

	for (int i = 1; i <= n; ++i)
	{
		if (i % 2 == 0 || i % 3 == 0)
		{
			int i_tmp = i;

		}

		else // 2 또는 3 과 나눠지지 않을 때 -1 을 연산하게 되면 전 수와 동일해지기 때문에
			dp[i] = dp[i - 1] + 1; // 현재 수의 최소 연산 횟수 = 전 수의 최소 연산 횟수 + 1
	}

	cout << dp[n];

}
