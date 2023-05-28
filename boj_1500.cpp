#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int s, k;
    cin >> s >> k;

    int arr[21];
    int sum = 0;
    long long ans = 1;

    for (int i = 0; i < k; ++i)
    {
        arr[i] = ceil((float)s/k);
        sum += arr[i];
    }

    for (int i = 0; i < sum - s; ++i) --arr[i];
    for (int i = 0; i < k; ++i) ans *= arr[i];

    cout << ans;
}