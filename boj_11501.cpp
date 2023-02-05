#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
long long sum;
vector<long long> v(n);
vector<long long> b(n);

int main()
{
    int t; cin >> t;
    for (int c = 0; c < t; ++c)
    {
        cin >> n;
        sum = 0;
        v = vector<long long>(n, 0);
        b = vector<long long>(n, 0);
        
        for (int i = 0; i < n; ++i) cin >> v[i];

        long long mx = -1;
        for (int i = n - 1; i >= 0; --i)
        {
            if (v[i] > mx) mx = v[i];

            b[i] = mx;
        }


        for (int i = 0; i < n - 1; ++i)
        {
            if (v[i] < b[i + 1])
            {
                sum += b[i + 1] - v[i];
            }
        }

        cout << sum << endl;
    }
}