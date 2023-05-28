/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> sw(n + 1);
    for (int i = 1; i <= n; ++i) cin >> sw[i];

    int m; cin >> m;

    vector<vector<int> > v(m, vector<int>(2));
    for (int i = 0; i < m; ++i) cin >> v[i][0] >> v[i][1];

    for (int i = 0; i < m; ++i)
    {
        if (v[i][0] == 1)
        {
            for (int j = v[i][1]; j <= n; j += v[i][1])
            {
                sw[j] = !sw[j];
            }
        }
        else
        {
            for (int j = 1; j <= min(j, n - j); ++j)
            {
                sw[v[i][1]] = !sw[v[i][1]];

                if (sw[v[i][1] + j] != sw[v[i][1] - j])
                    break;
                else
                {
                    sw[v[i][1] + j] = !sw[v[i][1] + j];
                    sw[v[i][1] - j] = !sw[v[i][1] - j];
                }
            }
        }

        for (int i = 0; i < n; ++i)
            cout << sw[i] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; ++i)
        cout << sw[i] << " ";

}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> sw(n + 1);
    for (int i = 1; i <= n; ++i) cin >> sw[i];

    int m; cin >> m;
    vector<vector<int> > v(m, vector<int>(2));
    for (int i = 0; i < m; ++i) cin >> v[i][0] >> v[i][1];

    for (int i = 0; i < m; ++i)
    {
        if (v[i][0] == 1)
        {
            for (int j = v[i][1]; j <= n; j += v[i][1])
                sw[j] = !sw[j];
        }
        else
        {
            sw[v[i][1]] = !sw[v[i][1]];
            for (int j = 1; j <= min(v[i][1] - 1, n - v[i][1]); ++j)
            {
                if (sw[v[i][1] + j] == sw[v[i][1] - j])
                {
                    sw[v[i][1] + j] = !sw[v[i][1] + j];
                    sw[v[i][1] - j] = !sw[v[i][1] - j];
                }
                else
                    break;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {   
        cout << sw[i] << " ";
        
        if (i % 20 == 0)
            cout << endl;
    }
}