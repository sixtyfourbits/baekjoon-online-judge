#include <iostream>
#include <vector>
#include <string>

std::vector<std::string>	vs;

void output(std::string ans)
{
	std::cout << ans << '\n';
}

bool search_palindrome(std::string s)
{
	for (int i = 0; i < static_cast<int>(s.size()); ++i)
	{
		if (s[i] != s[static_cast<int>(s.size()) - i - 1])
			return false;
	}

	return true;
}

void solution()
{
	for (int i = 0; i < static_cast<int>(vs.size()); ++i)
	{
		for (int j = 0; j < static_cast<int>(vs.size()); ++j)
		{
			if (i == j)
				continue ;
			if (search_palindrome(vs[i] + vs[j]))
				{
					output(vs[i] + vs[j]);
					return ;
				}
		}
	}
	output("0");
}

void input(int t)
{
	for (int i = 0; i < t; i++)
	{
		int							n;

		std::cin >> n;
		vs = std::vector<std::string>(n);

		for(int j = 0; j < n; j++)
			std::cin >> vs[j];

		solution();
	}
}

void case_input()
{
	int		t;
	std::cin >> t;

	input(t);
}

int main()
{
	case_input();
}
