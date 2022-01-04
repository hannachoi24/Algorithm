#include <iostream>

using namespace std;

int main(void)
{
    int num, sum = 0;
    int arr[42] = {0};

    for (int i = 0; i < 10; i++)
    {
        cin >> num;
        if (!arr[num % 42]++) // 입력 받은 수를 42로 나눈 나머지 인덱스의 값을 증가시키지 않았다면
            sum++;            // 해당 인덱스의 값을 증가시킨다.
    }

    cout << sum;
}