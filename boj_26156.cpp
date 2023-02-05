#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    long long ans=0;
    string s;
    cin >> n >> s;

    vector<long long> rc(n), oc(n), cc(n), kc(n);
    vector<int> yee(1000001);

    yee[0] = 1;
    for (int i = 1; i <= 1000000; ++i)
    {
        yee[i] = (yee[i - 1] * 2) % 1000000007;
    }

    if (s[n - 1] == 'K')
        kc[n - 1] = 1;

    for (int i = n - 2; i >= 0; --i) 
    {
        if (s[i] == 'K')
        {
            kc[i] = kc[i + 1] + 1;
        }
        else
        {
            kc[i] = kc[i + 1];
        }

        
    }

    for (int i = n - 2; i >= 0; --i)
    {
        if (s[i] == 'C')
        {
            cc[i] = (kc[i + 1] % 1000000007 + cc[i + 1] % 1000000007) % 1000000007;
        }
        else
        {
            cc[i] = cc[i + 1] % 1000000007;
        }
    }

    for (int i = n - 3; i >= 0; --i)
    {
        if (s[i] == 'O')
        {
            oc[i] = (cc[i + 1] % 1000000007 + oc[i + 1] % 1000000007) % 1000000007;
        }
        else
        {
            oc[i] = oc[i + 1] % 1000000007;
        }
    }

    for (int i = n - 4; i >= 0; --i)
    {
        if (s[i] == 'R')
        {
            ans = ((ans % 1000000007) + ((yee[i] * oc[i]) % 1000000007)) % 1000000007;
        }
    }
    /*
    for (int i = 0; i < n; ++i)
        cout << kc[i] << " ";
    cout << endl;
    for (int i = 0; i < n; ++i)
        cout << cc[i] << " ";
    cout << endl;
    for (int i = 0; i < n; ++i)
        cout << oc[i] << " ";
    cout << endl;
    */
    cout << ans;
}