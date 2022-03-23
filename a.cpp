#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	int n;
	int n2;
	vector<string> v;
	vector<string> v2;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		v.push_back(s);
	}

	cin >> n2;
	for (int i = 0; i < n2; ++i)
	{
		string s2;
		cin >> s2;

		v2.push_back(s2);
	}

	for (auto& i : v)
	{
		cout << i;
	}
	for (auto& i : v2)
	{
		cout << i;
	}
}
