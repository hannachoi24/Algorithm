#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char buf[] = "ACQRAGGVHDI";

int cmp(int a, int b)
{
    // 1. C ~ H이면 우선순위 높음
    if ((a >= 'C' && a <= 'H') && !(b >= 'C' && b <= 'H'))
        return 1;
    if (!(a >= 'C' && a <= 'H') && (b >= 'C' && b <= 'H'))
        return 0;

    // 큰 알파벳 우선순위 높음
    return a > b;
}

int main()
{
    int len = strlen(buf);
    // 다중조건
    sort(buf, buf + len, cmp);

    for (int i = 0; i < len; i++)
    {
        cout << buf[i];
    }

    return 0;
}