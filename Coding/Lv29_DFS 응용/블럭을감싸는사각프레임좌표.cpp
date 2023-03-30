#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int x, y;
};

int map[4][5];

queue<Node> q;

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (map[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }

    cout << "(" << q.front().x << "," << q.front().y << ")" << '\n';
    cout << "(" << q.back().x << "," << q.back().y << ")" << '\n';

    return 0;
}

/* 또 다른 코드
#include <iostream>
using namespace std;

int vect[4][5];

void input()
{
    int x, y;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 5; x++) {
            cin >> vect[y][x];
        }
    }
}
int main()
{
    input();

    int maxX = -1;
    int maxY = -1;
    int minX = 9;
    int minY = 9;

    int x, y;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 5; x++) {
            if (vect[y][x] == 1)
            {
                if (x > maxX) maxX = x;
                if (y > maxY) maxY = y;
                if (x < minX) minX = x;
                if (y < minY) minY = y;
            }
        }
    }

    cout << "(" << minY << "," << minX << ")" << endl;
    cout << "(" << maxY << "," << maxX << ")" << endl;

    return 0;
}
*/