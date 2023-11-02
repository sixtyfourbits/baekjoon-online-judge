#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long res;

    bool trigger = false;
    int index = 0;
    long long sum = 0;

    //짝
    for (int i = 0; i < n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            if (trigger) sum += i - index;
            ++index;
        }
        else trigger = true;
    }
    res = sum;
    
    trigger = false; index = 0; sum = 0;
    //홀
    for (int i = 0; i < n; ++i)
    {
        if (a[i] % 2 != 0)
        {
            if (trigger) sum += i - index;
            ++index;
        }
        else trigger = true;
    }
    res = min(res, sum);
    
    trigger = false; index = n - 1; sum = 0;
    //짝
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] % 2 == 0)
        {
            if (trigger) sum += index - i;
            --index;
        }
        else trigger = true;
    }
    res = min(res, sum);
    
    trigger = false; index = n - 1; sum = 0;
    //홀
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] % 2 != 0)
        {
            if (trigger) sum += index - i;
            --index;
        }
        else trigger = true;
    }
    res = min(res, sum);
    
    cout << res;
}