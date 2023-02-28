#include <iostream>
using namespace std;

void run(int lev)
{
    if (lev == 2)
    {
        return;
    }

    run(lev + 1);
    cout << "#";
    run(lev + 1);
    cout << "#";
    int d = 1;
}

int main()
{
    run(0);

    return 0;
}

/*
#은 총 6개 출력
  *
 / \
 *  *
/ \ / \
* * * *

*/