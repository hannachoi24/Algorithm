#include <iostream>
using namespace std;

// n자리수 비번

char path[10];

void run(int lev, int n)
{
    if (lev == n)
    {
        cout << path << '\n';
        return;
    }

    // 각 자리[lev]에서 인덱스 증가시키며 해당 자리 채우면 lev 호출해서 출력
    for (int i = 1; i <= 9; i++)
    {
        path[lev] = '0' + i;
        run(lev + 1, n);
        path[lev] = 0;
    }
}

int main()
{
    run(0, 3);
    run(0, 4);
    run(0, 5);

    return 0;
}