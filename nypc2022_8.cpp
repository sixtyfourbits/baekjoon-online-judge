#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int i = -1;
    int cnt = 0;
    int mx = 0;
    cin >> n;

    vector<int> v(n);
    int arr[3] = {1, 2, 4};
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int j = 0; j < n; ++j)
    {
            if (mx < v[j])
                mx = v[j];
    }

    while(true)
    {
        ++i;
        ++cnt;

        for (int j = 0; j <= n; ++j)
        {
            if (j == n) 
            {
                cout << cnt - 1;
                return 0;
            }
            if (v[0] != v[j])
                break;
        }

        if (i == 3)
            i = 0;

        vector<int> needs(n);
        for (int j = 0; j < n; ++j)
        {
            needs[j] = mx - v[j];
        }

        bool check = false;
        for (int j = 0; j < n; ++j)
        {
            if (needs[j] == arr[i])
            {
                v[j] += needs[j];
                cout << j << "번 + " << arr[i] << endl;
                check = true;
            }
        }
        if (check)
        {
            continue;
        }
        
        int mx2 = 0;
        int mx2_pos = -1;
        for (int j = 0; j < n; ++j)
        {
            bool check2 = false;

            for (int k = 0; k < 3; ++k)
            {
                if (k == i)
                    continue;
                
                if (needs[j] == arr[k])
                    check2 = true;
            }

            if (check2)
                continue;

            if (mx2 < needs[j])
            {
                mx2 = needs[j];
                mx2_pos = j;
            }
        }

        if (mx2_pos != -1)
        {
            v[mx2_pos] += v[i];
            cout << "  " << mx2_pos+1 << "번 + " << arr[i] << endl;
            getchar();
        }
        else
        {
            cout << "SKIP " << arr[i] << endl;
        }
    }
}


//1. 1, 2, 4를 i를 통해 반복
//입력 된 수들 중 가장 큰 수가 되기 위해 더해야하는 값을 각각 구함 -> needs vector
//needs 를 돌며 arr[i] 와 일치하는 것이 있는지 확인 -> v[j] 에 needs[j] 를 더한 후 continue
//만약 없다면, arr[i] 보다 큰 needs[j] 중 가장 크고 1, 2, 4 가 아닌 수에 arr[i] 를 더함