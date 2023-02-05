#include <iostream>
#include <vector>

int                 n;
std::vector<int>    v;

void    input()
{
    std::cin >> n;
    v = std::vector<int>(n, 0);
    for(auto&i:v)
    {
        std::cin >> i;
    }
}

void    output(int n)
{
    std::cout << n;
}

void    heaply(int i)
{
    if (i*2+1 > v.size())
        return;


    if (v[i*2+1] > v[i*2+2])
    { 
        if (v[i] < v[i*2+1])
        {
            int             tmp;

            tmp = v[i];
            v[i] = v[i*2+1];
            v[i*2+1] = tmp;
        }
    }
    
    else
    {
        if (v[i] < v[i*2+2])
        {
            int             tmp;

            tmp = v[i];
            v[i] = v[i*2+2];
            v[i*2+2] = tmp;
        }
    }

    return heaply(v[i*2+1]);
    return heaply(v[i*2+2]);
}

void    heap_sort()
{
    if(v.size() <= 0)
        return;

    heaply(0);
    
    output(v[0]);
    v.erase(v.begin());

    return heap_sort();
}

int     main()
{
    input();
    heap_sort();
}