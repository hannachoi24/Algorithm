#include <iostream>
using namespace std;

// 숫자를 조합해 곱셈을 하고 나올 수 있는 개수 출력

int map[3][3] = {
    4,
    5,
    -1,
    2,
    -3,
    -4,
    0,
    1,
    2,
};

bool visit[3][3];
int cnt;
int dat[3000];

void run(int lev, int mul)
{
    if (lev == 4)
    {
        if (dat[mul + 1000] == 0)
            cnt++;
        dat[mul + 1000] = 1;
        // cnt++;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (visit[i][j] == true)
                continue;
            visit[i][j] = true;
            run(lev + 1, mul * map[i][j]);
            visit[i][j] = false;
        }
    }
}

int main()
{
    run(0, 1);

    cout << cnt;

    return 0;
}