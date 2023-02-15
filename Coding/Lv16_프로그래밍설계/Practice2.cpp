#include <iostream>

using namespace std;

/* 특정 문자열 제거 */

int main()
{
    char str[11];
    int idx;

    cin >> str;
    cin >> idx;

    // 1.문자열 길이
    int len = 0;
    for (int i = 0; i < 10; i++)
    {
        if (str[i] == '\0')
        {
            len = i;
            break;
        }
    }

    // 2.idx ~ len - 1 까지 하나씩 땡기기
    for (int i = idx; i <= len - 1; i++)
    {
        str[i] = str[i + 1];
    }

    len--;

    // 3.일반, 역순 출력
    cout << str << endl;

    for (int i = len - 1; i >= 0; i--)
    {
        cout << str[i];
    }

    return 0;
}