#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	int n;
	int result = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int temp = 0;
		result = 0;

		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'O')
			{
				temp++;
				result += temp;
			}


			else
			{
				temp = 0;
			}
		}
		cout << result << endl;
	}
}
