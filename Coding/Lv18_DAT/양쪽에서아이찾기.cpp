#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
1. 문장 하드코딩
2. 두 문자 입력 받기
3. 첫번째 문자 왼쪽부터(0번인덱스부터) 탐색
4. 두번째 문자 오른쪽부터(배열길이부터) 탐색
5. 가장 먼저 발견된 글자의 각 위치 저장하고 절대값붙여서 거리 계산
*/

string str = "ATKPTCABC";
int result;
char a, b;
int len = str.length();

int findA()
{
    for (int i = 0; i <= len - 1; i++)
    {
        if (str[i] == a)
        {
            return i;
        }
    }
    return 0;
}

int findB()
{
    for (int j = len; j >= 1; j--)
    {
        if (str[j] == b)
        {
            return j;
        }
    }
    return 0;
}

int main()
{
    cin >> a >> b;

    result = abs(findA() - findB());

    cout << result;
}

/* 또 다른 코드
#include<iostream>
using namespace std;

int main()
{
    char name[10] = "ATKPTCABC";
    char d1, d2;

    cin >> d1 >> d2;

    int x, y;
    for (x = 0; x < 10; x++)
    {
        if (name[x] == d1) break;
    }

    for (y = 9; y >= 0; y--)
    {
        if (name[y] == d2) break;
    }

    cout << y - x;
}
*/