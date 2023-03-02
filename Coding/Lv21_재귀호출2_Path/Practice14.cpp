#include <iostream>
using namespace std;

int n;
char path[10];

void run(int lev)
{
    if (lev == n)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        path[lev] = '1' + i;
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    cin >> n;

    run(0);

    return 0;
}