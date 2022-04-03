#include <iostream>

using namespace std;

int main ()
{
	int n, k;
	cin >> n >> k;

	int a = (n- (k + 1) * k / 2) % k;

	if (n < (k+1) * k / 2)
		cout << -1;
	else if (a == 0)
		cout << k - 1;
	else
		cout << k;

}
