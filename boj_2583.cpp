#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int cnt = 0;

vector<vector<bool> > v;

void func(int x, int y)
{
    if (x > n - 1 || x < 0 || y > m - 1 || y < 0 || v[x][y])
        return;
    
    v[x][y] = true;
    ++cnt;

    func(x+1, y);
    func(x, y+1);
    func(x, y-1);
    func(x-1, y);
}

int main ()
{
    cin >> m >> n >> k;

    v = vector<vector<bool> >(n, vector<bool>(m, false));

    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        int ex, ey;
        cin >> ex >> ey;
        
        for (int j = x; j < ex; ++j)
        {
            for (int l = y; l < ey; ++l)
            {
                v[j][l] = true;
            }
        }
    }

    vector<int> ans;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!v[j][i])
            {
                //cout << i << " " << j << " " << v[i][j] << endl;
                func(j, i);
                ans.push_back(cnt);
                cnt = 0;
            }
        }
    }

    cout << ans.size() << endl;

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
}