#include <iostream>
using namespace std;

char map[4][6] = {
    "_____",
    "_____",
    "_____",
    "_____"};

void explode(int x, int y)
{
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 5)
            continue;

        if (map[nx][ny] == '_')
        {
            map[nx][ny] = '#';
        }
    }
}

int main()
{
    int x, y;
    for (int t = 0; t < 2; t++)
    {
        cin >> x >> y;
        explode(x, y);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
