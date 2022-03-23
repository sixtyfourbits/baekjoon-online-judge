
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int r, l;
	int ans = 0;
	vector<int> rv;
	vector<int> lv;

	cin >> r >> l;

	int rtmp = r;
	while (rtmp)
	{
		rv.push_back(rtmp % 10);
		rtmp /= 10;
	}

	int ltmp = l;
	while (ltmp)
	{
		lv.push_back(ltmp % 10);
		ltmp /= 10;
	}

	if (rv.size() != lv.size())
	{
		cout << 0;
		return 0;
	}

	reverse(rv.begin(), rv.end());
	reverse(lv.begin(), lv.end());

	for (int i = 0; i < lv.size(); ++i)
	{
		if (rv[i] == 8 && lv[i] == 8)
			++ans;
		if (rv[i] != lv[i])
			break;
	}

	cout << ans;
}
