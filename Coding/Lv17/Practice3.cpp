#include <iostream>
using namespace std;

/*지역 변수의 크기가 10만개 넘어가면 안 됨 넘어갈 거 같으면 전역 변수로 선언*/

int main()
{
    int map[10][10] = {0};

    // 1. [3][4] 값 확인하기 -> Ctrl + F10

    int t = 1;
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            // 2. 3, 6이 왜 17이 들어갔는지 이 부분을 천천히 볼 수 있게 디버깅 코드 삽입 -> int d 줄에 breakpoint 찍고 F10
            if (y == 3 && x == 6)
            {
                int d = 1;
            }
            t = (t * 3 + 1234) % 22;
            map[y][x] = t;
        }
    }

    return 0;
}