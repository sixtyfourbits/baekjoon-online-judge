#include <iostream>
#include <vector>

using namespace std;

int h, w;
int a, b, c, d;
string ans;

vector<vector<int> > v;
vector<vector<int> > obs;

void func(int x, int y, int heading, int drift, string s) // heading: 0 = left, 1 = right, 2 = up, 3 = down
{ 

    cout << x << " " << y << " " << heading << " " << drift << endl;
    if (x == a && y == b)
    {
        if (x + 1 <= h && v[x+1][y] == 0)
            func(x+1, y, 3, drift+1, "S");
        if (x - 1 > 0 && v[x-1][y] == 0)
            func(x-1, y, 2, drift+1, "W");
        if (y + 1 <= w && v[x][y+1] == 0)
            func(x, y+1, 1, drift+1, "D");
        if (y - 1 > 0 && v[x][y-1] == 0)
            func(x, y-1, 0, drift+1, "A");
        return;
    }

    if (drift > v[x][y])
    {
        //cout << x << ' ' << y << endl;
        v[x][y] = drift;

        if (x == c && y == d)
        {
            ans = s;
            return;
        }
        if (heading == 0)
        {
            if (x + 1 <= h && v[x + 1][y] < drift && v[x+1][y] != -1)
                func(x+1, y, 3, drift + 1, s + "S");

            if (x - 1 > 0 && v[x - 1][y] < drift && v[x-1][y] != -1)
                func(x-1, y, 2, drift + 1, s + "W");

            if (y - 1 > 0 && v[x][y - 1] < drift && v[x][y - 1] != -1)
                func(x, y-1, 0, drift, s + "A");

            return;
        }
        else if (heading == 1)
        {
            if (x + 1 <= h && v[x + 1][y] < drift && v[x+1][y] != -1)
                func(x+1, y, 3, drift + 1, s + "S");

            if (x - 1 > 0 && v[x - 1][y] < drift && v[x-1][y] != -1)
                func(x-1, y, 2, drift + 1, s + "W");

            if (y + 1 <= w && v[x][y + 1] < drift && v[x][y + 1] != -1)
                func(x, y+1, 1, drift, s + "D");

            return;
        }
        else if (heading == 2)
        {
            if (y + 1 <= w && v[x][y + 1] < drift && v[x][y + 1] != -1)
                func(x, y+1, 1, drift + 1, s + "D");

            if (y - 1 > 0 && v[x][y - 1] < drift && v[x][y - 1] != -1)
                func(x, y-1, 0, drift + 1, s + "A");

            if (x - 1 > 0 && v[x - 1][y] < drift && v[x-1][y] != -1)
                func(x-1, y, 2, drift, s + "W");

            return;
        }
        else if (heading == 3)
        {
            if (y + 1 <= w && v[x][y + 1] < drift && v[x][y + 1] != -1)
                func(x, y+1, 1, drift + 1, s + "D");

            if (y - 1 > 0 && v[x][y - 1] < drift && v[x][y - 1] != -1)
                func(x, y-1, 0, drift + 1, s + "A");
                
            if (x + 1 <= h && v[x + 1][y] < drift && v[x+1][y] != -1)
                func(x+1, y, 3, drift, s + "S");

            return;
        }
    }
}

int main()
{
    cin >> h >> w;
    cin >> a >> b >> c >> d;

    v = vector<vector<int> >(h+1, vector<int>(w+1, 0));
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            char c; cin >> c;
            if (c == '#')
            {
                v[i][j] = -1;
            }
        }
    }

    func(a, b, 0, 0, "");

    cout << v[c][d] - 1 << endl << ans << endl;
}