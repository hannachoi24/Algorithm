#include <iostream>
using namespace std;

char name[4] = "LMR";
char path[4]; // 한번에 출력하기 위해 char형으로

void run(int lev)
{
    // 종료 조건
    if (lev == 3)
    {
        cout << path << '\n';
        return;
    }

    // 브랜치
    for (int i = 0; i < 3; i++)
    {
        path[lev] = name[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    // 재귀 호출
    run(0);

    return 0;
}