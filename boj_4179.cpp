/*
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int r, c;
    int x, y;
    int fx, fy;
    int cnt = 0;
    cin >> r >> c;

    vector<vector<char> > v(r, vector<char>(c));
    for (int j = 0; j < c; ++j)
    {
        for (int i = 0; i < r; ++i)
        {
            cin >> v[i][j];
            if (v[i][j] == 'J')
            {
                x = i; y = j;
            }
            else if (v[i][j] == 'F')
            {
                fx = i; fy = j;
            }
        }
    }
    stack<vector<int> > t;
    stack<vector<int> > f;

    t.push({x, y});
    f.push({fx, fy});

    while (true)
    {
        ++cnt;
        if (t.size() == 0)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }

        int fs = f.size();

        //cout << "fs: " << fs << endl;
        for (int i = 0; i < fs; ++i)
        {
            vector<int> ft = f.top();
            v[ft[0]][ft[1]] = 'F';
            //cout << "FIRE: " << ft[0] << ' ' << ft[1] << endl;
            f.pop();

            if (ft[0] + 1 < r && v[ft[0] + 1][ft[1]] != '#' && v[ft[0] + 1][ft[1]] != 'F')
            {
                f.push({ft[0] + 1, ft[1]});
            }
            if (ft[0] - 1 >= 0 && v[ft[0] - 1][ft[1]] != '#' && v[ft[0] - 1][ft[1]] != 'F')
            {
                f.push({ft[0] - 1, ft[1]});
            }
            if (ft[1] + 1 < c && v[ft[0]][ft[1] + 1] != '#' && v[ft[0]][ft[1] + 1] != 'F')
            {
                f.push({ft[0], ft[1] + 1});
            }
            if (ft[1] - 1 >= 0 && v[ft[0]][ft[1] - 1] != '#' && v[ft[0]][ft[1] - 1] != 'F')
            {
                f.push({ft[0], ft[1] - 1});
            }
        }

        int ts = t.size();
        //cout << "ts: " << ts << endl;
        for (int i = 0; i < ts; ++i)
        {
            vector<int> jt = t.top(); 
            v[jt[0]][jt[1]] = '!';
            //cout << "JIHOON: " << jt[0] << ' ' << jt[1] << endl;
            t.pop(); 

            if (jt[0] <= 0 || jt[0] >= r - 1 || jt[1] <= 0 || jt[1] >= c - 1)
            {
                cout << cnt;
                return 0;
            }

            if (jt[0] + 1 < r && v[jt[0] + 1][jt[1]] == '.')
            {
                t.push({jt[0] + 1, jt[1]});
            }
            if (jt[0] - 1 >= 0 && v[jt[0] - 1][jt[1]] == '.')
            {
                t.push({jt[0] - 1, jt[1]});
            }
            if (jt[1] + 1 < c && v[jt[0]][jt[1] + 1] == '.')
            {
                t.push({jt[0], jt[1] + 1});
            }
            if (jt[1] - 1 >= 0 && v[jt[0]][jt[1] - 1] == '.')
            {
                t.push({jt[0], jt[1] - 1});
            }
        }
    }

    cout << "IMPOSSIBLE";
}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
vector<vector<char> > v(r, vector<char>(c));

vector<vector<int> > j(r, vector<int>(c, -1));
vector<vector<int> > f(r, vector<int>(c, -1));

void jh(int x, int y, int cnt)
{
    if (!(x >= 0 && x < r && y >= 0 && y < c) || v[x][y] == '#' || v[x][y] == 'F')
        return;

    if (j[x][y] == -1)
        j[x][y] = cnt;
    else
    {
        j[x][y] = min(j[x][y], cnt);
        return;
    }
    

    jh(x + 1, y, cnt + 1);
    jh(x - 1, y, cnt + 1);
    jh(x, y + 1, cnt + 1);
    jh(x, y - 1, cnt + 1);
}

void fire(int x, int y, int cnt)
{
    if (!(x >= 0 && x < r && y >= 0 && y < c) || v[x][y] == '#')
        return;

    if (f[x][y] == -1)
        f[x][y] = cnt;
    else
    {
        f[x][y] = min(f[x][y], cnt);
        return;
    }
    

    fire(x + 1, y, cnt + 1);
    fire(x - 1, y, cnt + 1);
    fire(x, y + 1, cnt + 1);
    fire(x, y - 1, cnt + 1);
}

int main()
{
    cout << 'a';
    int x, y, fx, fy;

    cin >> r >> c;
    v = vector<vector<char> >(r, vector<char>(c));
    
    for (int j = 0; j < c; ++j)
    {
        cout << 'a';
        for (int i = 0; i < r; ++i)
        {
            cin >> v[i][j];
            if (v[i][j] == 'J')
            {
                x = i, y = j;
            }
            else if (v[i][j] == 'F')
            {
                fx = i, fy = j;
            }
        }
    }
    cout << 'a';
    fire(fx, fy, 0);
    cout << 'a';
    jh(x, y, 0);

    int ans = 1000001;

    for (int i = 0; i < r; ++i)
    {
        if (j[i][0] - f[i][0] > 0)
            ans = min(ans, j[i][0] - f[i][0]);
        if (j[i][c-1] - f[i][c-1] > 0)
            ans = min(ans, j[i][c-1] - f[i][c-1]);
    }
    for (int i = 0; i < c; ++i)
    {
        if (j[0][i] - f[0][i] > 0)
            ans = min(ans, j[0][i] - f[0][i]);
        if (j[r-1][i] - f[r-1][i] > 0)
            ans = min(ans, j[r-1][i] - f[r-1][i]);
    }

    if (ans == 1000001)
        cout << "IMPOSSIBLE";
    else
        cout << ans;


}