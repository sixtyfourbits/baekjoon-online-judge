#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n, m; 
    int cnt = 0;
    int ans = 0;
    string s;
    string compare;

    cin >> n >> m >> s;
    
    bool a = false;
    for (int i = 1; i < m; ++i)
    {
        if (a)
        {
            ++cnt;
        }
        else
        {
            ans += (cnt - (2 * n) - 1) / 2;
            cnt = 0;
        }
        if (s[i - 1] != s[i])
            a = true;
        else
            a = false;
    }

    cout << ans; 
}