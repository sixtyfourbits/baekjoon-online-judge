#include <iostream>
#include <vector>
#include <string>

int					cnt;
int					n;
std::vector<int> 	v;


void	solution(std::string ori_s, std::string s, int ori_st, int ori_ba)
{
	if (!((s[0] == '0' || s[1] == '0' || s[2] == '0')
		// return solution(ori_s, std::to_string(stoi(s) + 1), ori_st, ori_ba);
	|| (s[0] == s[1] || s[0] ==  s[2] || s[1] == s[2])))
		// return solution(ori_s, std::to_string(stoi(s) + 1), ori_st, ori_ba);
	{
	if (s == "987")
		return;

	int 		st = ori_st;
	int 		ba = ori_ba;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (s[i] == ori_s[j])
			{
				if (i == j)
					--st;
				else
					--ba;
			}
		}
	}

	if (st == 0 && ba == 0)
		++v[stoi(s)];

	}
	//std::cout << s << '\n';

	return solution(ori_s, std::to_string(stoi(s) + 1), ori_st, ori_ba);
}

void	input()
{
	cnt = 0;

	std::cin >> n;

	v.resize(1000);

	for (int i = 0; i < n; ++i)
	{
		int			strike;
		int			ball;
		std::string	tmp;

		std::cin >> tmp >> strike >> ball;
		solution(tmp, "123", strike, ball);
	}
}

void	output()
{
	std::cout << cnt;
}

void	find_ans()
{
	for (int i = 123; i <= 987; ++i)
		if (v[i] == n)
			++cnt;
}

int		main()
{
	input();
	find_ans();
	output();
}
