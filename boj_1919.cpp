#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()

{
    int sum = 0;
    string s1, s2;
    vector<int> v1(26);
    vector<int> v2(26);

    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); ++i)
    {
        v1[(int)s1[i] - 97]++;
    }

    for (int i = 0; i < s2.length(); ++i)
    {
        v2[(int)s2[i] - 97]++;
    }

    for (int i = 0; i < 26; ++i)
    {
        sum += abs(v1[i] - v2[i]);
    }

    cout << sum;
}