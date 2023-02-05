#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;

    for (int i = l; i <= 100; ++i)
    {
        int sum = 0;
        for (int j = 0; j < i; ++j)
        {
            sum += j;
        }
        
        if (n == sum)
        {
            for (int j = 0; j < i; ++j)
                cout << j << " ";
            return 0;
        }

        else if ((n - sum) % i == 0)
        {
            if (n - sum < 0)
                continue;

            for (int j = 0; j < i; ++j)
                cout << (n - sum) / i + j << " ";
            return 0;
        }
    }

    cout << "-1";
}