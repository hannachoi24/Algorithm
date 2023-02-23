#include <iostream>
using namespace std;

int x;

void abc()
{
    if (x == 2)
    {
        cout << "#";
        return;
    }
    cout << x;
    x++;
    abc();
    cout << x;

    int d = 1; // 트레이스 확인을 위한 쓰레기 값
}

int main()
{
    abc();

    return 0;
}