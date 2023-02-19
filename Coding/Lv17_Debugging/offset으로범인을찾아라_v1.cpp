#include <iostream>
using namespace std;

int main()
{
    char arr[3][5] =
        {
            "ATKB",
            "CZFD",
            "HGEI"};
    int x, y;
    int dx, dy;
    int offsetDx, offsetDy;
    char input;

    cin >> input;
    cin >> offsetDx >> offsetDy;
    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 4; y++)
        {
            if (arr[x][y] == input)
            {
                dx = x;
                dy = y;
            }
        }
    }

    cout << arr[dx + offsetDx][dy + offsetDy];

    return 0;
}