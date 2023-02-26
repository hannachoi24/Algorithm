#include <iostream>
using namespace std;

// 출력: 65433456

void abc(int x)
{
    if (x == 2)
    {
        return;
    }

    cout << x;
    abc(x - 1);
    cout << x;

    int d = 1;
}

int main()
{
    abc(6);

    return 0;
}