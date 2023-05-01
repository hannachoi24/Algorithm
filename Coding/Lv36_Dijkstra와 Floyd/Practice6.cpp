#include <iostream>
#include <queue>
using namespace std;

// Floyd-Warshall

const int M = 21e5;

int map[4][4] = {
    0, 30, 40, 2,
    M, 0, 10, 1,
    M, M, 0, M,
    M, 2, 60, 0};

int main()
{
    // for 1: 경유할 곳

    for (int i = 0; i < 4; i++)
    {
        // for 2: 출발지점
        // for 3: 도착지점
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (map[j][k] > map[j][i] + map[i][k])
                {
                    map[j][k] = map[j][i] + map[i][k];
                }
            }
        }
    }

    return 0;
}