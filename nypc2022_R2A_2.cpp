#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> x(n), a(n), b(n);
    vector<bool> used(1000000001, false);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = 0; i < n; ++i)
    {
        int mx1 = -1, mx2 = -1, mx3 = -1;
        int j1, j2, j3;
        for (int j = 0; j < n; ++j)
        {
            if (b[j] > mx1)
            {
                mx1 = b[j];
                j1 = j;
                break;
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (b[j] > mx2 && mx1 > mx2)
            {
                mx2 = b[j];
                j2 = j;
                break;
            }
        }

        if ()
    }
}