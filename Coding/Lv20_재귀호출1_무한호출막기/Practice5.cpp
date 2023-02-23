#include <iostream>
using namespace std;

/* 재귀 호출 */

int n = 3;
char path[10];

void run(int x)
{
    if (x == n)
    {
        cout << path << '\n';
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        path[x] = '0' + i;
        run(x + 1);
    }
}

int main()
{

    cin >> n;
    run(0);

    return 0;
}