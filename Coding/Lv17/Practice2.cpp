#include <iostream>
using namespace std;

/*지역 변수의 크기가 10만개 넘어가면 안 됨 넘어갈 거 같으면 전역 변수로 선언*/

int arr[100000] = {5};

int main()
{
    for (int i = 0; i < 100000; i++)
    {
        // i는 28부터 천천히 볼 수 있도록 디버킹 코드 삽입 -> int d 줄에 breakpoint 찍고 F10
        if (i == 27)
        {
            int d = 1;
        }
        arr[i + 1] = arr[i] * 2;
    }

    return 0;
}