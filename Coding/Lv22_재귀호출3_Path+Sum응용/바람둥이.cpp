#include <iostream>
using namespace std;

char word[3] = "xo";
char path[10];
int n;

void run(int lev)
{
    if (lev == n)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 0; i < 2; i++)
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

    return 0;
}