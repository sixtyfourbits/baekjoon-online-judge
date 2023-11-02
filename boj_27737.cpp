#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 int n, m, k;
 vector<vector<int> > v;
 vector<int> cnt(0);

void dfs(int x, int y)
{
    v[x][y] = 2;
    if (x + 1 < n && v[x + 1][y] == 0)
    {
        ++cnt[cnt.size() - 1];
        dfs(x + 1, y);
    }
    if (x - 1 >= 0 && v[x - 1][y] == 0)
    {
        ++cnt[cnt.size() - 1];
        dfs(x - 1, y);
    }
    if (y + 1 < n && v[x][y + 1] == 0)
    {
        ++cnt[cnt.size() - 1];
        dfs(x, y + 1);
    }
    if (y - 1 >= 0 && v[x][y - 1] == 0)
    {
        ++cnt[cnt.size() - 1];
        dfs(x, y - 1);
    }
}

int ceil(int a, int b)
{
    if (a % b == 0)
        return a / b;
    else
        return (a / b) + 1;
}

int main()
{
    cin >> n >> m >> k;

    v = vector<vector<int> >(n, vector<int>(n));
    for (int j = 0; j < n; ++j)
        for (int i = 0; i < n; ++i)
            cin >> v[i][j];

    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (v[i][j] == 0)
            {
                cnt.push_back(1);
                dfs(i, j);
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < cnt.size(); ++i)
    {
        sum += ceil(cnt[i], k);
    }


    if (sum > m || sum == 0)
        cout << "IMPOSSIBLE";
    else
        cout << "POSSIBLE" << endl << m - sum;
}