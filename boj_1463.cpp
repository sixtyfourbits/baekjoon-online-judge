#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int n;
	cin >> n;

	vector<int> dp(n + 1); // 1 ~ n 까지 연산의 최소 횟수를 저장하는 배열

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; ++i)
	{
		if (i % 2 == 0)
			dp[i] = dp[i / 2] + 1;
		if (i % 3 == 0)
			dp[i] != 0 ? dp[i] = min(dp[i], dp[i / 3] + 1) : dp[i] = dp[i / 3] + 1;
		// 2 또는 3 과 나눠지지 않을 때 -1 을 연산하게 되면 전 수와 동일해지기 때문에
		dp[i] == 0 ? dp[i] = dp[i - 1] + 1 : dp[i] = min(dp[i - 1] + 1, dp[i]); // 현재 수의 최소 연산 횟수 = 전 수의 최소 연산 횟수 + 1
	}

	cout << dp[n];

}
