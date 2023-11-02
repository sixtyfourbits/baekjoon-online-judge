/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    
    return a.first > b.first;
}

int main()
{
    int n;
    cin >> n;

    for (int t = 0; t < n; ++t)
    {
        vector<pair<int, int> > v(4);
        for (int i = 0; i < 4; ++i)
        {
            int a, b;
            cin >> a >> b;

            v[i].first = a + 100001;
            v[i].second = b + 100001;
        }

        sort(v.begin(), v.end());

        if (v[0].first == v[1].first)
        {
            int dif = abs(v[0].second - v[1].second);

            if (v[2].first == v[3].first && v[0].first + dif == v[2].first)
            {
                if (abs(v[2].second - v[3].second) == dif)
                {
                    cout << 1 << endl;
                    continue;
                }
            }
        }
        else if (v[0].second == v[3].second && v[1].first == v[2].first)
        {
            int dif = abs(v[0].first - v[3].first);

            if (abs(v[1].second - v[2].second) == dif)
            {
                if (dif % 2 == 0)
                {
                    if (v[0].first + dif / 2 == v[1].first && v[1].second + dif / 2 == v[0].second)
                    {
                        cout << 1;
                        continue;
                    }
                }
            }
        }
        cout << 0 << endl;
        
    }
}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    
    return a.first > b.first;
}

int main()
{
    int n;
    cin >> n;

    for (int t = 0; t < n; ++t)
    {
        vector<pair<int, int> > v(4);
        for (int i = 0; i < 4; ++i)
        {
            int a, b;
            cin >> a >> b;

            v[i].first = a + 100001;
            v[i].second = b + 100001;
        }

        sort(v.begin(), v.end());

        int w = v[3].first - v[0].first;
        int h = abs(v[3].second - v[0].second);

        if (abs(v[1].second - v[2].second) == w && v[2].first - v[1].first == h)
        {
            int w2 = v[1].first - v[0].first;
            int h2 = abs(v[1].second - v[0].second);

            if (v[2].first - v[0].first == h2 && abs(v[2].second - v[0].second) == w2)
            {
                if (v[3].first - v[1].first == h2 && abs(v[3].second - v[1].second) == w2)
                {
                    if (v[3].first - v[2].first == w2 && abs(v[3].second - v[2].second) == h2)
                    {
                        cout << 1 << endl;
                        continue;
                    }
                }
            }
        }

        cout << 0 << endl;
    }
}