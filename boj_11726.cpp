#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	long long a, b, c;

	a = 1;
	b = 1;


	for (int i = 1; i < n; ++i)
	{
		c = (a + b) % 10007;
		a = b;
		b = c;

	}

	cout << b;
}
