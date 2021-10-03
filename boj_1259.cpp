#include <iostream>

std::string		s;

void output(bool ans)
{
	if(ans)
		std::cout << "yes" << "\n";
	else
		std::cout << "no" << "\n";
}

void solution(int i)
{
	if (i - 1 >= static_cast<int>(s.size()) / 2)
		return output(true);

	if (s[i] == s[s.size() - i - 1])
		return solution(i+1);
	else
		return output(false);
}

void input()
{
	std::cin >> s;

	if (s == "0")
		return;

	solution(0);
	input();
}

int main()
{
	input();
}
