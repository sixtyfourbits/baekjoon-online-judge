#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int mx = 0;
    int mxi;

    vector<int> a(1000000);
    vector<vector<int> > v(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> v[i][j];
            
            if (mx < v[i][j])
            {
                mx = v[i][j];
                mxi = i;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        a[v[mxi][i]] = i + 1;
    }

    sort(v[mxi].begin(), v[mxi].end());

    for (int i = 0; i < n; ++i)
    {
        cout << a[v[mxi][i]] << " ";
    }
}