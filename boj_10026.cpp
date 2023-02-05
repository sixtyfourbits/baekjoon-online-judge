#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> s;

void func(int x, int y, char c)
{
    if (x >= n || y >= n || x < 0 || y < 0)
        return;

    if (s[x][y] == c)
    {
        s[x][y] = 'N';

        func(x+1, y, c);
        func(x, y+1, c);
        func(x -1, y, c);
        func(x, y-1, c);
    }
    else
    {
        return;
    }
}

int main()
{
    int normal = 0;
    int rg = 0;

    cin >> n;
    s = vector<string>(n);
    vector<string> tmp;
    for (int i = 0; i < n; ++i) cin >> s[i];

    tmp = s;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (tmp[i][j] == 'G')
                tmp[i][j] = 'R';
                
            if (s[i][j] != 'N')
            {
                func(i, j, s[i][j]);
                ++normal;
            }
        }
    }

    s = tmp;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {       
            if (s[i][j] != 'N')
            {
                func(i, j, s[i][j]);
                ++rg;
            }
        }
    }

    cout << normal << ' ' << rg;
}