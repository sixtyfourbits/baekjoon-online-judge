#include <iostream>
#include <vector>

using namespace std;

int n, k, w;
vector<int> D;
vector<bool> check;
vector<pair<int, int> > v;
bool arrived;

int dfs(int x)
{
    //cout << x << endl;
    int mx = 0;
    bool tmp;
    
    for (int i = 0; i < k; ++i)
    {
        int sum = 0;
        if (v[i].first == x)
        {
            tmp = true;
            mx = max(mx, dfs(v[i].second) + D[i]);
        }
    } 

    if (!tmp)
        return D[x - 1];

    return mx;
}

int main()
{
    cin >> n >> k;

    D = vector<int>(n);
    check = vector<bool>(n);
    v = vector<pair<int, int> >(k);

    for (int i = 0; i < n; ++i) cin >> D[i];
    for (int i = 0; i < k; ++i) cin >> v[i].second >> v[i].first;

    cin >> w;

    cout << dfs(w);
}