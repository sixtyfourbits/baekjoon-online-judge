#include <iostream>
#include <vector>

using namespace std;

int n, m, t;
int block = 0;
vector<vector<int> > v;

void dfs (int x, int y)
{   
    if (x < 0 || y < 0 || x >= n || y >= m)
        return;

    if (v[x][y] >= t)
    {
        v[x][y] = -1;

        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
    }
}

int main ()
{
    cin >> n >> m;
    v = vector<vector<int> >(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                int a;
                cin >> a;

                v[i][j] += a;
            }
        }
    }
    cin >> t;
    t *= 3;


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (v[i][j] >= t)
            {
                dfs(i, j);
                ++block;
            }
        }
    }

    cout << block;
}