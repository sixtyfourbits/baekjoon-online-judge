#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int mx = 0;
vector<vector<int> > tw;

void func(int x, int y)
{
    int sum = 0;
    for (int i = x - m; i <= x + m; ++i)
    {
        if (i < 0 || i > n - 1)
            continue;

        sum += tw[i][y];
        //cout << "(" << i << "," << y << ")" << endl;
    }
    for (int i = y - m; i <= y + m; ++i)
    {
        if (i < 0 || i > n - 1)
            continue;

        sum += tw[x][i];
        //cout << "(" << x << "," << i << ")" << endl;
    }
    sum -= tw[x][y];

    mx = max(sum, mx);
    //cout << "(" << x << "," << y << ") [CROSS] " << sum << endl << endl;
    

    sum = 0;
    for (int i = -m; i <= m; ++i)
    {
        if (x + i < 0 || x + i > n - 1 || y + i < 0 || y + i > n - 1)
            continue;

        sum += tw[x+i][y+i];
        //cout << "(" << x+i << "," << y+i << ")" << endl;
    }
    for (int i = -m; i <= m; ++i)
    {
        if (x - i < 0 || x - i > n - 1 || y + i < 0 || y + i > n - 1)
            continue;

        sum += tw[x-i][y+i];
        //cout << "(" << x-i << "," << y+i << ")" << endl;
    }
    sum -= tw[x][y];

    mx = max(sum, mx);
    //cout << "(" << x << "," << y << ") [DIG] " << sum << endl << endl;


    if (x == n - 1)
    {
        if (y == n - 1)
            return;
        else
            func(0, y+1);
    }
    else
        func(x + 1, y);
}

int main()
{
    cin >> n >> m;
    tw = vector<vector<int> >(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> tw[i][j];

    func(0, 0);

    cout << mx;
}