#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct pos
{
    int x;
    int y;
}Pos;

Pos arr[1000000];

bool compare(Pos a, Pos b)
{
    return a.x < b.x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> arr[i].x >> arr[i].y;

    sort(arr, arr+n, compare);

    int mx = arr[0].y;
    int sum = arr[0].y - arr[0].x;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i].x <= mx)
        {
            if (arr[i].y - mx > 0)
            {
                sum += arr[i].y - mx;
                mx = arr[i].y;
            }
        }
        else
        {
            sum += arr[i].y - arr[i].x;
            mx = arr[i].y;
        }
    }

    cout << sum;
}
