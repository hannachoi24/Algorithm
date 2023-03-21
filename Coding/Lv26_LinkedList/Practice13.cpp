#include <iostream>
using namespace std;

// 힙-메모리공간(원하는 변수 만큼 공간 할당하기 위해)

int main()
{
    int *p = new int;

    *p = 1231;
    cout << *p;

    return 0;
}
