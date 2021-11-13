#include <iostream>
#include <vector>


std::vector<std::string> v(5);
std::vector<std::string> s;

void	input()
{
	for (int i = 0; i < 5; ++i)
		std::cin >> v[i];
}

void	output()
{

}

void	solution(int x, int y, int cnt, int i)
{
	if (cnt <= 0)
	{
		s.push_back(v[x][y]);
		i = s.size() - 1;
	}

	++cnt;

}

int		main()
{

}
