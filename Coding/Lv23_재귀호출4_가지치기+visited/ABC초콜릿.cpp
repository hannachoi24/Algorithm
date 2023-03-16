#include <iostream>
using namespace std;

/* A /B /C 세 종류의 초콜릿이 있다. 이 중 n개의 초콜릿을 선택하려고 하는데
3개 연속으로 같은 알파벳의 초콜릿을 선택하면 안 된다. */

char word[4] = "ABC";
char path[10];
int n;
int cnt;

void run(int lev)
{
    if (lev > 0 && path[lev - 1] == path[lev - 2] && path[lev - 2] == path[lev - 3])
    {
        return;
    }

    if (lev == n)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        path[lev] = word[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    cin >> n;

    run(0);

    cout << cnt;

    return 0;
}