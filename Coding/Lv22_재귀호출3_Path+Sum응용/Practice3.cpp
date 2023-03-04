#include <iostream>
using namespace std;

/* 주사위 3개 재귀 호출
1 1 1
1 1 2
1 1 3
  .
  .
6 6 5
6 6 6
*/

char path[10];

void run(int lev)
{
    if (lev == 3)
    {
        cout << path << '\n';
        return;
    }

    // 각 자리[lev]에서 인덱스 증가시키며 해당 자리 채우면 lev 호출해서 출력
    for (int i = 0; i < 6; i++)
    {
        path[lev] = '1' + i;
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    run(0);

    return 0;
}