#include <iostream>
#include <vector>

std::vector<int>            g_numbers;
std::vector<int>            g_temp;

void    input_action()
{
    int                     n;

    std::cin >> n;
    g_numbers = std::vector<int>(n, 0);
    g_temp = std::vector<int>(n, 0);
    for (auto& i:g_numbers)
            std::cin >> i;
}

void    output_action()
{
    for (auto& i:g_numbers)
        std::cout << i << '\n';
}

void    merge(int left, int mid, int right)
{
    int                     i, j, k;

    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right)
    {
        if (g_numbers[i] < g_numbers[j])
            g_temp[k++] = g_numbers[i++];
        else
            g_temp[k++] = g_numbers[j++];
    }
    while (i <= mid)
        g_temp[k++] = g_numbers[i++];
    while (j <= right)
        g_temp[k++] = g_numbers[j++];
    while (--k >= left)
        g_numbers[k] = g_temp[k];
}

void    solution(int left, int right)
{
    int                     mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        solution(left, mid);
        solution(mid + 1, right);
        merge(left, mid, right);
    }
}   

int     main()
{
    input_action();
    solution(0, g_numbers.size() - 1);
    output_action();
    return (0);
}