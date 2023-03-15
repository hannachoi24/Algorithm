#include <iostream>
using namespace std;

char a;

int isExist()
{
    char map[2][2][4] = {
        "ATB",
        "CCB",

        "AAA",
        "BBC"};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (map[i][j][k] == a)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    cin >> a;

    if (isExist())
    {
        cout << "발견" << '\n';
    }
    else
        cout << "미발견";

    return 0;
}