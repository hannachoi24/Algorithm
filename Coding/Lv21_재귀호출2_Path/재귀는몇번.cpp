#include <iostream>
using namespace std;

int level, branch;

int cnt;

void run(int lev)
{
    cnt++;
    if (lev == level)
    {
        return;
    }

    for (int i = 0; i < branch; i++)
    {
        run(lev + 1);
    }
}

int main()
{
    cin >> branch >> level;

    run(0);

    cout << cnt;

    return 0;
}