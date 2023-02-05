#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > v(n, vector<int>(3));

    v[0][0] = 1;
    v[0][1] = 1;
    v[0][2] = 1;

    for (int i = 1; i < n; ++i)
    {
        v[i][0] = (v[i - 1][1] + v[i - 1][2]) % 9901;
        v[i][1] = (v[i - 1][0] + v[i - 1][2]) % 9901;
        v[i][2] = (v[i - 1][0] + v[i - 1][1] + v[i - 1][2]) % 9901;
    }

    cout << (v[n - 1][0] + v[n - 1][1] + v[n - 1][2]) % 9901;
}