#include <iostream>

using namespace std;


int main ()
{
	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;

	int cmd = 0; // 0 = (p+1, q+1), 1 = (p-1, q-1), 2 = (p-1, q+1), 3 = (p+1, q-1)
	for (int i = 0; i < t; ++i)
	{
		if (p >= w)
		{
			if (q >= h)
			{
				cmd = 1;
			}
			else
			{
				if (cmd == 1 || cmd == 3)
				{
					cmd = 1;
				}
				else
				{
					cmd = 2;
				}

			}
		}
		else if (q >= h)
		{
			if (cmd == 0 || cmd == 3)
			{
				cmd = 3;
			}
			else
			{
				cmd = 1;
			}
		}
		else if (p <= 0)
		{
			if (q <= 0)
			{
				cmd = 0;
			}
			else
			{
				if (cmd == 1 || cmd == 2)
				{
					cmd = 3;
				}
				else
				{
					cmd = 0;
				}
			}
		}
		else if (q <= 0)
		{
			if (cmd == 0 || cmd == 3)
			{
				cmd = 1;
			}
			else
			{
				cmd = 2;
			}
		}

		if (cmd == 0)
		{
			++p;
			++q;
		}
		else if (cmd == 1)
		{
			--p;
			--q;
		}
		else if (cmd == 2)
		{
			--p;
			++q;
		}
		else
		{
			++p;
			--q;
		}
	}

	cout << p << " " << q;

}
