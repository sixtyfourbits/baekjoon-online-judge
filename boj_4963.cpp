/*
#include <vector>
#include <iostream>

using namespace std;


int w, d;
int cnt = 0;
vector<vector<int> > v;

void dfs(int x, int y)
{
    if (x < 0 || x >= w || y < 0 || y >= d || !v[x][y])
        return;

    cout << "(" << x << "," << y << ")" << endl;

    v[x][y] = 0;

    dfs(x + 1, y);
    dfs(x + 1, y + 1);
    dfs(x + 1, y - 1);
    dfs(x - 1, y);
    dfs(x - 1, y + 1);
    dfs(x - 1, y - 1);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main()
{
    while (true)
    {
        cin >> w >> d;
        v = vector<vector<int> >(w, vector<int>(7));
        cnt = 0;

        if (w == 0 && d == 0)
            break;

        for (int i = 0; i < w; ++i)
            for (int j = 0; j < d; ++j)
                cin >> v[i][j];

        for (int i = 0; i < w; ++i)
        {
            for (int j = 0; j < d; ++j)
            {
                if (v[i][j])
                {
                    dfs(i, j);
                    ++cnt;
                }
            }
        }

        for (int i = 0; i < d; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cout << v[j][i] << " ";
            }
            cout << endl;
        }
        cout << cnt << endl;
    }
}
*/

#include <vector>
#include <iostream>

using namespace std;

int w, h;
vector<vector<int> > v;

void dfs(int x, int y)
{
    if (x < 0 || x >= w || y < 0 || y >= h || !v[y][x])
        return;
    //cout << "[" << y << "," << x << "] | " << v[y][x] << endl;

    v[y][x] = 0;

    dfs(x, y + 1);
    dfs(x, y - 1);
    dfs(x + 1, y);
    dfs(x + 1, y + 1);
    dfs(x + 1, y - 1);
    dfs(x - 1, y);
    dfs(x - 1, y + 1);
    dfs(x - 1, y - 1);
}

int main()
{
    while(true)
    {
        int cnt = 0;

        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        v = vector<vector<int> >(h, vector<int>(w));
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> v[i][j];
            }
        }

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (v[i][j])
                {
                    ++cnt;
                    dfs(j, i);
                }
            }
        }

        cout << cnt << endl;
    }
}