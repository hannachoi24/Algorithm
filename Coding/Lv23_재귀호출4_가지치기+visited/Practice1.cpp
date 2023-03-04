#include <iostream>
using namespace std;

/* 주사위 3개 재귀 호출과 가지치기(숫자 2 빼고 전부 출력)
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
    // if (lev > 0 && path[lev - 1] == '2') return; -> 가지치기 첫번째 방법(일단 들어갔다가 아니네 하고 바로 나옴)
    if (lev == 3)
    {
        cout << path << '\n';
        return;
    }

    // 각 자리[lev]에서 인덱스 증가시키며 해당 자리 채우면 lev 호출해서 출력
    for (int i = 1; i <= 6; i++)
    {
        if (i != 2) // 가지치기 두번째 방법(아예 안 들어감 사전에 막아버림)
        {
            path[lev] = '0' + i;
            run(lev + 1);
            path[lev] = 0;
        }
    }
}

int main()
{
    run(0);

    return 0;
}