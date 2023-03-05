#include <iostream>
using namespace std;

/* 주사위 3개 재귀 호출과 가지치기(숫자 2와 4 빼고 전부 출력)
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
    // if (lev > 0 && path[lev -1] == '2' || path[lev - 1] == '4') return; // 가지치기(일단 들어갔다가 아니네 하고 바로 나옴)
    if (lev == 3)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 1; i <= 6; i++)
    {
        if (i == 2 || i == 4) // 가지치기(아예 안 들어감 사전에 막아버림)
            continue;

        path[lev] = '0' + i;
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{

    run(0);

    return 0;
}
