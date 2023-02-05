#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mx = 0;
int k;
vector<bool> check;
vector<int> v;


void func(int sum, int i)
{
    if (sum > 0 && sum <= mx)
    {
        check[sum] = true;
        //cout << sum << endl;
    }
    if (i > k - 1) 
    {
        return;
    }

    func(sum + v[i], i+1);
    func(abs(sum - v[i]), i+1);
    func(sum, i+1);
    return;
}

int main()
{
    cin >> k;

    v = vector<int>(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> v[i];
        mx += v[i];
    }

    check = vector<bool>(mx, false);

    func(0, 0);

    int cnt = -1;
    for (int i = 0; i < mx; ++i)
        if (!check[i])
            ++cnt;
    
    cout << cnt;
}