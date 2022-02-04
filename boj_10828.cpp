#include <iostream>
#include <string>

using namespace std;

int arr[10001];
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

	for (int i = 0; i < n; ++i)
	{
		string arg;
		cin >> arg;

		if (arg == "push")
		{
			int x;
			cin >> x;

			push(x);
		}

		else if (arg == "pop")
			cout << pop() << '\n';

		else if (arg == "size")
			cout << size() << '\n';

		else if (arg == "empty")
			cout << empty() << '\n';

		else if (arg == "top")
			cout << top() << '\n';

		else if (arg == "full")
			cout << full(n) << '\n';
	}
}
