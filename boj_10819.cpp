#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int mx = -1000000;
vector<int> v;
vector<int> check(201);
vector<int> s;

void func(int x, int sum)
{
    if (x == n - 1)
    {
        mx = max(mx, sum);
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        check[v[i] + 100] = true;
        s[x] = v[i];
        if (x == 0)
            func(x + 1, sum);
        else
        {
            func(x + 1, sum + abs(v[i] - s[x - 1]));
        }
        check[v[i] + 100] = false;
    }
}

int main()
{
    cin >> n;

    v = vector<int>(n);
    s = vector<int>(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    func(0, 0);

    cout << mx;
}