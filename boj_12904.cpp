#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
    string s, t;
    cin >> s >> t;

    while (t.length() > s.length())
    {
        //cout << t << endl;
        if (t[t.length() - 1] == 'A')
        {
            t.erase(t.end() - 1);
        }
        else if (t[t.length() - 1] == 'B')
        {
            t.erase(t.end() - 1);
            reverse(t.begin(), t.end());
        }
    }

    if (s == t)
        cout << 1;
    else
        cout << 0;
}