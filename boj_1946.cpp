#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef struct r
{
    int r1;
    int r2;
}Rank;

int compare(Rank p1, Rank p2)
{
    return p1.r1 < p2.r1;
}

int main ()
{
    int t; cin >> t;
    for (int c = 0; c < t; ++c)
    {
        int n; 
        cin >> n;

        vector<Rank> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i].r1 >> v[i].r2;
        sort(v.begin(), v.end(), compare);

        int cnt = 0;
        int min = n+1;
        for (int i = 0; i < n; ++i)
        {
            if (min > v[i].r2)
                min = v[i].r2;

            if (v[i].r2 > min)
                ++cnt;
        }

        cout << n - cnt << endl;
    }
}