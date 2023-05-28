#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, e;
    cin >> s >> e;

    if (s > e)
    {
        string t;
        t = s;
        s = e;
        e = t;
    }

    int cnt = 0;
    for (; ;)
    {
        if (s == e)
            break;

        if (s.length() == e.length())
        {
            for (int j = 1; j < s.length(); ++j)
            {
                if (s[j] != e[j])
                {
                    s[j] = e[j];
                    //cout << s << endl;
                    ++cnt;
                }
            }
        }


        if (s.length() < e.length())
        {
            
            for (int j = 1; j < s.length(); ++j)
            {
                if (s[j] == '0')
                {
                    s[j] = '1';
                    //cout << s << endl;
                    ++cnt;
                }
            }
            
            string tmp;
            tmp.push_back('1');
            for (int j = 0; j < s.length(); ++j)
            {
                tmp.push_back('0');
            }

            ++cnt;
            s = tmp;
            //cout << s << endl;
        }
    }

    cout << cnt;
}