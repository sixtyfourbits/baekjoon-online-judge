#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<vector<int> > > v(n + 1, vector<vector<int> >(0, vector<int>(3)));
    for (int i = 0; i < m; ++i)
    {
        int ttmp, itmp, stmp;
        cin >> ttmp >> itmp >> stmp;
        
        vector<int> tmp;
        tmp.push_back(ttmp); tmp.push_back(itmp); tmp.push_back(stmp);
        v[itmp].push_back(tmp);
    }
}