#include <iostream>
#include <cmath>

using namespace std;

int n;
int ans;

void solution(int a)
{
	if (a > n)
	{
		cout << ans;
		return;
	}

	int dif = abs(a % 10 - a % 100);
	int a_tmp = a;
	while (true)
	{
		if (a_tmp / 100 <= 0)
			++ans; break;

		if (abs(a_tmp % 10 - a_tmp % 100) != dif)
			break;

		a_tmp /= 10;
	}

	return solution(a + 1);
}

int main()
{
	cin >> n;

	if (n >= 99)
	{
		ans = 99;
		solution(100);
	}
	else
	{
		cout << n;
	}
}
