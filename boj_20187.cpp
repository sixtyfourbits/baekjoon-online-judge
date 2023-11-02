#include <iostream>
#include <vector>
#include <string>

using namespace std;

int k, h;
int tpk;
vector<char> fold;
vector<vector<int> > paper;

void func (int x, int y, int i, int hl, int vl)
{
    if (i < 0) return;

    else if (fold[i] == 'R')
    {
        if (paper[x][y] == 1 || paper[x][y] == 3)
            paper[tpk - 1 - x + tpk - hl][y] = paper[x][y] - 1;
        else
            paper[tpk - 1 - x + tpk - hl][y] = paper[x][y] + 1;

        func(tpk - 1 - x + tpk - hl, y, i - 1, hl * 2, vl);
        func(x, y, i - 1, h * 2, vl);
    }
    else if (fold[i] == 'L')
    {
        if (paper[x][y] == 1 || paper[x][y] == 3)
            paper[tpk - 1 - x - (tpk - hl)][y] = paper[x][y] - 1;
        else
            paper[tpk - 1 - x - (tpk - hl)][y] = paper[x][y] + 1;

        func(tpk - 1 - x - (tpk - hl), y, i - 1, hl * 2, vl);
        func(x, y, i - 1, h * 2, vl);
    }
    else if (fold[i] == 'D')
    {
        if (paper[x][y] == 2 || paper[x][y] == 3)
            paper[x][tpk - 1 - x + tpk - vl] = paper[x][y] - 2;
        else
            paper[x][tpk - 1 - x + tpk - vl] = paper[x][y] + 2;

        func(x, tpk - 1 - x + tpk - vl, i - 1, hl, vl * 2);
        func(x, y, i - 1, h, vl * 2);
    }
    else //fold[i] == 'U'
    {
        if (paper[x][y] == 2 || paper[x][y] == 3)
            paper[x][tpk - 1 - x - (tpk - vl)] = paper[x][y] - 2;
        else
            paper[x][tpk - 1 - x - (tpk - vl)] = paper[x][y] + 2;
        
        func(x, tpk - 1 - x - (tpk - vl), i - 1, hl, vl * 2);
        func(x, y, i - 1, h, vl * 2);
    }
}

int main()
{
    cin >> k;

    fold = vector<char>(2*k);
    for (int i = 0; i < 2*k; ++i) cin >> fold[i];

    tpk = 1<<k;
    paper = vector<vector<int> >(tpk, vector<int>(tpk));

    cin >> h;

    int start[2] = {0, 0};
    int end[2] = {tpk - 1, tpk - 1};
    
    for (int i = 0; i < 2 * k; ++i)
    {
        if (fold[i] == 'D')
        {
            start[1] = (start[1] + end[1] + 1) / 2;
        }
        if (fold[i] == 'U')
        {
            end[1] = (start[1] + end[1] + 1) / 2 - 1;
        }
        if (fold[i] == 'R')
        {
            start[0] = (start[0] + end[0] + 1) / 2;
        }
        if (fold[i] == 'L')
        {
            end[0] = (start[0] + end[0] + 1) / 2 - 1;
        }
    }

    //cout << start[0] << "," << start[1] << " | " << end[0] << "," << end[1];

    paper[start[0]][start[1]] = h;

    func(start[0], start[1], 2 * k - 1, 2, 2);
    /*
    for (int i = 0; i < tpk; ++i)
    {
        for (int j = 0; j < tpk; ++j)
        {
            cout << paper[j][i] << " ";
        }
        cout << endl;
    }
    */
}