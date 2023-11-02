#include <iostream>
#include <vector>

using namespace std;

void ph(int, vector<int>, int);
void pl(int, vector<int>, int);
void st(int, vector<int>, int);


int n, k;
int mx = 0;
vector<int> ans;
vector<int> omr;

void ph(int p, vector<int> v, int kc)
{
    if (p >= n || kc >= k) return;

    for (int i = n - 1; i >= p + 1; --i)
        v[i] = v[i - 1];
    v[p] = 0;

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] == ans[i])
            ++cnt;
    }

    mx = max(cnt, mx);
    ++kc;

    ph(p + 1, v, kc);
    pl(p + 1, v, kc);
    st(p + 1, v, kc);
}

void pl(int p, vector<int> v, int kc)
{
    if (p >= n || kc >= k) return;

    for (int i = p; i < n - 1; ++i)
        v[i] = v[i + 1];
    v[n - 1] = 0;

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] == ans[i])
            ++cnt;
    }

    mx = max(cnt, mx);
    ++kc;

    ph(p + 1, v, kc);
    pl(p + 1, v, kc);
    st(p + 1, v, kc);
}

void st(int p, vector<int> v, int kc)
{
    if (p >= n || kc >= k) return;

    ph(p + 1, v, kc);
    pl(p + 1, v, kc);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> ans[i];
    for (int i = 0; i < n; ++i) cin >> omr[i];

    ph(0, omr, 0);
    pl(0, omr, 0);
    st(0, omr, 0);
    

    cout << mx;
}