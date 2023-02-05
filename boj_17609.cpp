#include <iostream>
#include <string>

using namespace std;

string s;

int fl(int r, int l)
{
	while (r >= l)
    {
        if (s[r] != s[l])
            return 2;
        cout << "asd";
        ++r; --l;
    }

    return 1;
}
int main()
{
    int n;

    cin >> n;

    for (int t = 0; t < n; ++t)
    {

        cin >> s;

        int ans;
        int acc = 0;

        int r = 0;
        int l = s.size() - 1;

        for (int i = 1; i <= s.size() / 2; ++i)
        {
            if (s[r] != s[l])
            {
                ++acc;

                if (acc == 2)
                {
                    ans = 2;
                    break;
                }

                if (s[r] == s[l - 1] && s[r + 1] == s[l])
                {
                    ans = min(fl(r, l - 1), fl(r + 1, l));
                    break;
                }
                else if (s[r] == s[l - 1])
                {
                    --l;
                    --i;
                    continue;
                }
                else if (s[r + 1] == s[l])
                {
                    ++r;
                    --i;
                    continue;
                }
                else
                {
                    ans = 2;
                    break;
                }
            }

            if (i == s.size() / 2)
                ans = acc;

            ++r; --l;
        }

        cout << ans;

    }
}
