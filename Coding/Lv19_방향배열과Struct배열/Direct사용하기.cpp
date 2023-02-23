#include <iostream>
using namespace std;

int map[3][3] = {
    {3, 5, 4},
    {1, 1, 2},
    {1, 3, 9}};

int main()
{
    int x, y;
    cin >> x >> y;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
            continue;
        sum += map[nx][ny];
    }

    cout << sum;

    return 0;
}