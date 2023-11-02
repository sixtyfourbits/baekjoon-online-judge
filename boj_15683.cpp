#include <iostream>
#include <vector>

using namespace std;

int n, m;
int res;
vector<vector<int> > v;

void back_tracking (int x, int y, int degree)
{
    if (v[x][y] == 1)
    {
        if (degree == 0)
        {
            for (int i = y + 1; i < m; ++i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
        }
        else if (degree == 90)
        {
            for (int i = x + 1; i < n; ++i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
        }
        else if (degree == 180)
        {
            for (int i = y - 1; i >= 0; --i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
        }
        else
        {
            for (int i = x - 1; i >= 0; --i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
        }
    }
    else if (v[x][y] == 2)
    {
        if (degree == 0)
        {
            for (int i = y + 1; i < m; ++i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
            for (int i = y - 1; i >= 0; --i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
        }
        else
        {
            for (int i = x + 1; i < n; ++i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
            for (int i = x - 1; i >= 0; --i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
        }
    }
    else if (v[x][y] == 3)
    {
        if (degree == 0)
        {
            for (int i = y + 1; i < m; ++i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
            for (int i = x - 1; i >= 0; --i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
        }
        else if (degree == 90)
        {
            for (int i = y + 1; i < m; ++i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
            for (int i = x + 1; i < n; ++i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
        }
        else if (degree == 180)
        {
            for (int i = y - 1; i >= 0; --i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
            for (int i = x + 1; i < n; ++i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
        }
        else
        {
            for (int i = y - 1; i >= 0; --i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
            for (int i = x - 1; i >= 0; --i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
        }
    }
    else if (v[x][y] == 4)
    {
        if (degree == 0)
        {
            for (int i = y + 1; i < m; ++i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
            for (int i = x - 1; i >= 0; --i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
            for (int i = y - 1; i >= 0; --i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
        }
        else if (degree == 90)
        {
            for (int i = y + 1; i < m; ++i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
            for (int i = x + 1; i < n; ++i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
            for (int i = x - 1; i >= 0; --i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
        }
        else if (degree == 180)
        {
            for (int i = y + 1; i < m; ++i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
            for (int i = y - 1; i >= 0; --i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
            for (int i = x + 1; i < n; ++i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
        }
        else
        {
            for (int i = y - 1; i >= 0; --i)
            {
                if (v[x][i] == 6)
                    break;
                if (v[x][i] == 0)
                    v[x][i] = -1;
            }
            for (int i = x - 1; i >= 0; --i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
            for (int i = x + 1; i < n; ++i)
            {
                if (v[i][y] == 6)
                    break;
                if (v[i][y] == 0)
                    v[i][y] = -1;
            }
        }
    }
    else if (v[x][y] == 5)
    {
        for (int i = y + 1; i < m; ++i)
        {
            if (v[x][i] == 6)
                break;
            if (v[x][i] == 0)
                v[x][i] = -1;
        }
        for (int i = y - 1; i >= 0; --i)
        {
            if (v[x][i] == 6)
                break;
            if (v[x][i] == 0)
                v[x][i] = -1;
        }
        for (int i = x - 1; i >= 0; --i)
        {
            if (v[i][y] == 6)
                break;
            if (v[i][y] == 0)
                v[i][y] = -1;
        }
        for (int i = x + 1; i < n; ++i)
        {
            if (v[i][y] == 6)
                break;
            if (v[i][y] == 0)
                v[i][y] = -1;
        }
    }
    if (x >= n - 1 && y >= m - 1)
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(v[i][j] == 0)
                    ++cnt;
            }
        }

        //cout << cnt << endl;
        res = min(res, cnt);
        return;
    }

    vector<vector<int> > vtmp = v;
    
    int tmp = y + 1;
    for (int i = x; i < n; ++i)
    {
        for (int j = tmp; j < m; ++j)
        {
            if (v[i][j] == 1 || v[i][j] == 3 || v[i][j] == 4)
            {
                back_tracking(i, j, 0);
                v = vtmp;
                back_tracking(i, j, 90);
                v = vtmp;
                back_tracking(i, j, 180);
                v = vtmp;
                back_tracking(i, j, 270);

                return;
            }
            else if (v[i][j] == 2)
            {
                back_tracking(i, j, 0);
                v = vtmp;
                back_tracking(i, j, 90);

                return;
            }
            else if (v[i][j] == 5)
            {
                back_tracking(i, j, 0);
                
                return;
            }
            else
            {
                if (i == n - 1 && j == m - 1)
                {
                    int cnt = 0;
                    for (int i = 0; i < n; ++i)
                    {
                        for (int j = 0; j < m; ++j)
                        {
                            if(v[i][j] == 0)
                                ++cnt;
                        }
                    }

                    //cout << cnt << endl;
                    res = min(res, cnt);
                    return;
                }
            }
        }

        tmp = 0;
    }
}

int main ()
{
    cin >> n >> m;
    v = vector<vector<int> >(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> v[i][j];
    }

    res = n * m;

    if (v[0][0] == 0 || v[0][0] == 6)
        back_tracking(0, 0, 0);
    else
    {
        vector<vector<int> > vtmp = v;

        if (v[0][0] == 1 || v[0][0] == 3 || v[0][0] == 4)
        {
            back_tracking(0, 0, 0);
            v = vtmp;
            back_tracking(0, 0, 90);
            v = vtmp;
            back_tracking(0, 0, 180);
            v = vtmp;
            back_tracking(0, 0, 270);
        }
        else if (v[0][0] == 2)
        {
            back_tracking(0, 0, 0);
            v = vtmp;
            back_tracking(0, 0, 90);
        }
        else
        {
            back_tracking(0, 0, 0);
        }
    }

    cout << res;
}