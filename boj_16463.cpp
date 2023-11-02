#include <iostream>

using namespace std;

int main()
{
    int year = 2019;
    int month = 1;
    int day = 4;


    int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n;
    cin >> n;

    int cnt = 0;

    while (year <= n)
    {
        /*
        if (month <= 7)
        {
            if (month % 2 == 0)
                max_day = 30;
            else
                max_day = 31;
        }
        else
        {
            if (month % 2 == 0)
                max_day = 31;
            else
                max_day = 30;
        }
        */
       
        if (month == 2)
        {
            if (year % 400 == 0 || (year % 400 != 0 && year % 100 != 0 && year % 4 == 0))
                d[month - 1] = 29;
            else
                d[month - 1] = 28;
        }

        if (day == 13)
            ++cnt;

        day += 7;

        if (day > d[month - 1])
        {
            day -= d[month - 1];
            ++month;

            if (month > 12)
            {
                ++year;
                month = 1;
            }
        }
    }

    cout << cnt;
}