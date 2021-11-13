#include <iostream>
#include <vector>

std::vector<int> v;

void	input()
{
	v = std::vector<int>(10);

	for (int i = 0; i < 10; ++i)
		std::cin >> v[i];
}

void	output(int ans)
{
	std::cout << ans;
}

void	solution()
{
	int sum = 0;

	for (int i = 0; i < 10; ++i)
	{
		sum += v[i];
		if (sum > 100)
		{
			if (100 - (sum - v[i]) < sum - 100)
				sum -= v[i];
			break;
		}
	}
	return output(sum);
}

int		main()
{
	input();
	solution();
}
