#include <iostream>
using namespace std;

/*
OOOOO
OOOOX
  .
  .
XXXXX
*/

char name[3] = "OX";
char path[6];

void run(int lev)
{
    if (lev == 5)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        path[lev] = name[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    run(0);

    return 0;
}
