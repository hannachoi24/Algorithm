#include <iostream>
using namespace std;

char word[5] = "BGTK";
char path[10];

int level;

void run(int lev)
{
    if (lev == level)
    {
        for (int i = 0; i < lev; i++)
        {
            cout << path[i];
        }
        cout << '\n';

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        path[lev] = word[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    cin >> level;

    run(0);

    return 0;
}