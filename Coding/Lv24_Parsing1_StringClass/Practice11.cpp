#include <iostream>
#include <string>
using namespace std;

// 대괄호 안에 있는 문자열 출력

int main()
{
    string str;
    cin >> str;

    int a = str.find("[");
    int b = str.find("]", a + 1);

    int size = b - a - 1;
    cout << str.substr(a + 1, size);

    return 0;
}