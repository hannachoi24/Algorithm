#include <iostream>
using namespace std;

// 중복순열
// 방문처리하면서 같은 숫자 나오지 않게 출력

char path[10];
bool visit[7];

void run(int lev)
{
    if (lev == 3)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 1; i <= 6; i++)
    {
        if (visit[i] == true)
            continue;
        visit[i] = true;
        path[lev] = '0' + i;
        run(lev + 1);
        path[lev] = 0;
        visit[i] = false;
    }
}

int main()
{
    run(0);

    return 0;
}