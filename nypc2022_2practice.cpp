#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > v(m, vector<int>(n));
    vector<vector<int> > control(m, vector<int>(n, 0));
    vector<vector<int> > ans;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> v[j][i];

    while(v != control)
    {
        for (int i = 0; i < n; ++i)
        {
            int tmp = 0;
            bool check = false;
            for (int j = 0; j < m; ++j)
            {
                if (v[j][i] != 0)
                {
                    check = true;
                    if (tmp != 0 && tmp != v[j][i])
                    {
                        check = false;
                        break;
                    }

                    tmp = v[j][i];
                }
            }
            if (check)
            {
                for (int j = 0; j < m; ++j)
                {
                    v[j][i] = 0;
                }
                vector<int> t;
                t.push_back(1); t.push_back(i + 1); t.push_back(tmp);
                ans.push_back(t);
            }
        }

        for (int i = 0; i < m; ++i)
        {
            int tmp = 0;
            bool check = false;
            for (int j = 0; j < n; ++j)
            {
                if (v[i][j] != 0)
                {
                    check = true;
                    if (tmp != 0 && tmp != v[j][i])
                    {
                        check = false;
                        break;
                    }

                    tmp = v[i][j];
                }
            }
            if (check)
            {
                for (int j = 0; j < n; ++j)
                {
                    v[i][j] = 0;
                }
                vector<int> t;
                t.push_back(0); t.push_back(i + 1); t.push_back(tmp);
                ans.push_back(t);
            }
        }
    }

    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; --i)
    {
        if (ans[i][0])
            cout << "H " << ans[i][1] << " " << ans[i][2] << endl;
        else
            cout << "V " << ans[i][1] << " " << ans[i][2] << endl;
    }
}