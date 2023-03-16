#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

char card[6];
char path[10];
int cnt;

void run(int lev)
{
    if (lev == 4)
    {
        int a = 0; // 간격마다 3이하인지 카운팅하는 변수
        for (int i = 0; i < 3; i++)
        {
            if (abs((path[i] - '0') - (path[i + 1] - '0')) <= 3)
                a++;
        }
        if (a == 3) // 총 세번 모두 증가되면 모든 자리가 3이하의 차
            cnt++;  // 그때 카운트 증가
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        path[lev] = card[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> card[i];
    }

    run(0);

    cout << cnt;

    return 0;
}