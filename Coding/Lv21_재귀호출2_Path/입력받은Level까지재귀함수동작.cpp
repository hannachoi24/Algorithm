#include <iostream>
using namespace std;

int n;

void run(int lev)
{

    cout << lev;
    if (lev == n)
    {
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        run(lev + 1);
    }
}

int main()
{
    cin >> n;

    run(0);

    return 0;
}