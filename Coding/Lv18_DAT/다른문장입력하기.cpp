#include <iostream>
#include <string>
using namespace std;

string arr[3];

int dat[200];

int NoExist()
{
    for (int i = 0; i < 3; i++)
    {
        int len = arr[i].length();
        for (int j = 0; j < len; j++)
        {
            dat[arr[i][j]]++;

            if (dat[arr[i][j]] >= 2)
            {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{

    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    if (NoExist())
    {
        cout << "Perfect";
    }

    else
    {
        cout << "No";
    }

    return 0;
}