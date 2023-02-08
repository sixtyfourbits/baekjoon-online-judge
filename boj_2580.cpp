#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v(9, vector<int>(9));

vector<bool> scan(int x, int y)
{
    vector<bool> check(10, false);

    for (int i = 0; i < 9; ++i)
        check[v[i][y]] = true;

    for (int j = 0; j < 9; ++j)
        check[v[x][j]] = true;
    
    if (x >= 0 && x <= 2)
    {
        if (y >= 0 && y <= 2)
        {
            for (int j = 0; j < 3; ++j)
                for (int i = 0; i < 3; ++i)
                    check[v[i][j]] = true;
        }
        if (y >= 3 && y <= 5)
        {
            for (int j = 3; j < 6; ++j)
                for (int i = 0; i < 3; ++i)
                    check[v[i][j]] = true;
        }
        if (y >= 6 && y <= 8)
        {
            for (int j = 6; j < 9; ++j)
                for (int i = 0; i < 3; ++i)
                    check[v[i][j]] = true;
        }
    }
    if (x >= 3 && x <= 5)
    {
        if (y >= 0 && y <= 2)
        {
            for (int j = 0; j < 3; ++j)
                for (int i = 3; i < 6; ++i)
                    check[v[i][j]] = true;
        }
        if (y >= 3 && y <= 5)
        {
            for (int j = 3; j < 6; ++j)
                for (int i = 3; i < 6; ++i)
                    check[v[i][j]] = true;
        }
        if (y >= 6 && y <= 8)
        {
            for (int j = 6; j < 9; ++j)
                for (int i = 3; i < 6; ++i)
                    check[v[i][j]] = true;
        }
    }
    if (x >= 6 && x <= 8)
    {
        if (y >= 0 && y <= 2)
        {
            for (int j = 0; j < 3; ++j)
                for (int i = 6; i < 9; ++i)
                    check[v[i][j]] = true;
        }
        if (y >= 3 && y <= 5)
        {
            for (int j = 3; j < 6; ++j)
                for (int i = 6; i < 9; ++i)
                    check[v[i][j]] = true;
        }
        if (y >= 6 && y <= 8)
        {
            for (int j = 6; j < 9; ++j)
                for (int i = 6; i < 9; ++i)
                    check[v[i][j]] = true;
        }
    }

    return check;
}
void bt(int x, int y)
{
    if (v[x][y] != 0)
    {
        if (x >= 8)
        {
            if (y >= 8)
            {
                for (int j = 0; j < 9; ++j)
                {
                    for (int i = 0; i < 9; ++i)
                        cout << v[i][j] << " ";
                    cout << endl;
                }
                return;
            }
            
            bt(0, y+1);
        }
        else bt(x+1, y);
    }
    vector<bool> check = scan(x, y);

    for (int i = 1; i <= 9; ++i)
    {
        if (!check[i])
        {
            v[x][y] = i;
            if (x >= 8)
            {
                if (y >= 8)
                {
                    for (int j = 0; j < 9; ++j)
                    {
                        for (int i = 0; i < 9; ++i)
                            cout << v[i][j] << " ";
                        cout << endl;
                    }
                    return;
                }
                
                bt(0, y+1);
            }
            else bt(x+1, y);

            v[x][y] = 0;
        }
    }
}

int main()
{
    for (int j = 0; j < 9; ++j)
        for (int i = 0; i < 9; ++i)
            cin >> v[i][j];

    bt(0, 0);
}