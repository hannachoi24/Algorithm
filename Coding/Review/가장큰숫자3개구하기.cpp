#include <iostream>
using namespace std;

int n, m;
int map[10][10];
bool visited[10][10];

struct Coordinate // 좌표를 저장하기 위한 구조체
{
    int x, y;
};

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    // 가장 큰 숫자 3개와 해당 좌표를 저장할 배열 선언
    int max_nums[3] = {
        -2100000000,
        -2100000000,
        -2100000000,
    };
    Coordinate max_coords[3];

    for (int cnt = 0; cnt < 3; cnt++)
    {
        int max_num = -21e8;
        Coordinate max_coord; // 좌표 저장할 변수 선언
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] > max_num && !visited[i][j])
                {
                    max_num = map[i][j];
                    max_coord.x = i;
                    max_coord.y = j;
                }
            }
        }
        max_nums[cnt] = max_num;
        max_coords[cnt] = max_coord;
        visited[max_coord.x][max_coord.y] = true;
    }

    // 결과 출력
    for (int i = 0; i < 3; i++)
    {
        cout << max_nums[i] << "(" << max_coords[i].x << "," << max_coords[i].y << ")" << '\n';
    }

    return 0;
}