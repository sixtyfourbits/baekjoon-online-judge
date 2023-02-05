#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	string s;
	cin >> s;

	string res = s;
	vector<int> r;


	for (int i = 0; i < s.length(); ++i)
	{
		int rnd = rand() % s.length();

		bool c = true;
		for (int j = 0; j < r.size(); ++j)
		{
			if (r[j] == rnd)
			{
				c = false;
				--i;
				break;
			}
			
		}
		if (c)
			r.push_back(rnd);
	}

	for (int i = 0; i < s.length(); ++i)
	{
		res[i] = s[r[i]];
		cout << r[i] << " ";
	}

	cout << res;
}