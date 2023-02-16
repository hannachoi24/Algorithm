#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char town[3][3] = {
        {'C', 'D', 'A'},
        {'B', 'M', 'Z'},
        {'Q', 'P', 'O'}};

    char black[200];

    cin >> black;

    int len = strlen(black);

    int target[200] = {0};

    for (int i = 0; i < len; i++)
    {
        target[black[i]] = 1;
    }

    int cnt = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (target[town[j][k]] == 1)
            {
                cnt++;
            }
        }
    }

    cout << cnt << "명";

    return 0;
}