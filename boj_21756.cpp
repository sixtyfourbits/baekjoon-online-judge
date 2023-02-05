#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n;
	cin >> n;

	vector<int> v(n+1);
	for (int i = 1; i <= n; ++i) v[i] = i;

	while (v.size() > 2)
	{
		for (int i = 1; i <= n; i+=2)
		{
			v[i] = -1;
			//cout << i << endl;
		}

		for (int i = 1; i <= v.size(); ++i)
		{
			if (v[i] == -1)
			{
				//cout << i << endl;
				v.erase(v.begin() + i);
			}
		}
	}

	cout << v[1];
}
