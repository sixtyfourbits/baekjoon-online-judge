#include <iostream>
#include <vector>

using namespace std;

int maxi = -1000000001, mini = 1000000001;
int n;
vector<int> v;
vector<int> mod(4);

void func (int p, int m, int t, int d, int cn, int i)
{
    if (i >= n)
    {
        if (cn > maxi)
            maxi = cn;
        if (cn < mini)
            mini = cn;
        return;
    }


    if (p > 0) 
        func(p - 1, m, t, d, cn + v[i], i+1);
    if (m > 0) 
        func(p, m - 1, t, d, cn - v[i], i+1);
    if (t > 0) 
        func(p, m, t - 1, d, cn * v[i], i+1);
    if (d > 0) 
        func(p, m, t, d - 1, cn / v[i], i+1);
}

int main ()
{
    
    cin >> n;

    v.resize(n);
    for(int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 0; i < 4; ++i) cin >> mod[i];


    func(mod[0], mod[1], mod[2], mod[3], v[0], 1);

    cout << maxi << endl << mini;
}