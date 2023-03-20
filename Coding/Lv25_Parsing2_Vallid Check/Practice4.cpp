#include <iostream>
#include <string>
using namespace std;

// # 사이에 있는 문자들 출력

int main()
{
    string str;
    cin >> str;

    int a = str.find('#');
    int b = str.find('#', a + 1);

    cout << str.substr(0, a) << '\n';
    cout << str.substr(a + 1, b - a - 1) << '\n';
    cout << str.substr(b + 1, str.length() - b - 1);

    return 0;
}