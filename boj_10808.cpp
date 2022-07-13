#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
	string s;
	cin >> s;

	vector<int> v(128, 0);

	for (int i = 0; i < s.size(); ++i)
	{
		++v[s[i]];
	}

	for (int i = 97; i <= 122; ++i)
	{
		cout << v[i] << " ";
	}
}
