#include <iostream>
using namespace std;

int main()
{
    int map[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        int num = map[i][0];
        bool isSame = true;

        for (int j = 0; j < 3; j++)
        {
            if (map[i][j] != num)
            {
                isSame = false;
                break;
            }
        }
        if (isSame)
        {
            cout << num << '\n';
        }
        else
            cout << "x" << '\n';
    }

    return 0;
}