/*
#include <iostream>

using namespace std;

int main()
{
    int c;
    cin >> c;

    for (int t = 0; t < c; ++t)
    {
        int n, m;
        cin >> n >> m;
        if (m - n <= 2)
        {
            cout << m - n << endl;
            continue;
        }

        int dis = 2;
        long long cnt = 3;
        long long a = 0;
        for (long long i = 3; i <= m - n; i+=dis)
        {
            ++a;
            if (cnt % 2 == 0)
                ++dis;

            ++cnt;
        }

        cout << cnt - 1 << endl;
        //cout << a;
    }
}
*/

#include <iostream>

using namespace std;

int main()
{
    int t; cin >> t;
    for (int c = 0; c < t; ++c)
    {
        long long n, m;
        cin >> n >> m;

        long long length = m - n;

        for (long long i = 1; ; ++i)
        {
            if (length <= i * i)
            {
                cout << 2 * (i - 1) + 1 << endl;
                break;
            }

            if (length <= i * (i + 1))
            {
                cout << i * 2 << endl;
                break;
            }
        }
    }
}