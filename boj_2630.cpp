#include <iostream>
#include <vector>

int n;
int w; int b;
std::vector<std::vector<int> > plate;

void    input()
{
    std::cin >> n;

    plate = std::vector<std::vector<int> >(n, std::vector<int>(n, 0));
    w = 0;
    b = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            std::cin >> plate[i][j];
    }
}

void    output()
{
    std::cout << w << '\n' << b;
}

void    solution(int x, int y, int size)
{
    for (int i = x; i < x + size; ++i)
    {
        for (int j = y; j < y + size; ++j)
        {
            if (plate[i][j] != plate[x][y])
            {
                solution(x, y, size / 2);
                solution(x, y + size / 2, size / 2);
                solution(x + size / 2, y, size / 2);
                solution(x + size / 2, y + size / 2, size / 2);
                return;
            }
        }
    }

    if (plate[x][y])
        b++;
    else
        w++;
}

int        main()
{
    input();
    solution(0, 0, n);
    output();
}
