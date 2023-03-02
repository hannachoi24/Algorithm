#include <iostream>
using namespace std;

// level:3, branch: 4

int path[3];
void run(int lev)
{
    if (lev == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << path[i] << " "
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        path[lev] = i + 1; // 가려고 하는 lev 내용을 기록
        run(lev + 1);
        path[lev] = 0; // 돌아와서 기록한 것을 지움
    }

    int d = 1;
}

int main()
{
    run(0);

    return 0;
}
