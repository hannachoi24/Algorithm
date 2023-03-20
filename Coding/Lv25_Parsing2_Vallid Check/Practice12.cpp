#include <iostream>
#include <string>
using namespace std;

/* 유효성 검사하기
1. 2~5글자 허용
2. 특수문자 1개 허용
3. 대문자 안 됨
*/

int flag = 0;

int isValid(string str)
{
    if (!(str.length() >= 2 && str.length <= 5))
        return 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            continue;
        if (str[i] >= 'a' && str[i] <= 'z')
            continue;
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        return 0;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            continue;
    }

    return 1;
}

int main()
{
    string name;
    cin >> name;

    isValid(name);

    return 0;
}