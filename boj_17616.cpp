#include <iostream>
#include <vector>

using namespace std;

int n, m, x;
vector<vector<int> > high, low;
vector<bool> check_h, check_l;

int cnt_h = 0, cnt_l = 0;

void dfs_h(int k)
{
    ++cnt_h;
    check_h[k] = true;

    for (int i = 0; i < high[k].size(); ++i)
    {
        if (!check_h[high[k][i]])
            dfs_h(high[k][i]);
    }
}

void dfs_l(int k)
{
    ++cnt_l;
    check_l[k] = true;

    for (int i = 0; i < low[k].size(); ++i)
    {
        if (!check_l[low[k][i]])
            dfs_l(low[k][i]);
    }
}

int main()
{
    cin >> n >> m >> x;
    high = vector<vector<int> >(n + 1);
    low = vector<vector<int> >(n + 1);
    check_h = vector<bool>(n + 1);
    check_l = vector<bool>(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        low[a].push_back(b);
        high[b].push_back(a);
    }

    dfs_h(x); dfs_l(x);

    cout << cnt_h << " " << n - cnt_l + 1;
}