#include <iostream>
using namespace std;

// 직전 눈금과 같으면 탈락

char path[10];

void run(int lev)
{
    // if (lev >= 2 && path[lev - 1] == path[lev - 2]) return; 가지치기1

    if (lev == 3)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 1; i <= 6; i++)
    {
        if (lev > 0 && path[lev - 1] == '0' + i) // 가지치기2
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
