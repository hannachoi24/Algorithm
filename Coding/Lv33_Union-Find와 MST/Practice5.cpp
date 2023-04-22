#include <iostream>
using namespace std;

// 섬의 개수 구하기

int myBoss[10];
int makeGroupCnt;
int map[10][10];

int getBoss(int n)
{
    if (myBoss[n] == 0)
        return n;

    int ret = getBoss(myBoss[n]);
    myBoss[n] = ret;
    return ret;
}

void setUnion(int t1, int t2)
{
    int a = getBoss(t1);
    int b = getBoss(t2);

    if (a == b)
        return;

    myBoss[b] = a;

    makeGroupCnt++;
}

int main()
{
    freopen_s(new FILE *, "input4.txt", "r", stdin);

    int n;
    cin >> n;

    int cnt = 0;
    int dx = {0, 0, -1, 1};
    int dy = {-1, 1, 0, 0};

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = ++cnt;

        for (int t = 0; t < 4; t++)
        {
            int nx = a + dx[t];
            int ny = b + dy[t];

            if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10)
                continue;
            if (map[nx][ny] == 0)
                continue;

            setUnion(map[a][b], map[nx][ny]);

            cout << cnt - makeGroupCnt;
        }
    }

    return 0;
}