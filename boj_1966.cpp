#include <vector>
#include <iostream>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main ()
{
    int t; 
    cin >> t;
    for (int c = 0; c < t; ++c)
    {

        int n, m;
        cin >> n >> m;
        
        vector<int> v(n);
        vector<int> index(n);
        vector<int> srt;
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
            index[i] = i;
        }
        srt = v;
        sort(srt.begin(), srt.end(), compare);

        for (int i = 0; i < n + 1; ++i)
        {
            if (i > n - 1)
                i = 0;

            if (v[i] == srt[0])
            {
                if (i == m)
                {
                    int cnt = 0;
                    for (int j = 0; j < n; ++j)
                        if (v[j] == 0)
                            ++cnt;
    
                    cout << cnt + 1 << endl;
                    break;
                }

                srt.erase(srt.begin(), srt.begin() + 1);
                v[i] = 0;
            }
        }
    }
}