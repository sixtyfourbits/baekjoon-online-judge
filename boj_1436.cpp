#include <iostream>
#include <vector>
#include <string>

int					n;
std::vector<int> 	v;

void	input()
{
	std::cin >> n;
	v.push_back(666);
}

void	output()
{
	std::cout << v[n - 1];
}

void	check(int i)
{
	int res = v[i];
	while(true)
	{
		int tmp = res;
		int cnt = 0;

		while(tmp > 0)
		{
			if (cnt >= 3)
				break;

			if (tmp % 10 == 6)
				++cnt;
			else
				cnt = 0;

			tmp /= 10;
		}

		if (cnt >= 3)
			break;

		++res;
	}

	v[i] = res;

}

void	solution()
{
	for (int i = 1; i <= n; ++i)
	{
		v[i] = v[i - 1] + 1;
		check(i);
	}
}

int		main()
{
	input();
	solution();
	output();
}
