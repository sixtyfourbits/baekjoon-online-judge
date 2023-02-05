/*
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int arr[100001][3];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    int low[100001][3], high[100001][3];

    high[0][0] = arr[0][0];
    high[0][1] = arr[0][1];
    high[0][2] = arr[0][2];

    low[0][0] = arr[0][0];
    low[0][1] = arr[0][1];
    low[0][2] = arr[0][2];

    for (int i = 1; i < n; ++i)
    {
        high[i][0] = arr[i][0] + max(high[i - 1][0], high[i - 1][1]);
        high[i][1] += arr[i][1] + max(high[i - 1][0], max(high[i - 1][1], high[i - 1][2]));
        high[i][2] += arr[i][2] + max(high[i - 1][1], high[i - 1][2]);

        low[i][0] = arr[i][0] + min(low[i - 1][0], low[i - 1][1]);
        low[i][1] += arr[i][1] + min(low[i - 1][0], min(low[i - 1][1], low[i - 1][2]));
        low[i][2] += arr[i][2] + min(low[i - 1][1], low[i - 1][2]);
    }

    cout << max(high[n - 1][0], max(high[n - 1][1], high[n - 1][2])) << " " << min(low[n - 1][0], min(low[n - 1][1], low[n - 1][2]));
}
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;

    int high[2][3] = {0};
    int low[2][3] = {0};

    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        high[1][0] = a, high[1][1] = b, high[1][2] = c;
        low[1][0] = a, low[1][1] = b, low[1][2] = c;

        high[1][0] += max(high[0][0], high[0][1]);
        high[1][1] += max(high[0][0], max(high[0][1], high[0][2]));
        high[1][2] += max(high[0][1], high[0][2]);

        low[1][0] += min(low[0][0], low[0][1]);
        low[1][1] += min(low[0][0], min(low[0][1], low[0][2]));
        low[1][2] += min(low[0][1], low[0][2]);

        high[0][0] = high[1][0], high[0][1] = high[1][1], high[0][2] = high[1][2];
        low[0][0] = low[1][0], low[0][1] = low[1][1], low[0][2] = low[1][2];
    }

    cout << max(high[0][0], max(high[0][1], high[0][2])) << " " << min(low[0][0], min(low[0][1], low[0][2]));
}