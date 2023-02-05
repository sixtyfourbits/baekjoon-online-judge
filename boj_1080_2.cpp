#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > A;
vector<vector<int> > B;

void flip (int x, int y)
{
    for (int i = x; i <= x + 2; ++i)
    {
        for (int j = y; j <= y + 2; ++j)
            A[i][j] = !A[i][j];
    }
}
int main ()
{
    int cnt = 0;
    cin >> n >> m;

    A = vector<vector<int> >(m, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%1d", &A[j][i]);
        
    B = vector<vector<int> >(m, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%1d", &B[j][i]);

    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = 0; j < m - 2; ++j)
        {
            if (A[j][i] != B[j][i])
            {
                flip(j, i);
                ++cnt;
            }
        }
    }
    
    if (A != B)
        cnt = -1;

    cout << cnt;
}