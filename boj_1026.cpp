#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int i, int j)
{
	return i > j;
}

int main ()
{
	int n;
	int sum = 0;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);

	for (int i = 0 ; i < n; ++i)
		sum += a[i]*b[i];

	cout << sum;
}
