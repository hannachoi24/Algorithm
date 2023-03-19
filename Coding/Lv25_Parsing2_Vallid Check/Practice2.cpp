#include <iostream>
#include <string>
using namespace std;

// 주어진 문자열에서 찾을 문자가 각각 몇개인지 출력

string str = "ABCDAGDISSJKFCKFCKFC";
string tar[3] = {"KFC", "BF", "KF"};

int getCount(string tar)
{
    int a = -1;
    int cnt = 0;
    while (1)
    {
        a = str.find(tar, a + 1);
        if (a == -1)
            break;
        cnt++;
    }
    return cnt;
}

int main()
{
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        cnt += getCount(tar[i]);
    }

    cout << cnt;

    return 0;
}