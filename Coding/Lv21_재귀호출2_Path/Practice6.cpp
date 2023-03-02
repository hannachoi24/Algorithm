#include <iostream>
using namespace std;

int cnt;
void run(int lev)
{
    if (lev == 2)
    {
        return;
    }

    cout << cnt;
    for (int i = 0; i < 2; i++)
    {
        cnt++;
        run(lev + 1);
        cnt--;
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