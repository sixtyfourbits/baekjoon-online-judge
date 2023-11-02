#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = i + 1;

    vector<int> sq;
    for (int i = 2; i <= n * 2;)
    {
        sq.push_back(i);
        //cout << i << endl;
        i *= 2;
    }

    vector<int> ans;
    vector<bool> check(n);

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = sq.size() - 1; j >= 0; --j)
        {
            if (sq[j] - v[i] > 0 && sq[j] - v[i] <= n && !check[sq[j] - v[i] - 1])
            {
                ans.push_back(v[sq[j] - v[i] - 1]);
                check[sq[j] - v[i] - 1] = true;
                break;
            }
        }
    }

    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << endl;
}