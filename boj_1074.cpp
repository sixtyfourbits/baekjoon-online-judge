#include <iostream>
#include <vector>

using namespace std; 

int n, r, c;
vector<vector<int> > v;

void func(int x, int y, int size, int cnt)
{
    if (x == r && y == c)
    {
        cout << cnt;
        return;
    }

    if (r >= x + size / 2)
    {
        if (c >= y + size / 2) // 3/4
        {
            x += size / 2;
            y += size / 2;
            cnt += size * size / 4 * 3;
        }
        else // 1/4
        {
            x += size / 2;
            cnt += size * size / 4;
        }
    }
    else
    {
        if (c >= y + size / 2) // 2/4
        {
            y += size / 2;
            cnt += size * size / 4 * 2;
        }
    }
    func (x, y, size / 2, cnt);
}

int main()
{
    cin >> n >> c >> r;

    func(0, 0, 1<<n, 0);
}