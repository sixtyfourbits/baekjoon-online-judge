#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
vector<bool> ch(4294967296);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        ch[tmp + 2147483648] = true;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int tmp;
        cin >> tmp;

        if (ch[tmp + 2147483648])
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

}
*/
/*
int main ()
{
    int n;
    cin >> n;
    vector<int> nv(n);
    for (int i = 0 ; i < n; ++i) cin >> nv[i];

    int m;
    cin >> m;
    vector<int> mv(m);
    for (int i = 0 ; i < m; ++i) cin >> mv[i];

    sort(nv.begin(), nv.end());
    sort(mv.begin(), mv.end());

    int ni = 0;
    int mi = 0;
    
    while (ni <= nv.size() || mi <= mv.size())
    {
        if (nv[ni] == mv[mi])
        {
            cout << 1 << endl;
            ++ni; ++mi;
        }
        else if (nv[ni] < mv[mi])
            ++ni;

        else
            break;
    }

    for (int i = mi; i < mv.size(); ++i)
        cout << 0 << endl;
}
*/

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int nv[100001];
    for (int i = 0 ; i < n; ++i) cin >> nv[i];

    int m;
    cin >> m;
    int mv[100001];
    for (int i = 0 ; i < m; ++i) cin >> mv[i];

    sort(nv, nv + n);
    
    for (int i = 0; i < m; ++i)
    {
        int l = 0;
        int r = n - 1;
        int mid = n / 2;

        while (true)
        {
            if (l > r) 
            {
                cout << 0 << '\n';
                break;
            }

            if (mv[i] == nv[l] || mv[i] == nv[mid] || mv[i] == nv[r])
            {
                cout << 1 << '\n';
                break;  
            }
            else if (mv[i] > nv[mid])
            {
                l = mid + 1;
                mid = (l + r) / 2;
            }
            else
            {
                r = mid - 1;
                mid = (l + r) / 2;
            }
        }
    }
}