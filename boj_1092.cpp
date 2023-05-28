/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &v1, vector<int> &v2)
{
    return v1[0] > v2[0];
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, m;

    cin >> n;
    vector<vector<int> > v(n, vector<int>(1));
    for (int i = 0; i < n; ++i)
        cin >> v[i][0];


    cin >> m;
    vector<int> box(m);
    for (int i = 0; i < m; ++i)
        cin >> box[i];

    sort(v.begin(), v.end(), compare);
    sort(box.begin(), box.end(), cmp);

    for (int i = 0; i < n; ++i)
        cout << v[i][0] << " ";
    cout << endl;

    int crane = 0;
    int j = 0;
    for (int i = 0; i < m; ++i)
    {
        if (box[i] > v[][0])
        {
            if (box[i] > v[j][0])
            {
                if (box[i] > v[0][0])
                {
                    cout << -1;
                    return 0;
                }
                else
                {
                    j = 0;
                    v[j].push_back(box[i]);
                    ++j;
                }
            }
            else
            {
                v[j].push_back(box[i]);
                ++j;
            }
        }
        else
        {
            v[crane].push_back(box[i]);
        }

        if (crane >= n - 1)
            crane = 0;
        else
            ++crane;
    }

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, (int)v[i].size() - 1);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }

    cout << ans;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &v1, vector<int> &v2)
{
    return v1[0] > v2[0];
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
     int n, m;

    cin >> n;
    vector<vector<int> > v(n, vector<int>(1));
    for (int i = 0; i < n; ++i)
        cin >> v[i][0];


    cin >> m;
    vector<int> box(m);
    for (int i = 0; i < m; ++i)
        cin >> box[i];

    sort(v.begin(), v.end(), compare);
    sort(box.begin(), box.end(), cmp);

    for (int i = 0; i < m; ++i)
    {
        int end = n - 1;
        for (int j = 0; j < n; ++j)
        {
            if (v[j][0] < box[i])
            {
                end = j - 1;
                break;
            }
        }
        if (end < 0)
        {
            cout << -1;
            return 0;
        }

        //cout << end << endl;

        int mi = m+1;
        int mii;
        for (int j = 0; j <= end; ++j)
        {
            if (v[j].size() < mi)
            {
                mi = v[j].size();
                mii = j;
            }
        }

        v[mii].push_back(box[i]);
    }
    
    int ans;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, (int)v[i].size() - 1);
    }
    /*
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    */

    cout << ans;
}