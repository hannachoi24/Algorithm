#include <iostream>
#include <string>
using namespace std;

/*
1. dat에 입력 받은 배열을 넣기
2. dat 값 카운트
3. 카운트 1이상인 방 알파벳 출력(단, 알파벳 순서대로 출력)
*/

int main()
{
    string str;
    int dat[200] = {0};

    cin >> str;

    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        dat[str[i]]++;
    }

    for (int i = 65; i <= 70; i++)
    {
        if (dat[i] >= 1)
        {
            cout << char(i);
        }
    }

    return 0;
}
