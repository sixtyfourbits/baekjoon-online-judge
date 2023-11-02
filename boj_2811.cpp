#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    int mx = 0;
    int sum = 0;

    int ipt;
    cin >> ipt;

    if (ipt < 0)
    {
        v[0] = 1;
        mx = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        cin >> ipt;

        if (ipt < 0)
        {
            v[i] = v[i - 1] + 1;
            v[i - 1] = 0;

            mx = max(mx, v[i]);
        }

    }

    bool check = false;
    for (int i = n - 1; i >= 0; --i)
    {
        //cout << v[i] << " ";
        if (v[i] > 0)
        {
            //cout << 'a';
            if (v[i] == mx && !check)
            {
                check = true;
                if (i + 1 - 4 * v[i] > 0)
                {
                    sum += 3 * v[i];
                }
                else
                {
                    sum += i + 1 - v[i];
                }
            }
            else
            {
                if (i + 1 - 3 * v[i] > 0)
                {
                    //cout << 'a';
                    sum += 2 * v[i];
                }
                else
                {
                    //cout << 'a';
                    sum += i + 1 - v[i];
                }
            }
        }
    }

    //cout << endl;

    cout << sum;
}