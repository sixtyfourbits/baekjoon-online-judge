#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
 
    int v[1024][1024] = {0};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = -1; j < n - 1; ++j)
        {
            if (i - 1 < 0 && j == -1)
                continue;

            if (j == -1)
                v[i][j+1] += v[i-1][j+1];
            else if (i - 1 < 0)
                v[i][j + 1] += v[i][j];
            else
                v[i][j+1] += v[i][j] + v[i - 1][j + 1] - v[i - 1][j];
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        x1 -= 1; x2 -= 1; y1 -= 1; y2 -= 1;

        if (x1 - 1 < 0 && y1 - 1 < 0)
            cout << v[x2][y2];
        else if(x1 - 1 < 0)
            cout << v[y2][x2] - v[y1 - 1][x2] << '\n';
        else if (y1 - 1 < 0)
            cout << v[y2][x2] - v[y2][x1 - 1] << '\n';
        else 
            cout << v[y2][x2] - v[y2][x1 - 1] - v[y1 - 1][x2] + v[y1 - 1][x1 - 1] << '\n';
    }
}