/*
	!!! 해결 못함 !!!
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int t; cin >> t;
	for (int c = 0; c < t; ++c)
	{
		int n; cin >> n;
		int cnt = 0;
		int avr = 0;
		vector<int> v(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			avr += v[i]; // 모든 점수 합산
		}
		//cout << avr << '\n';

		for (auto& i : v)
			cnt += i > (double(avr) / n) ? 1 : 0; // 점수가 평균 값보다 크면 cnt += 1

		//cout << avr << " " << cnt << '\n';
		cout << round(double(cnt) / n * 100000) / 1000 << '\n'; // 평균 이상 점수 갯수 / 점수 갯수 * 100 = 평균 이상 비율
																// v평균 이상 비율에 소수 셋째자리까지 반올림
																// 평균 이상 비율 * 1000 을 반올림 후 다시 / 1000
	}
}
