#include <vector>
#include <iostream>

using namespace std; 

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    vector<int> dp;
    dp.push_back(1);

    for (int i = 1; i < n; ++i)
    {
        int max = 0;
        for (int j = 0; j < i; ++j)
        {
            if (v[j] < v[i])
            {
                if (dp[j] > max)
                    max = dp[j];
            }
        }

        dp.push_back(max + 1);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (ans < dp[i])
            ans = dp[i];

    cout << ans;
}