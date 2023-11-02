#include <iostream> 
#include <map>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    map<string, int> p1; //<이름, 번호>
    map<int, string> p2; //<번호, 이름>

    vector<string> ans;

    for (int i = 1; i <= n; ++i)
    {
        string a; cin >> a;
        p1[a] = i;
        p2[i] = a;
    }

    for (int i = 0; i < m; ++i)
    {
        string a; cin >> a;

        if(a[0] >= 65 && a[0] <= 90) //문자
        {
            cout << p1[a] << '\n';
            //ans.push_back(p1[a]);
        }
        else //숫자
        {
            cout << p2[stoi(a)] << '\n';
            //ans.push_back(p2[a]);
        }
    }

    // for (int i = 0; i < ans.size(); ++i)
    //     cout << ans[i] << endl;
}