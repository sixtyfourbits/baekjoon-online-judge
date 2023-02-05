#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v;

void flip (int x, int y)
{
    for (int j = 0; j <= y; ++j)
    {
        for (int i = 0; i <= x; ++i)
        {
            v[i][j] = !v[i][j];
        }
    }
    /*
    cout << endl;
    cout << x << " " << y;
    cout << endl;
    for (auto& i : v)
    {
        for (auto& j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
    */
}

int main ()
{
    int n, m;
    cin >> n >> m;  

    v = vector<vector<int> >(m, vector<int>(n));
    for (int j = 0; j < n; ++j)
        for (int i = 0; i < m; ++i)
            scanf("%1d", &v[i][j]);

    int cnt = 0;

    for (int i = m - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            if (v[i][j])
            {
                flip(i, j);
                ++cnt;
            }
        }
    }

    cout << cnt;
}