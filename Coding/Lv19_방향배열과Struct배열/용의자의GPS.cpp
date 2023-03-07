#include <iostream>
using namespace std;

struct Coord
{
    int x;
    int y;
};

int main()
{
    Coord input[4];

    for (int i = 0; i < 4; i++)
    {
        cin >> input[i].x >> input[i].y;
    }

    int vect[4][3] = {0};

    for (int i = 0; i < 4; i++)
    {
        vect[input[i].x][intput[i].y] = 5;
    }

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 3; y++)
        {

            cout << vect[x][y] << " ";
        }
        cout << '\n';
    }

    return 0;
}