#include <iostream>
#include <vector>
#include <string>

int n; int m;
std::vector<std::string> v;
std::vector<int> res;

void	input()
{
	std::cin >> n >> m;

	v = std::vector<std::string>(n);
	res.resize(n);

	for (int i = 0; i < n; ++i)
		std::cin >> v[i];

}

void	output(int i)
{
	std::cout << v[i] << '\n' << res[i];
}

void	solution()
{
	for (int i = 0; i < n; ++i)
	{
		int cnt = 0;
		for (int j = i; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (v[i][k] != v[j][k])
					++cnt;
			}
		}

		res[i] = cnt;
	}

	auto iter = std::min_element(std::begin(v), std::end(v));
	output(std::distance(std::begin(v), iter));
}

int 	main()
{
	input();
	solution();
}
