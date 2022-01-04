#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c;

    int arr[10] = {0};

    cin >> a >> b >> c;

    int result = a * b * c;

    // 1의 자리를 얻어 온다.
    // result가 0이 되면 while문을 빠져나간다.
    while (result != 0)
    {
        arr[result % 10] += 1;
        result /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}