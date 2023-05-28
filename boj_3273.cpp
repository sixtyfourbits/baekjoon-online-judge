#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; 
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    int x; 
    cin >> x;

    int cnt = 0;
    int i  = 0;
    int j = n - 1;

    for (;;)
    {
        if (i >= j)
            break;

        if (v[i] + v[j] == x)
        {
            ++cnt;
            --j;
        }
        else if (v[i] + v[j] < x)
            ++i;
        else
            --j;
    }

    cout << cnt;
}