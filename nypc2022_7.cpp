#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t; cin >> t;
    for (int c = 0; c < t; ++c)
    {

        int n, a, b;
        int ax, ay, bx, by;
        int x, y = 0;
        int cnt = 1;
        int heading = 0; // 0 = right, 1 = left, 2 = up, 3 = down

        cin >> n >> a >> b;
        vector<vector<long long> > v(n, vector<long long>(n, 0));
        vector<int> vsize(4, n - 1); // left, right, top, bottom
        vsize[0] = 0; vsize[2] = 0;

        if (n == 1)
        {
            cout << "YES";
            return 0;
        }
        
        while (true)
        {
            //cout << vsize[0] << ' ' << vsize[1] << ' ' << vsize[2] << ' ' << vsize[3] << endl;
            v[x][y] = cnt;
            cout << cnt << endl;

            if (v[x][y] == a)
            {
                ax = x; ay = y;
            }
            if (v[x][y] == b)
            {
                bx = x; by = y;
            }
            
            if (vsize[0] >= n || vsize[1] < 0 || vsize[2] >= n|| vsize[3] < 0)
                break;

            if (heading == 0)  // right
            {
                if (y + 1 > vsize[1])
                {
                    if (x + 1 > vsize[3])  
                        break;

                    heading = 3; //down
                    ++x;
                    ++cnt;
                    ++vsize[2];
                }
                else
                {
                    ++y;
                    ++cnt;
                }
            }
            else if (heading == 1) // left
            {
                if (y - 1 < vsize[0])
                {
                    if (x - 1 < vsize[2])
                        break;

                    heading = 2; //up
                    --x;
                    ++cnt;
                    --vsize[3];
                }
                else
                {
                    --y;
                    ++cnt;
                }
            }
            else if (heading == 2) // up
            {
                if (x - 1 < vsize[2])
                {
                    if (y + 1 > vsize[1])
                        break;

                    heading = 0; // right
                    ++y;
                    ++cnt;
                    ++vsize[0];
                }
                else
                {
                    --x;
                    ++cnt;
                }
            }
            else if (heading == 3) // down
            {
                if (x + 1 > vsize[3])
                {
                    if (y - 1 < vsize[0])
                        break;

                    heading = 1; // left
                    --y;
                    ++cnt;
                    --vsize[1];
                }
                else
                {
                    ++x;
                    ++cnt;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << v[i][j] << ' ';
            }
            cout << endl;
        }

        cout << ax << " " << ay << " " << bx << " " << by << endl;

        if (abs(bx - ax) == abs(by - bx))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}