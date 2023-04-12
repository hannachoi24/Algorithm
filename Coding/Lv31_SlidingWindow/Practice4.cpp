#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "ABBABQAADAA";
    int dat[100] = {0};
    int max = 0;

    for (int i = 0; i < 4; i++)
    {
        dat[str[i]]++;
    }

    int limit = str.length() - 4;
    for (int i = 0; i <= limit; i++)
    {
        if (dat['A'] > max)
        {
            max = dat['A'];
        }

        if (i == limit)
            break;

        dat[str[i]]--;
        dat[str[i + 4]]++;
    }

    cout << max;

    return 0;
}