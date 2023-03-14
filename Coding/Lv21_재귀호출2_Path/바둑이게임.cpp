#include <iostream>
#include <queue>
using namespace std;

char map[7][8] = {
    "0000000",
    "00W0W00",
    "0WB0BW0",
    "00WBW00",
    "00BW0W0",
    "0WW0000",
    "0000000",
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int Wx, Wy;

struct Node
{
    int x, y;
};

queue<Node> q;

int main()
{

    cin >> Wx >> Wy;

    map[Wx][Wy] = 'W';

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (map[i][j] == 'B')
            {
                q.push({i, j});
            }
        }
    }

    int Black = 0;

    while (!q.empty())
    {
        int cnt = 0;
        int Bx = q.front().x;
        int By = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = Bx + dx[i];
            int ny = By + dy[i];

            if (nx < 0 && nx > 7 && ny < 0 && ny > 7)
                continue;

            if (map[nx][ny] == 'W')
            {
                cnt++;
            }
        }
        if (cnt == 4)
        {
            Black++;
        }
    }

    cout << Black;

    return 0;
}
