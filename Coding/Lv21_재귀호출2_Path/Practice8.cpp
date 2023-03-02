#include <iostream>
using namespace std;

int n;

void run(int lev)
{
    if (lev == n)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        run(lev + 1);
    }

    int d = 1;
}

int main()
{
    cin >> n;

    run(0);

    return 0;
}