#include <iostream>
#include <vector>
#include <algorithm>

using pii = std::pair<int, int>;
int                             n;
int                             m;
int                             g_max = -1;
std::vector<std::vector<int> >  v;
std::vector<pii>                displacement = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
std::vector<std::vector<bool> > visited;

void    input()
{
    std::cin >> n >> m;
    
    v = std::vector<std::vector<int> >(n, std::vector<int>(m, 0));
    visited = std::vector<std::vector<bool> >(n, std::vector<bool>(m, false));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            std::cin >> v[i][j];
}

void    output()
{
    std::cout << g_max;
}


void    solve(int x, int y, int count, int cm)
{
    if(count >= 4)
    {
        if(g_max < cm)
            g_max = cm;
        return;
    }
    
    
    for (int i = 0; i <= 4; i++)
    {
        int nx = x + displacement[i].first;
        int ny = y + displacement[i].second;
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (visited[nx][ny] == false)
            {
                visited[x][y] = true;
                solve(nx, ny, count + 1, cm + v[nx][ny]);
                visited[nx][ny] = false;
            }
        }
    }
}

void    special_case(int x, int y)
{
    int sum;
    
    // ㅜ
    if (x + 2 < n && y + 1 < m)
    {
        sum  = v[x][y] + v[x + 1][y] + v[x + 2][y] + v[x + 1][y + 1];
        g_max = std::max(sum, g_max);
    }
    // ㅗ
    if (x + 2 < n && y - 1 >= 0)
    {
        sum  = v[x][y] + v[x + 1][y] + v[x + 2][y] + v[x + 1][y - 1];
        g_max = std::max(sum, g_max);
    }
    // ㅓ
    if (y - 2 >= 0 && x - 1 >= 0)
    {
        sum  = v[x][y] + v[x][y - 1] + v[x][y - 2] + v[x - 1][y - 1];
        g_max = std::max(sum, g_max);
    }
    // ㅏ
    if (y - 2 >= 0 && x + 1 < n)
    {
        sum  = v[x][y] + v[x][y - 1] + v[x][y - 2] + v[x + 1][y - 1];
        g_max = std::max(sum, g_max);
    }
}

void    get_max()
{
    int     max_value = -1;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] > max_value)
                max_value = v[i][j];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == max_value)
            {
                visited[i][j] = true;
                solve(i, j, 1, v[i][j]);
                special_case(i, j);
                visited[i][j] = false;
            }
        }
    }
}

int     main()
{
    input();
    get_max();
    output();
}