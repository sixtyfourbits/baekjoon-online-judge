/*
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > v;

// cleaning
string func(int y, int x, string s)
{
    v[y][x] = 0;

    if (y + 1 < n && x - 1 >= 0 && v[y + 1][x - 1])
        return func(y + 1, x - 1, s + "L");
    else if (y + 1 < n && v[y + 1][x])
        return func(y + 1, x, s + "D");
    else if (y + 1 < n && x + 1 < m && v[y + 1][x + 1])
        return func(y + 1, x + 1, s + "R");
    else
        return s;
}

int main()
{
    cin >> n >> m;

    v = vector<vector<int> >(n, vector<int>(m));
    // string to int convert
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c;
            cin >> c;

            if (c == 'O')
                v[i][j] = 0;
            else
                v[i][j] = 1;
        }
    }

    int k = 0;
    vector<string> ans;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (v[i][j])
            {
                ++k;
                string tmp;
                for (int k = 0; k < i; ++k) tmp.push_back('D');
                ans.push_back(to_string(j + 1) + " " + func(i, j, tmp));
                for (int k = ans[ans.size() - 1].size() - 1; k <= n - 1; ++k) ans[ans.size() - 1].push_back('D');
            }
        }
    }

    cout << k << endl;
    for (int i = 0; i < k; ++i)
        cout << ans[i] << endl;
}
*/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > v;

int main()
{
    unsigned int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c; cin >> c;
            if (c == 'X')
            {
                vector<int> tmp;
                tmp.push_back(j); tmp.push_back(i);
                v.push_back(tmp);
            }
        }
    }

    vector<string> ans;
    int k = 0;

    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (v[i][0] == -1 || v[i][1] == -1)
            continue;

        //cout << v[i][0] << " " << v[i][1] << endl;

        int x = v[i][0]; 
        int y = v[i][1];

        ans.push_back(to_string(v[i][0] + 1) + " ");
        for (int j = 0; j < v[i][1]; ++j)
            ans[ans.size() - 1] += "D";

        for (int j = i + 1; j < v.size(); ++j)
        {
            if (v[j][0] == -1 || v[j][1] == -1)
                continue;

            if (abs(x - v[j][0]) <= abs(v[j][1] - y))
            {
                int a = abs(x - v[j][0]); 
                int b = v[j][1] - y;
                
                while (a > 0)
                {
                    if (v[i][0] > v[j][0])
                        ans[ans.size() - 1].push_back('L');
                    else
                        ans[ans.size() - 1].push_back('R');

                    --a; --b;
                }
                for (int k = 0; k < b; ++k)
                    ans[ans.size() - 1].push_back('D');

                //cout << s.size() << endl;
                x = v[j][0]; y = v[j][1];
                v[j][0] = -1; v[j][1] = -1;
            }
        }
        unsigned int aa = ans[ans.size() - 1].size() + 1;
        for (int i = aa; i < n; ++i)
            ans[ans.size() - 1] += "D";
            
        ++k;
    }

    cout << k << endl;
    for (int i = 0; i < k; ++i)
        cout << ans[i] << endl;
}