#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int cnt = 0;

    vector<string> d(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    vector<vector<char> > ans(n, vector<char>(m));

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            vector<int> a(26);
            for (int p = 0; p < n; p += k)
            {
                for (int q = 0; q < m; q += k)
                {
                    ++a[d[p+i][q+j] - 65];
                }
            }

            int mx = a[0];
            int mxi = 0;
            int sum = 0;

            for (int l = 0; l < 26; ++l)
            {
                sum += a[l];
                if (a[l] > mx)
                {
                    mx = a[l];
                    mxi = l;
                }
            }

            cnt += sum - a[mxi];

            for (int p = 0; p < n; p += k)
            {
                for (int q = 0; q < m; q += k)
                {
                    ans[p+i][q+j] = mxi + 65;
                }
            }
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}