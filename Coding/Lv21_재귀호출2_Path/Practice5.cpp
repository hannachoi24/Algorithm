#include <iostream>
using namespace std;

// 011101110

void run(int lev)
{
    if (lev == 2)
    {
        return;
    }

    cout << lev;
    run(lev + 1);
    cout << lev;
    run(lev + 1);
    cout << lev;

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