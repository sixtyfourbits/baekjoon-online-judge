/*
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
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const std::vector<std::string> wb_tile = {
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW"
};
const std::vector<std::string> bw_tile = {
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB"
};
int g_answer;
std::pair<int, int> g_matrix;
std::vector<std::string> g_tile;

void pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void input_action(void)
{
	std::cin >> g_matrix.first >> g_matrix.second;
	g_tile = std::vector<std::string>(g_matrix.first, std::string(g_matrix.second, 0));
	for (auto& i : g_tile)
		for (auto& j : i)
			std::cin >> j;
			g_answer = 2147483647;
}

int tile_count(int x, int y, bool is_wb)
{
	int cnt = 0;
	const std::vector<std::string>& the_tile = is_wb ? wb_tile : bw_tile;

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			if (the_tile.at(i).at(j) != g_tile.at(i + x).at(j + y))
				++cnt;
			return (cnt);
}

void solution(void)
{
	for (int i = 0; i + 8 <= g_matrix.first; ++i)
		for (int j = 0 ; j + 8 <= g_matrix.second; ++j)
			g_answer = std::min({tile_count(i, j, true), tile_count(i, j, false), g_answer});
}

void output_action(void)
{
	std::cout << g_answer;
}

int main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
