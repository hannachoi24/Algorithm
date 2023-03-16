#include <iostream>
using namespace std;

// 순열
// 다섯개의 후보 중에 1~3등을 뽑으려고 한다. 단 T는 1등 불가하도록 구현

char word[6] = "QWERT";
char path[10];
bool visit[5];

void run(int lev)
{
    // if (path[0] == 'T') return; // 가지치기1

    if (lev == 3)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if (visit[i] == true)
            continue;
        if (lev == 0 && word[i] == 'T') // 가지치기2
            continue;
        visit[i] = true;
        path[lev] = word[i];
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