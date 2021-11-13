#include <iostream>

std::string 	s;
std::string 	se;
int 			ans;

void	input()
{
	std::getline(std::cin, s);
	std::getline(std::cin, se);

	ans = 0;
}

void	output()
{
	std::cout << ans;
}

void	solution()
{
	for (int i = 0; i < static_cast<int>(s.size() - se.size()) + 1;)
	{
		bool check = true;
		for (int j = 0; j < static_cast<int>(se.size()); ++j)
		{
			if(s[i+j] != se[j])
			{
				check = false;
				break;
			}
		}

		if (check)
		{
			++ans;
			i += se.size();
		}
		else
			++i;
	}
}

int		main()
{
	input();
	solution();
	output();
}
