#include <iostream>
using namespace std;

void bts(int i)
{
    cout << i;
}

void abc(int n)
{
    for (int i = 0; i < 4; i++)

    {
        // abc함수 안에 있는 변수 n은 3이고, 변수 i가 1일 때 문제가 발생 했을 때 디버깅 코드 삽입
        if (n == 3 && i == 1)
        {
            int d = 1;
        }
        bts(i);
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        abc(i);
    }

    return 0;
}