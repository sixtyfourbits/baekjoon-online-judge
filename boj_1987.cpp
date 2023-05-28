#include <iostream>
#include <algorithm>

using namespace std;

int r, c;
char arr[21][21];
bool check[27] = {false};
int ans = 0;

void bt(int x, int y, int cnt)
{
    //cout << arr[x][y] << " ( " << x << " , " << y << " )" << endl;
    ++cnt;
    ans = max(ans, cnt);

    if (x + 1 < c && !check[arr[x + 1][y] - 65])
    {
        check[arr[x + 1][y] - 65] = true;
        bt(x + 1, y, cnt);
        check[arr[x + 1][y] - 65] = false;
    }


    if (x - 1 >= 0 && !check[arr[x - 1][y] - 65])
    {
        check[arr[x - 1][y] - 65] = true;
        bt(x - 1, y, cnt);
        check[arr[x - 1][y] - 65] = false;
    }
    
    if (y + 1 < r && !check[arr[x][y + 1] - 65])
    {
        check[arr[x][y + 1] - 65] = true;
        bt(x, y + 1, cnt);
        check[arr[x][y + 1] - 65] = false;
    }

    if (y - 1 >= 0 && !check[arr[x][y - 1] - 65])
    {
        check[arr[x][y - 1] - 65] = true;
        bt(x, y - 1, cnt);
        check[arr[x][y - 1] - 65] = false;
    }
}

int main()
{
    cin >> r >> c;
    for (int j = 0; j < r; ++j)
        for (int i = 0; i < c; ++i)
            cin >> arr[i][j];

    check[arr[0][0] - 65] = true;
    bt(0, 0, 0);

    cout << ans;
}