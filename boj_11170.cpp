#include <iostream>

int t;

void 	output(int ans)
{
	std::cout << ans << '\n';
}

void	solution(int n, int m)
{
	int cnt = 0;

	for (int i = n; i <= m; ++i)
	{
		int i_temp = i;

		while(true)
		{
			if (i_temp % 10 == 0)
				++cnt;
			i_temp /= 10;
			if (i_temp == 0)
				break ;
		}
	}

	output(cnt);
}

void	input()
{
	int n; int m;

	std::cin >> t;

	for (int i = 0; i < t; ++i)
	{
		std::cin >> n >> m;
		solution(n, m);
	}
}

int		main()
{
	input();
}
