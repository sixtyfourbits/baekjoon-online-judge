#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<int> v;

	cin >> n;
	v.push_back(n % 42);

	for(int i = 1; i < 10; ++i)
	{
		cin >> n;

		int check = 0;
		for (int j = 0; j < static_cast<int>(v.size()); ++j)
		{
			if (n % 42 == v[j])
			{
				check = 1;
				break;
			}
		}

		if (!check)
			v.push_back(n % 42);
	}

	cout << v.size();
}
