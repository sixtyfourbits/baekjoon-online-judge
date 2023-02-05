#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > v(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%1d", &v[i][j]);

    queue<vector<int> > q;
    vector<int> t(2);
    t[0], t[1] = 0;
    q.push(t);

    vector<vector<int> > check(n, vector<int>(m, false));
    check[0][0] = true;


while (q.size() > 0)
{
    int x = q.front()[1];
    int y = q.front()[0];

    if (x + 1 < m && v[y][x + 1] && !check[y][x+1])
    {
        v[y][x+1] = v[y][x] + 1;
        
        check[y][x+1] = !check[y][x+1];
        t[0] = y; t[1] = x+1;
        q.push(t);
    }
    if (x - 1 >= 0 && v[y][x - 1] && !check[y][x-1])
    {
        v[y][x-1] = v[y][x] + 1;

        check[y][x-1] = !check[y][x-1];
        t[0] = y; t[1] = x-1;
        q.push(t);
    }
    if (y + 1 < n && v[y + 1][x] && !check[y+1][x])
    {
        v[y+1][x] = v[y][x] + 1;

        check[y+1][x] = !check[y+1][x];
        t[0] = y+1; t[1] = x;
        q.push(t);
    }
    if (y - 1 >= 0 && v[y - 1][x] && !check[y-1][x])
    {
        v[y-1][x] = v[y][x] + 1;

        check[y-1][x] = !check[y-1][x];
        t[0] = y-1; t[1] = x;
        q.push(t);
    }

    q.pop();

}

cout << v[n - 1][m - 1];

}