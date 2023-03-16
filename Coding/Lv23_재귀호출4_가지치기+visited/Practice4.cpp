#include <iostream>
using namespace std;

// 두번째가 2가 아닌 눈금 모두 출력

char path[10];

void run(int lev, int sum)
{

    // if (lev == 2 && path[1] == '2') return; 가지치기 첫번째 방법

    if (lev == 3)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 1; i <= 6; i++)
    {
        if (lev == 1 && i == 2) // 가지치기 두번째 방법
            continue;
        path[lev] = '0' + i;
        run(lev + 1, sum + i);
        path[lev] = 0;
    }
}

int main()
{
    run(0, 0);

    return 0;
}
