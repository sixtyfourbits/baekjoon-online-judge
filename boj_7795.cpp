/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int t;
    cin >> t;
    for (int c = 0; c < t; ++c)
    {
        int cnt = 0;

        int n, m;
        cin >> n >> m;
        
        vector<int> v1(n);
        vector<int> v2(m);

        for (int i = 0; i < n; ++i) cin >> v1[i];
        for (int i = 0; i < m; ++i) cin >> v2[i];

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());


        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (v1[i] <= v2[j])
                    break;
                ++cnt;
            }
        }

        cout << cnt << endl;

    }
}
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
    int t;
    cin >> t;
    for (int c = 0; c < t; ++c)
    {
        int cnt = 0;

        int n, m;
        cin >> n >> m;
        
        vector<int> v1(n);
        vector<int> v2(m);

        for (int i = 0; i < n; ++i) cin >> v1[i];
        for (int i = 0; i < m; ++i) cin >> v2[i];

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        for (int i = 0; i < n; ++i)
        {
            int l, mid, r;
            l = 0; mid = (m-1) / 2; r = m-1;
            while (l < r)
            {
                if (v2[mid] > v1[i])
                {
                    l = mid + 1;
                }
                else if (v2[mid] <= v1[i])
                {
                    r = mid - 1;
                }
                mid = (l+r) / 2;
                //cout << r << ' ' << l << "  ";
            }

            cnt += r;
        }
        cout << endl;
        cout << cnt;
    }
}