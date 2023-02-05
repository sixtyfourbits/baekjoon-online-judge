#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int							n;
int							m;
std::vector<std::string> 	v;

void	input()
{
	std::cin >> n >> m;

	v = std::vector<std::string>(n);
	for (int i = 0; i < n; ++i)
			std::cin >> v[i];
}

void	output(int ans)
{
	std::cout << ans * ans;
}

void	soulution()
{
	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 1; k <= std::min(n , m); ++k)
			{
				if (i + k >= n || j + k >= m)
					continue ;
				if (v[i][j] == v[i][j + k] && v[i][j] == v[i + k][j] && v[i][j] == v[i + k][j + k])
					ans = std::max(ans, k);
			}
		}
	}

	output(ans + 1);
}

int		main()
{
	input();
	soulution();
}
