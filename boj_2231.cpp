#include <iostream>

int     n;

void    input()
{
    std::cin >> n;
}

void    solve()
{
    for (int i = 1; i <= n; ++i)
    {
        int     tmp_i = i;
        int     res = 0;

        while (true)
        {
            if (tmp_i < 10)
            {
                res += tmp_i;
                break;
            }

            res += tmp_i % 10;
            tmp_i /= 10;
            //std::cout << "[" << i << "] " << tmp_i << "\n";
        }

        if (res + i == n)
        {
            std::cout << i;
            return;
        }
    }

    std::cout << 0;
    return;
}

int main()
{
    input();
    solve();
}
