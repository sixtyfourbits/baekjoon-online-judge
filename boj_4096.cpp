
/*
#include <iostream>
#include <string>
#include <cctype>
void output(int ans)
{
	std::cout << ans << '\n';
}

void solution(std::string s, int i)
{
	if (!isdigit(s[i] + 1))
		solution(s, i+1);
	else
	{
		search_palindrome(s);
	}
}

void search_palindrome(std::string s)
{
	for (int i = 0; i < static_cast(s.size()) / 2; ++i)
	{
		if (s[i] != s[static_cast(s.size() - i - 1])
			{
				solution(s);
				return;
			}
	}
}

void input()
{
	std::string		s;
	std::cin >> s;

	if (s == "0")
		return;

	solution(s);
	input();
}

int main()
{
	input();
}
*/
/*
#include <iostream>
#include <vector>
#include <cctype>
#include <string>

std::string s;
int ans;

void	output()
{
	std::cout << ans << '\n';
}

bool	check_palindrome()
{
	int size = static_cast<int>(s.size());

	for (int i = 0; i < size; ++i)
	{
		if (s[i] != s[size - i - 1])
			return false;
	}

	return true;
}

void	solution()
{
	if (check_palindrome())
		output();
	else
	{
		int a = stoi(s);
		++a;
		s = std::to_string(a);

		solution();
	}
}

void	input()
{
	std::cin >> s;
	if (s == "0")
		return;
	else
		{
			ans = 0;
			solution();
			input();
			return;
		}

}

int		main()
{
	input();
}
*/

#include <iostream>

std::string s;
std::string ex = "0123456789"; //{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int ans;

void	output()
{
	std::cout << '\n' << ans;
}

bool	check_palindorme()
{
	int size = static_cast<int>(s.size());

	for (int i = 0; i < size / 2; ++i)
	{
		if (s[i] != s[size - i - 1])
			return false;
	}

	return true;
}

void	solution()
{
	if (check_palindorme())
		output();

	else
	{
		int check;
		for (int i = 0; check < 10; ++check)
		{
			check = i;

			if (s[s.size() - 1] == ex[check])
				break;
		}

		if (check == 9)
		{
			int cnt = 1;
			while (true)
			{
				if (s[s.size() - 1 - cnt] == '9')
				{
					s[s.size() - 1 - cnt] = '0';
					++cnt;
				}
				else
				{
					for (int i = 0; i < 10; ++i)
					{
						if (s[s.size() - 1 - cnt] == ex[i])
						{
							s[s.size() - 1 - cnt] = ex[i + 1];
							break;
						}
					}
					++ans;
					break;
				}
			}
		}
		else
		{
			s[s.size() - 1] = ex[check + 1];
			++ans;
		}

		solution();
	}
}

void	input()
{
	std::cin >> s;

	if (s == "0")
		return;
	else
	{
		ans = 0;
		solution();
		input();
	}

}

int		main()
{
	input();
}
