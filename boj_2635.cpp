#include <iostream>
#include <vector>

int		n;
int		max_count;
std::vector<int> save;

void	input()
{
	std::cin >> n;

	max_count = 0;
}

void	output()
{
	std::cout << max_count << '\n';

	for (auto&i: save)
		std::cout << i << ' ';
}

void		calc(int sec)
{
	int					i = 2;
	std::vector<int> 	v;

	v.push_back(n);
	v.push_back(sec);

	while (v[i - 2] >= v[i - 1])
	{
		v.push_back(v[i - 2] - v[i - 1]);

		++i;
	}
	if (save.size() < v.size())
		save = v;
	max_count = std::max(max_count, i);
}

void	solution()
{
	for (int i = n / 2; i <= n - n / 4 + 1; i++)
		calc(i);

	output();
}

int		main()
{
	input();
	solution();
}
