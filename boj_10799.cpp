#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int stick = 0;
    int cnt = 0;
    int cut = 0;

    for (int i = 0; i < s.length() - 1; ++i)
    {
        if (s[i] == '(')
        {
            if (s[i+1] == ')')
            {
                cut += stick;
                ++i;
            }
            else
            {
                ++stick;
                ++cnt;
            }
        }
        else
            --stick;
    }

    cout << cnt + cut;
}