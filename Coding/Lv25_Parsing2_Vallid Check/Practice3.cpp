#include <iostream>
#include <string>
using namespace std;

// 길이가 긴 문장에서 길이가 짧은 문장 찾기

string str1, str2;

int getCount(string str1, string str2)
{
    int a = -1;
    int b = -1;
    int cnt = 0;
    while (1)
    {
        a = str1.find(str2, a + 1);
        b = str2.find(str1, b + 1);
        if (a == -1 || b == -1)
            break;
        cnt++;
    }
    return cnt;
}

int main()
{
    cin >> str1, str2;

    int len1 = str1.length();
    int len2 = str2.length();

    int cnt = 0;
    if (len1 > len2)
    {
        cnt = getCount(str1, str2);
    }
    else
        cnt = getCount(str2, str1);

    cout << cnt;

    return 0;
}