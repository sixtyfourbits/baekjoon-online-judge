#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<bool> check(n + 1, false);

	for (int i = 0; i < n; ++i)
	{
		if (!check[v[i]])
			check[v[i]] = true;
		else
			cout << v[i];
	}
}
