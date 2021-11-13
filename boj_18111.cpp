#include <iostream>
#include <vector>
#include <algorithm>

int n; int m; int b;
std::vector<std::vector<int> > 	v;

void	input()
{
	std::cin >> n >> m >> b;

	v = std::vector<std::vector<int> >(n, std::vector<int>(m));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			std::cin >> v[i][j];
}

void	output(int height, int time)
{
	std::cout << time << " " << height;
}

void	solution()
{
	int time;
	int height = -1;

	for (int k = 0; k < 256; ++k)
	{
		int b_temp = b;
		int t_temp = 0;
		for(int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (v[i][j] > k)
				{
					t_temp += 2;
					b_temp += v[i][j] - k;
				}
				else
				{
					++t_temp;
					b_temp += v[i][j] - k;
				}
			}
		}

		if (time >= t_temp)
		{
			time = t_temp;
			height = k;
		}
	}

	output(height, time);
}

int		main()
{
	input();
	solution();
}
