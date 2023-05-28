/*
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v(9, vector<int>(9));

vector<vector<int> > ans;
int col[9][9] = {0};
int row[9][9] = {0};
int box[9][9] = {0};


void bt(int x, int y)
{
    if (v[x][y] != 0)
    {
        if (x == 8)
        {
            if (y == 8) 
            {
                if (ans.empty())
                    ans = v;
            }
            else bt(0, y+1);
        }
        else bt(x+1, y);
        
        return;
    }

    int zone;
    if (x >= 0 && x <= 2)
    {
        if (y >= 0 && y <= 2) zone = 0;
        if (y >= 3 && y <= 5) zone = 3;
        if (y >= 6 && y <= 8) zone = 6;
    }
    if (x >= 3 && x <= 5)
    {
        if (y >= 0 && y <= 2) zone = 1;
        if (y >= 3 && y <= 5) zone = 4;                 
        if (y >= 6 && y <= 8) zone = 7;
    }
    if (x >= 6 && x <= 8)
    {
        if (y >= 0 && y <= 2) zone = 2;
        if (y >= 3 && y <= 5) zone = 5;
        if (y >= 6 && y <= 8) zone = 8;
    }

    for (int i = 1; i <= 9; ++i)
    {
        if (!row[y][i - 1] && !col[x][i - 1] && !box[zone][i - 1])
        {
            int rowtmp = row[y][i - 1];
            int coltmp = col[x][i - 1];
            int boxtmp = box[zone][i - 1];

            v[x][y] = i; 
            row[y][i - 1] = col[x][i - 1] = box[zone][i - 1] = false;

            if (x == 8)
            {
                if (y == 8) 
                {
                    if (ans.empty())
                        ans = v;
                    return;
                }
                else bt(0, y+1);
            }
            else bt(x+1, y);

            v[x][y] = 0;
            row[y][i - 1] = rowtmp;
            col[x][i - 1] = coltmp;
            box[zone][i - 1] = boxtmp;
        }
    }
}

int main()
{
    for (int j = 0; j < 9; ++j)
    {
        for (int i = 0; i < 9; ++i)
        {
            cin >> v[i][j];
            if (v[i][j] != 0)
            {
                row[j][v[i][j] - 1] = true;
                col[i][v[i][j] - 1] = true;

                if (i >= 0 && i <= 2)
                {
                    if (j >= 0 && j <= 2) box[0][v[i][j] - 1] = true;
                    if (j >= 3 && j <= 5) box[3][v[i][j] - 1] = true;
                    if (j >= 6 && j <= 8) box[6][v[i][j] - 1] = true;
                }
                if (i >= 3 && i <= 5)
                {
                    if (j >= 0 && j <= 2) box[1][v[i][j] - 1] = true;
                    if (j >= 3 && j <= 5) box[4][v[i][j] - 1] = true;                   
                    if (j >= 6 && j <= 8) box[7][v[i][j] - 1] = true;
                }
                if (i >= 6 && i <= 8)
                {
                    if (j >= 0 && j <= 2) box[2][v[i][j] - 1] = true;
                    if (j >= 3 && j <= 5) box[5][v[i][j] - 1] = true;
                    if (j >= 6 && j <= 8) box[8][v[i][j] - 1] = true;
                }
            }
        }
    }

    bt(0, 0);

    for (int j = 0; j < 9; ++j)
    {
        for (int i = 0; i < 9; ++i)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v(9, vector<int>(9));
vector<vector<int> > ans;
int col[9][9] = {0};
int row[9][9] = {0};
int box[9][9] = {0};

void bt(int x, int y)
{
    int zone;
    if (x >= 0 && x <= 2)
    {
        if (y >= 0 && y <= 2) zone = 0;
        if (y >= 3 && y <= 5) zone = 3;
        if (y >= 6 && y <= 8) zone = 6;
    }
    if (x >= 3 && x <= 5)
    {
        if (y >= 0 && y <= 2) zone = 1;
        if (y >= 3 && y <= 5) zone = 4;                 
        if (y >= 6 && y <= 8) zone = 7;
    }
    if (x >= 6 && x <= 8)
    {
        if (y >= 0 && y <= 2) zone = 2;
        if (y >= 3 && y <= 5) zone = 5;
        if (y >= 6 && y <= 8) zone = 8;
    }

    int i = x;

    for (int j = y; j < 9; ++j)
    {
        for (; i < 9; ++i)
        {
            if (v[i][j] == 0)
            {
                for (int k = 1; k <= 9; ++k)
                {
                    if (!row[y][k - 1] && !col[x][k - 1] && !box[zone][k - 1])
                    {
                        v[x][y] = k; 
                        row[y][k - 1] = col[x][k - 1] = box[zone][k - 1] = true;

                        if (x == 8 && y == 8)
                        {
                            if (ans.empty())
                                ans = v;
                            return;
                        }
                        
                        bt(i, j);

                        v[x][y] = 0;
                        row[y][k - 1] = col[x][k - 1] = box[zone][k - 1] = false;
                    }
                }
            }
        }
        i = 0;
    }
}

int main()
{
    for (int j = 0; j < 9; ++j)
    {
        for (int i = 0; i < 9; ++i)
        {
            cin >> v[i][j];
            if (v[i][j] != 0)
            {
                row[j][v[i][j] - 1] = true;
                col[i][v[i][j] - 1] = true;

                if (i >= 0 && i <= 2)
                {
                    if (j >= 0 && j <= 2) box[0][v[i][j] - 1] = true;
                    if (j >= 3 && j <= 5) box[3][v[i][j] - 1] = true;
                    if (j >= 6 && j <= 8) box[6][v[i][j] - 1] = true;
                }
                if (i >= 3 && i <= 5)
                {
                    if (j >= 0 && j <= 2) box[1][v[i][j] - 1] = true;
                    if (j >= 3 && j <= 5) box[4][v[i][j] - 1] = true;                   
                    if (j >= 6 && j <= 8) box[7][v[i][j] - 1] = true;
                }
                if (i >= 6 && i <= 8)
                {
                    if (j >= 0 && j <= 2) box[2][v[i][j] - 1] = true;
                    if (j >= 3 && j <= 5) box[5][v[i][j] - 1] = true;
                    if (j >= 6 && j <= 8) box[8][v[i][j] - 1] = true;
                }
            }
        }
    }

    bt(0, 0);

    for (int j = 0; j < 9; ++j)
    {
        for (int i = 0; i < 9; ++i)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
