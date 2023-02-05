#include <iostream>


using namespace std;

int main()
{
    int n;
    long long dp[90];
    
    dp[0] = 1;
    dp[1] = 1;
    cin >> n;

    for (int i = 2; i < n; ++i)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    cout << dp[n - 1];
}