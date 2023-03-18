#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int dat[200] = {0};

    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        dat[str[i]]++;
    }

    char min = 'A';
    char max = 'A';
    for (int i = 'A'; i <= 'K'; i++)
    {
        if (dat[i] < dat[min])
        {
            min = i;
        }

        if (dat[i] > dat[max])
        {
            max = i;
        }
    }

    cout << max << '\n'
         << min;

    return 0;
}