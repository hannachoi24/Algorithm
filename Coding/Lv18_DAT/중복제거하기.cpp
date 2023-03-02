#include <iostream>
#include <string>
using namespace std;

/*
1. dat배열에 입력 받은 문자에 해당하는 방 1로 체크
2. 1로 체크된 방의 알파벳 출력(단, 알파벳 순서대로 출력)
*/

int main()
{
    string str;
    int dat[200] = {0};

    cin >> str;

    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        dat[str[i]] = 1;
    }

    for (int i = 0; i < 200; i++)
    {
        if (dat[i] == 1)
        {
            cout << (char)i;
        }
    }

    return 0;
}

/* 또 다른 코드
#include<iostream>
using namespace std;

int main()
{
    char name[10];
    int bucket[200] = { 0 };
    int x;

    cin >> name;

    int len;
    for (x = 0; x < 10; x++)
    {
        if (name[x] == '\0')
        {
            len = x;
            break;
        }
    }

    for (x = 0; x < len; x++)
    {
        bucket[name[x]] = 1;
    }

    for (x = 0; x < 200; x++)
    {
        if (bucket[x] == 1)
        {
            cout << (char)(x);
        }
    }
}
*/
