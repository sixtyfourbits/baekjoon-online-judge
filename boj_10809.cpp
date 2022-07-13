#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
	string s;
	vector<int> v(26, -1);

	cin >> s;

	for (int i = 0; i < s.size(); ++i)
	{
		if (v[s[i] - 97] == -1)
			v[s[i] - 97] = i;
	}

	for (int i = 0; i < 26; ++i)
	{
		cout << v[i] << ' ';
	}
}
