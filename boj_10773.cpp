#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[100001];
int last_index = -1;

void push(int x)
{
	++last_index;
	arr[last_index] = x;
}

int pop()
{
	if (last_index == -1)
		return -1;

	int tmp = arr[last_index];

	arr[last_index] = 0;
	--last_index;

	return tmp;
}

int size()
{
	return last_index + 1;
}

int empty()
{
	if (last_index == -1)
		return 1;

	return 0;
}

int top()
{
	if (last_index != -1)
		return arr[last_index];

	return -1;
}

int full(int n)
{
	if (last_index + 1 == n)
		return 1;

	return 0;
}

int main()
{
	int n;
	cin >> n;

	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		int arg;
		cin >> arg;

		if (arg == 0)
			pop();
		else
			push(arg);
	}

	int saved_size = size();

	for (int i = 0; i < saved_size; ++i)
	{
		ans += pop();
	}

	cout << ans;
}
