#include <iostream>
using namespace std;

// 수 2개(a, b) 입력 받고 a인덱스 부터 b인덱스 까지 출력

int main()
{
    string str;

    for (char i = 'A'; i <= 'Z'; i++)
    {
        str += i;
    }

    int a, b;
    cin >> a >> b;

    int size = b - a + 1;

    cout << str.substr(a, size);

    return 0;
}