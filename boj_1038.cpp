#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> v;
    for (int i = 0; i <= 9; ++i)
        v.push_back(i);

    int j = 0;
    while (true)
    {
        long long a = v[j];
        long long b = 0;
        int cnt = 0;
        while (a != 0)
        {
            ++cnt;
            b = a % 10;
            a /= 10;
        }

        if (cnt == 10)
            break;

        for (int k = b + 1; k <= 9; ++k)
        {
            long long num = 10;
            for (int l = 0; l < cnt - 1; ++l)
                num *= 10;

            v.push_back(v[j] + num * k);
        }
        ++j;
    }

    sort(v.begin(), v.end());

    if (n > v.size() - 1)
        cout << -1;
    else
        cout << v[n];
}