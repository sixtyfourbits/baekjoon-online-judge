#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int> > v(4, vector<int>(8));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 8; ++j)
            scanf("%1d", &v[i][j]);
    
    int n;
    cin >> n;  

    int r;

    vector<int> tw(4);
    for (int i = 0; i < n; ++i)
    {
        int s, rot;
        cin >> s >> rot;

        if (rot != 1)
        {
            rot = 1;
            if (tw[s - 1] == 7)
                tw[s - 1] = 0;
            else
                ++tw[s - 1];
        }
        else
        {
            rot = -1;
            if (tw[s - 1] == 0)
                tw[s - 1] = 7;
            else
                --tw[s - 1];
        } 

        r = rot;
        for (int j = s - 2; j >= 0; --j)
        {
            if (tw[s - 1] - 2 < 0)
            {
                if (tw[j] + 3 > 7)
                {
                    if (v[s - 1][tw[s - 1] + 5] == v[j][tw[j] - 6])
                        break;
                }
                else
                {
                    if (v[s - 1][tw[s - 1] + 5] == v[j][tw[j] + 2])
                        break;
                }
                
            }
            else
            {
                if (tw[j] + 3 > 7)
                {
                    if (v[s - 1][tw[s - 1] - 2] == v[j][tw[j] - 6])
                        break;
                }
                else
                {
                    if (v[s - 1][tw[s - 1] - 2] == v[j][tw[j] + 2])
                        break;
                }
            }

            if (r != 1)
            {
                r = 1;
                if (tw[j] == 7)
                    tw[j] = 0;
                else
                    ++tw[j];
            }
            else
            {
                r = -1;
                if (tw[j] == 0)
                    tw[j] = 7;
                else
                    --tw[j];
            }
        }

        r = rot;
        for (int j = s; j < 4; ++j)
        {
            if (tw[j] - 2 < 0)
            {
                if (tw[s - 1] + 2 > 7)
                {
                    if (v[j][tw[j] + 6] == v[s - 1][tw[s - 1] - 6])
                        break;
                }
                else
                {
                    if (v[j][tw[j] + 6] == v[s - 1][tw[s - 1] + 2])
                        break;
                }
                
            }
            else
            {
                if (tw[s - 1] + 3 > 7)
                {
                    if (v[j][tw[j] - 2] == v[s - 1][tw[s - 1] - 6])
                        break;
                }
                else
                {
                    if (v[j][tw[j] - 2] == v[s - 1][tw[s - 1] + 2])
                        break;
                }
            }

            if (r != 1)
            {
                r = 1;
                if (tw[j] == 7)
                    tw[j] = 0;
                else
                    ++tw[j];
            }
            else
            {
                r = -1;
                if (tw[j] == 0)
                    tw[j] = 7;
                else
                    --tw[j];
            }
        }

        for (int j = 0; j < 4; ++j)
            cout << tw[j] << " ";
        cout << endl;
    }

    int sum  = 0;
    for (int i = 0; i < 4; ++i)
    {
        sum += v[i][tw[i]] * i<<2;
    }

    cout << sum;
}

// % 연산자로 index fix