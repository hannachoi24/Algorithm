#include <iostream>
using namespace std;

// 출력: 012344321

void abc(int x)
{
    if (x == 5)
    {
        return;
    }

    cout << x;
    abc(x + 1);
    cout << x;

    int d = 1;
}

int main()
{
    abc(0);

    return 0;
}