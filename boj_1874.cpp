#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int v[100001];
    for(int i = 0; i < n; ++i) cin >> v[i];

    int i = 1;
    int j = 0;
    int k = 0;
    char ans[200001];
    //vector<char> ans;
    stack<int> t;

    while (i <= n || j < n)
    {
        if (!t.empty() && t.top() == v[j])
        {
            t.pop();
            ans[k] = '-';
            ++k;
            ++j;
        }
        else
        {
            if (!t.empty() && t.top() > v[j])
            {
                cout << "NO";
                return 0;
            }

            t.push(i);
            ans[k] = '+';
            ++k;
            ++i;
        }
    }

    for (int i = 0; i < k; ++i)
        cout << ans[i] << '\n';
}