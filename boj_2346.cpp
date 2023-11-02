#include <iostream>
#include <vector>

using namespace std;

/*
int main()
{
    int n; cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int i = 0;
    int bi;
    while (v.size() > 0)
    {
        i %= v.size();
        bi = i;

        if (v[i] > 0)
        {
            i += v[i] - 1;    
        }
        else
        {
            i += v[i];
        }
        v.erase(v.begin() + bi);
        cout << bi << ' ';
    }
}
*/

int main()
{

    int n;
    cin >> n;


    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int i = 0;
    int cnt = 1;

    cout << 1 << ' ';

    while (cnt < n)
    {
        int a = v[i];
        v[i] = 0;
        ++cnt;

        int index = i;
        if (a > 0)
        {
            for (int j = 0; j < a; ++j)
            {
                ++index;
                index %= n;

                if (v[index] == 0)
                {
                    --j;
                }
            }
            //cout << "+ INDEX: " << index << endl;
        }
        else
        {
            for (int j = 0; j < -a; ++j)
            {
                --index;
                index = (index+n)%n; //***

                if (v[index] == 0)
                {
                    --j;
                }
                //cout << "- INDEX: " << index << endl;
            }
        }

        cout << index + 1 << ' ';
        i = index;
    }
}