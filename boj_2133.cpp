#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 0;
vector<vector<int> > v;

void bt(int x, int y, int depth)
{
    cout << x << " , " << y << " / " << depth << endl;
    if (v[x][y])
    {
        if (x == n - 1)
        {
            if (y == 2)
            {
                ++cnt;
                cout << "CNT" << endl;
                return;
            }
            else
            {
                bt(0, y + 1, depth+1);
            }
        }
        else
        {
            bt(x + 1, y, depth+1);
        }
    }

    if (x == n - 1 || v[x + 1][y])
    {
        if (y == 2 || v[x][y + 1])
        {
            return;
        }
        else
        {
            v[x][y] = v[x][y + 1] = 1;
            bt(0, y + 1, depth+1);
            v[x][y] = v[x][y + 1] = 0;
        }
    }
    else
    {
        if (y == 2 || v[x][y + 1])
        { 
            v[x + 1][y] = v[x][y] = 1;
            bt(x + 1, y, depth+1);
            v[x + 1][y] = v[x][y] = 0;
        }
        else
        {
            v[x + 1][y] = v[x][y] = 1;
            if (x < n - 2)
            {
                bt(x + 2, y, depth+1);
            }
            else
            {
                bt(0, y + 1, depth+1);
            }
            
            v[x + 1][y] = v[x][y] = 0;

            v[x][y] = v[x][y + 1] =  1;
            bt(x + 1, y, depth+1);
            v[x][y] = v[x][y + 1] = 0;
        }
    }
}

int main()
{
    cin >> n;

    v = vector<vector<int> >(n, vector<int>(3));

    bt(0, 0, 0);

    cout << cnt;
}