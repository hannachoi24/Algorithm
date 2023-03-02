#include <iostream>
using namespace std;

int path[2];
void run(int lev)
{
    if (lev == 2)
    {
        for (int i = 0; i < lev; i++)
        {
            cout << path[i] << " "
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < 2; i++)
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

/*

  *
 / \
 *  *
/ \ / \
* * * *

*/