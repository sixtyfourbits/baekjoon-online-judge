#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int arr[100001];
    
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    long long ans = 0;
    int a = 1;
    ans += arr[0] - a;
    arr[0] -= arr[0] - a;
    ++a;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] == arr[i - 1])
            continue;
        
        ans += arr[i] - a;
        arr[i] -= arr[i] - a;
        ++a;
    }

    cout << ans;
}