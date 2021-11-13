#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> WB = {"WBWBWBWB",
					"BWBWBWBW",
					"WBWBWBWB",
					"BWBWBWBW",
					"WBWBWBWB",
					"BWBWBWBW",
					"WBWBWBWB",
					"BWBWBWBW"};

vector<string> BW = {"BWBWBWBW",
					"WBWBWBWB",
					"BWBWBWBW",
					"WBWBWBWB",
					"BWBWBWBW",
					"WBWBWBWB",
					"BWBWBWBW",
					"WBWBWBWB"};
vector<string> plate;

int n; int m;

int check_plate(int a, int b)
{
	int cnt_wb = 0;
	int cnt_bw = 0;

	for (int i = a; i <= a + 7; ++i)
	{
		for (int j = b; j <= b + 7; ++j)
		{
			if (WB[i-a][j-b] != plate[i][j])
				++cnt_wb;
			if (BW[i-a][j-b] != plate[i][j])
				++cnt_bw;
		}
	}
	//cout << cnt_wb << " " << cnt_bw << '\n';
	return min(cnt_wb, cnt_bw);
}

int main()
{
	int ans = 2502;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		plate.push_back(temp);
	}

	for (int i = 0; i <= n - 8; ++i)
	{
		for (int j = 0; j <= m - 8; ++j)
		{
			ans = min(ans, check_plate(i, j));
		}
	}

	cout << ans;
}
