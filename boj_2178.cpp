#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int minimum = 999999;
vector<vector<int> > v;
vector<vector<bool> > check(false);

void func(int sum, int x, int y)
{
    if (check[x][y])
        return;
    
    check[x][y] = true;

    if (x == n - 1 && y == m - 1)
    {
        minimum = min(minimum, v[x][y]);
        return;
    }

    if (x - 1 >= 0)
        if (v[x - 1][y])
            func(sum + 1, x - 1, y);
    if (x + 1 < n)
        if (v[x + 1][y])
            func(sum + 1, x + 1, y);
    if (y - 1 >= 0)
        if (v[x][y - 1])
            func(sum + 1, x, y - 1);
    if (y + 1 < m)
        if (v[x][y + 1])
            func(sum + 1, x, y + 1);
}

int main()
{
    cin >> n >> m;
    
    v = vector<vector<int> >(n, vector<int>(m));
    check = vector<vector<bool> >(n, vector<bool>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%1d", &v[i][j]);

    func(0, 0, 0);

    cout << minimum;
}