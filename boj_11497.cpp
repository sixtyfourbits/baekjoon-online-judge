#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(int a, int b)
{
    return a > b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        sort(v.begin(), v.end(), compare);

        vector<int> ans;

        ans.push_back(v[0]);
        for (int i = 1; i < n; ++i)
        {
            if(i % 2 == 0) 
            {
                ans.insert(ans.begin(), v[i]);
            }
            else
            {
                ans.push_back(v[i]);
            }

        }
        /*
        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << " ";
        cout << endl;
        */

        int mx = 0;

        for (int i = 1; i < n; ++i)
        {
            mx = max(abs(ans[i]-ans[i-1]), mx);
            //cout << abs(ans[i]-ans[i-1]) << " ";
        }
        mx = max(abs(ans[0] - ans[n-1]), mx);
        //cout << abs(ans[0] - ans[n-1]) << endl;

        cout << mx << endl;
    }
}