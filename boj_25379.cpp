// #include <iostream>
// #include <algorithm>

// using namespace std;

// int arr[1000001];
// int arr2[1000001];

// int main()
// {
//     int n;

//     cin >> n;
//     for (int i = 0; i < n; ++i)
//         cin >> arr[i];
//     for (int i = 0; i < n; ++i)
//         arr2[i] = arr[i];

//     int cnt1 = 0;

//     for (int i = 1; i < n; ++i)
//     {
//         if (arr[i] % 2 == 0)
//         {
//             if (arr[i - 1] % 2 == 0)
//                 continue;

//             int tmp = arr[i - 1];
//             arr[i - 1] = arr[i];
//             arr[i] = tmp;
//             ++cnt1;
//             /*
//             for (int j = 0; j < n; ++j)
//                 cout << arr[j] << " ";
//             cout << endl;
//             */

//             i -= 2;
//         }
//     }

//     int cnt2 = 0;
//     for (int i = n - 2; i >= 0; --i)
//     {
//         if (arr2[i] % 2 == 0)
//         {
//             if (arr2[i + 1] % 2 == 0)
//                 continue;

//             int tmp = arr2[i];
//             arr2[i] = arr2[i + 1];
//             arr2[i + 1] = tmp;
//             ++cnt2;
//             /*
//             for (int j = 0; j < n; ++j)
//                 cout << arr[j] << " ";
//             cout << endl;
//             */

//             i += 2;
//         }
//     }

//     cout << min(cnt1, cnt2);
// }

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int a1 = 0;
    int cnt1 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] % 2 == 0)
        {
            cnt1 += i - a1;
            ++a1;
        }
    }

    int a2 = n - 1; 
    int cnt2 = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (arr[i] % 2 == 0)
        {
            cnt2 += a2 - i;
            --a2;
        }
    }
    //cout << cnt1 << " " << cnt2 << endl;
    cout << min(cnt1, cnt2);
}