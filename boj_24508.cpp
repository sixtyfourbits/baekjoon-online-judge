#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    long long n, k, t;
    cin >> n >> k >> t;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    int s = 0;
    int e = v.size() - 1;
    int needs = 0;
    while (true)
    {
        //cout << t << " " << n << endl;
        if (t < 0)
        {
            cout << "NO";
            return 0;
        }
        if (s >= e)
        {
            if (s > e)
                cout << "YES";
            else
            {
                if (v[s] == 0)
                    cout << "YES";
                else
                    cout << "NO";
            }
            
            return 0;
        }
        if (n == 0)
        {
            cout << "YES";
            return 0;
        }

        needs = k - v[e];

        if (v[s] >= needs)
        {
            t -= needs;
            v[s] -= needs;
            v[e] += needs;
        }
        else
        {
            t -= v[s];
            v[e] += v[s];
            v[s] = 0;
        }


        if (v[s] == 0)
        {
            ++s;
            --n;
        }
        if (v[e] == k)
        {
            --e;
            --n;
        }
    }  
}