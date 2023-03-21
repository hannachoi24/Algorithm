#include <iostream>
using namespace std;

// 힙-메모리공간(원하는 변수 만큼 공간 할당하기 위해)

int main()
{
    int n;
    cin >> n;

    int *p = new int[n];

    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }

    return 0;
}
