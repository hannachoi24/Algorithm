#include <iostream>
using namespace std;

int main()
{
    string str = "AB[1342]QT";
    string ret = str.substr(3, 4); // 3번 인덱스 부터 4글자를 뽑기

    cout << ret;

    return 0;
}