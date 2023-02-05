#include <iostream>

using namespace std;

int main()
{
	int n;
	int cnt = 0; // 영화 제목 번째 카운트

	cin >> n;

	int i = 665; // 수
	while (true)
	{
		++i;

		int tmp = i;
		int check = 0; // 6 연속 횟수 체크

		while (true)
		{
			if (check == 3)
			{
				++cnt;
				break;
			}
			if (tmp == 0)
				break;

			if (tmp % 10 == 6)
				++check;
			else
				check = 0;

			tmp /= 10;
		}

		if (cnt == n)
		{
			cout << i;
			return 0;
		}
	}
}
