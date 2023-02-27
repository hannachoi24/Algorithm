#include <iostream>
using namespace std;

int win[2][3] = {
    {3, 5, 1},
    {4, 2, 6}};

int people[4];

int isExist(int n)
{
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (win[x][y] == n)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> people[i];
    }

    for (int k = 0; k < 4; k++)
    {
        if (isExist(people[k]))
        {
            cout << people[k] << "번 합격" << '\n';
        }
        else
        {
            cout << people[k] << "번 불합격" << '\n';
        }
    }

    return 0;
}
