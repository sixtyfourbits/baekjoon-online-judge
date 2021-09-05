#include <iostream>
#include <vector>
#include <string>


int							n;
int							m;
int							g_min = 5e2 + 1;
std::vector<std::string> 	plate;

void	input()
{
	std::cin >> n >> m;
	plate = std::vector<std::string>(n, std::string(m, 0));
	for (auto& i : plate)
		for (auto& j : i)
			std::cin >> j;
}

void	output()
{
	std::cout << g_min;
}

void	solution(int x, int y)
{
	int cnt = 0;
	std::vector<std::vector<int> > tmp_v(2);

	for(int i = x+1; i <= x+8; i++)
	{
		for(int j = y; j <= y+8; j++)
		{
			if (plate[i-1][j] == plate[i][j])
			{
				
				if (plate[i][j] == 'B')
					plate[i][j] = 'W';
				else
					plate[i][j] = 'B';

				cnt++;
				tmp_v[0].push_back(i);
				tmp_v[1].push_back(j);

			}
		}
	}

	if (cnt < g_min)
		g_min = cnt;
	
	if (x > m - 2)
		return solution(0, y + 1);
	return solution(x + 1, y);
}

int		main()
{
	input();
	solution(0, 0);
	output();
}