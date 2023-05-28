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
    vector<int> ori = v;

    int ans = n - 2;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if ((v[j] - v[i]) % (j - i) == 0)
            {
                int d = (v[j] - v[i]) / (j - i);
                int cnt = 0;

                for (int k = i + 1; k < n; ++k)
                {
                    v[k] = v[k - 1] + d;
                }
                for (int k = i - 1; k >= 0; --k)
                {
                    v[k] = v[k + 1] - d;
                }
                //cout << i << " " << j << endl;
                for (int k = 0; k < n; ++k)
                {
                    if (v[k] != ori[k])
                        ++cnt;

                    //cout << v[k] << " ";
                }
                //cout << " " << cnt << endl;

                ans = min(ans, cnt);
                v = ori;
            }
        }
    }

    cout << ans;
    return 0;
}