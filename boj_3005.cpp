#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string s1, string s2)
{
    for (int i = 0; i < min(s1.size(), s2.size()); ++i)
    {
        if (s1[i] < s2[i])
            return true;

        if (s1[i] > s2[i])
            return false;
    }

    return s1.size() < s2.size();
}
int main()
{
    int r, c;
    cin >> r >> c;

    vector<vector<char> > v(r, vector<char>(c));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) 
            cin >> v[i][j];

    vector<string> s;
    

    for (int i = 0; i < r; ++i)
    {
        s.push_back("");
        for (int j = 0; j < c; ++j)
        {
            if (v[i][j] == '#')
            {
                if (j != c - 1 && j != 0)
                    s.push_back("");
                continue;
            }

            s[s.size() - 1].push_back(v[i][j]);
        }
    }

    for (int j = 0; j < c; ++j)
    {
        s.push_back("");
        for (int i = 0; i < r; ++i)
        {
            if (v[i][j] == '#')
            {
                if (i != r - 1 && i != 0)
                    s.push_back("");
                continue;
            }

            s[s.size() - 1].push_back(v[i][j]);
        }
    }

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i].size() < 2)
        {
            s.erase(s.begin() + i);
            --i;
        }
    }

    sort(s.begin(), s.end(), compare);

    // for (int i = 0; i < s.size(); ++i)
    // {
    //     cout << s[i] << endl;
    // }

    cout << s[0];
}