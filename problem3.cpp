#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; 
    cin >> n;

    int mx = 0;

    vector<vector<char> > v(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];

    int o, p;
    cin >> o >> p;
    vector<int> hr(o + 2);
    vector<int> vr(p + 2);
    for (int i = 1; i <= o; ++i)
        cin >> hr[i];
    for (int i = 1; i <= p; ++i)
        cin >> vr[i];

    hr[o + 1] = n;
    vr[p + 1] = n;

    for (int i = 1; i <= o + 1; ++i)
    {
        for (int j = 1; j <= p + 1; ++j)
        {
            vector<bool> a(26);
            for (int k = vr[i - 1]; k < vr[i]; ++k)
            {
                for (int l = hr[j - 1]; l < hr[j]; ++l)
                {
                    a[v[k][l] - 97] = true;
                }
            }

            int cnt = 0;
            for (int i = 0; i < 26; ++i)
                if (a[i])
                    ++cnt;

            mx = max(mx, cnt);
        }
    }

    cout << mx;
}