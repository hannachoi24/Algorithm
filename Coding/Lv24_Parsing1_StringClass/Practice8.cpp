#include <iostream>
using namespace std;

int main()
{
    string str = "ABCWERW";
    string ret = str.substr(2, 4); // 2번 인덱스 부터 4글자를 뽑기

    cout << ret;

    return 0;
}