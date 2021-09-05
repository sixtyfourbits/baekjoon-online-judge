#include <iostream>
#include <string>
#include <algorithm>

long long n;

void     input()
{
    std::cin >> n;
}

void     output(std::string ans)
{
    reverse(ans.begin(), ans.end());
    std::cout << ans;
}

void     solve()
{
    std::string s;

    while (n > 0)
    {
        if (n % 2 == 0)
            s.push_back('0');
        else
            s.push_back('1');

        n /= 2;
    }

    output(s);
}

int     main()
{
    input();
    solve();
}
