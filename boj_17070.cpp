#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 0;
vector<vector<int> > v;

void func(int r, int c, int s)
{
    if (r == n - 1 && c == n - 1)
    {
        ++cnt;
    }
    // 0 = →  |  1 = ↓  |   2 = ↘
    if (s == 0)
    {
        if (c + 1 < n && v[r][c + 1] == 0)
        {
            func(r, c + 1, 0);
        }
        if (c + 1 < n && r + 1 < n && v[r + 1][c + 1] == 0)
        {
            if (v[r][c + 1] == 0 && v[r + 1][c] == 0)
            {
                func(r + 1, c + 1, 2);
            }
        }
    }

    if (s == 1)
    {
        if (r + 1 < n && v[r + 1][c] == 0)
        {
            func(r + 1, c, 1);
        }
        if (c + 1 < n && r + 1 < n && v[r + 1][c + 1] == 0)
        {
            if (v[r][c + 1] == 0 && v[r + 1][c] == 0)
            {
                func(r + 1, c + 1, 2);
            }
        }
    }
    if (s == 2)
    {
        if (c + 1 < n && v[r][c + 1] == 0)
        {
            func(r, c + 1, 0);
        }
        if (r + 1 < n && v[r + 1][c] == 0)
        {
            func(r + 1, c, 1);
        }
         if (c + 1 < n && r + 1 < n && v[r + 1][c + 1] == 0)
        {
            if (v[r][c + 1] == 0 && v[r + 1][c] == 0)
            {
                func(r + 1, c + 1, 2);
            }
        }
    }
    
}

int main()
{
    cin >> n;
    v = vector<vector<int> >(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];

    func(0, 1, 0);

    cout << cnt;
}