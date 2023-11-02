#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<bool> > v(h, vector<bool>(w));
    for (int i = 0; i < w; ++i)
    {
        int a;
        cin >> a;

        for (int j = h - 1; j >= h - a; --j)
            v[j][i] = true; 
    }

    // for (int i = 0; i < h; ++i)
    // {
    //     for (int j = 0; j < w; ++j)
    //         cout << v[i][j];

    //     cout << endl;
    // }

    int sum = 0;
    for (int i = h - 1; i >= 0; --i)
    {
        bool st = false;
        int cnt = 0;
        for (int j = 0; j < w; ++j)
        {
            if (v[i][j])
            {
                st = !st;
                if (!st)
                {
                    sum += cnt;
                    cnt = 0;
                    st = !st;
                }
            }
            else
            {
                if (st)
                    ++cnt;
            }
        }
    }

    cout << sum;
}