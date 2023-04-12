#include <iostream>
#include <string>
using namespace std;

string str = "BAQRRGGVAQZAACT";

int main()
{
    int dat[100] = {0};

    int max = 0;
    char maxCh;
    for (int i = 0; i < 5; i++)
    {
        dat[str[i]]++;
        if (dat[str[i]] > max)
        {
            max = dat[str[i]];
            maxCh = str[i];
        }
    }

    for (int i = 0; i < str.size() - 5; i++)
    {
        dat[str[i]--];
        dat[str[i + 5]]++;

        if (dat[str[i + 5]] > max)
        {
            max = dat[str[i + 5]];
            maxCh = str[i + 5];
        }
    }

    cout << maxCh;

    return 0;
}