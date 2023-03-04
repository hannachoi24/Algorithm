#include <iostream>
using namespace std;

char name[6] = "ABTRG";
char path[7];

void run(int lev)
{
    if (lev == 4)
    {
        cout << path << '\n';
        return;
    }

    // 각 자리[lev]에서 인덱스 증가시키며 해당 자리 채우면 lev 호출해서 출력
    for (int i = 0; i < 5; i++)
    {
        path[lev] = name[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    run(0);

    return 0;
}