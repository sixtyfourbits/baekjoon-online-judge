#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 0;
vector<vector<int> > v;
vector<bool> completed(101, false);

void func(int start, int end)
{
    if (completed[end])
        return;

    completed[start] = true;
    completed[end] = true;
    for (int i = 0; i < n; ++i)
    {
        if (v[i][0] == end)
        {
            func(v[i][0], v[i][1]);
        }
        if (v[i][1] == end)
        {
            func(v[i][1], v[i][0]);
        }
    }
    ++cnt;
}

int main()
{
    int a;
    cin >> a; 
    cin >> n;

    v = vector<vector<int> > (n, vector<int>(2));
    for (int i = 0; i < n; ++i)
        cin >> v[i][0] >> v[i][1];

    func(1, 1);
    cout << cnt - 1;
}