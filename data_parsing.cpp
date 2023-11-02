#include <iostream>
#include <string>

using namespace std;

int main()
{
    string data_type, name;
    int length;

    cin >> data_type >> length >> name;

    string s;

    if (length > 1)
    {
        s = data_type + "[" + to_string(length) + "] " + name;
    }
    else
    {
        s = data_type + " " + name;
    }

    cout << s;
}