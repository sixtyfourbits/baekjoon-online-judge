#include <vector>
#include <iostream>

using namespace std;

int n;
vector<vector<int> > v;
int ans[3] = {0};

void func (int x, int y, int size)
{
    int a = v[x][y];
    for (int i = x; i < x + size; ++i)
    {
        for (int j = y; j < y + size; ++j)
        {
            if (v[i][j] != a)
            {
                if (size > 1)
                {
                    func(x, y, size / 3);
                    func(x + (size / 3), y, size / 3);
                    func(x + (size / 3 * 2), y, size / 3);
                    func(x, y + (size / 3), size / 3);
                    func(x + (size / 3), y + (size / 3), size / 3);
                    func(x + (size / 3 * 2), y + (size / 3), size / 3);
                    func(x, y + (size / 3 * 2), size / 3);
                    func(x + (size / 3), y + (size / 3 * 2), size / 3);
                    func(x + (size / 3 * 2), y + (size / 3 * 2), size / 3);
                }
                
                return;
            }
        }
    }

    ++ans[a+1];
}

int main ()
{
    cin >> n;

    v = vector<vector<int> >(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];

    func(0, 0, n);

    cout << ans[0] << endl << ans[1] << endl << ans[2];
}