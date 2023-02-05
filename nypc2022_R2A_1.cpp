#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n;
    int mx = 1;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 0; i < n - 1; ++i)
    {
        int cnt = 0;
        vector<int> check(1000001, -1);

        for (int j = i; j < n; ++j)
        {
            if (check[v[j]] != -1)
            {
                if (mx < cnt)
                    mx = cnt;

                i = check[v[j]];
                
                break;
            }

            check[v[j]] = j;
            ++cnt;

            if (j == n - 1)
            {
                if (mx < cnt)
                    mx = cnt;
                break;
            }
        }
    }

    cout << mx;
}