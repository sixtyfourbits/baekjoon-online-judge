#include <iostream>
#include <math.h>

using namespace std;

int main ()
{
	int t; cin >> t;
	for (int c = 0; c < t; ++c)
	{

		int n;
		cin >> n;

		int ADDH = 0; // +60
		int ADDT = 0; int MINT = 0; // +10 | -10
		int ADDO = 0; int MINO = 0; // +1 | -1

		{
			if (n > 0) { n -= 60; ++ADDH; } // +60분
		}

		while (abs(n) > 5)
		{
			if (n > 0) { n -= 10; ++ADDT; } // +10분
			else { n += 10; ++MINT; } // -10분
		}

		if (n > 0) ADDO += n; // +n분
		else MINO += abs(n); // -n분

		cout << ADDH << " " << ADDT << " " << MINT << " " << ADDO << " " << MINO << endl;

	}
}
