#include <iostream>
#include <string>
using namespace std;

// 대괄호 안에 문자들끼리 정수형으로 변환하여 더하기

int main()
{
    string str = "B[45]AB[9994]";

    int a = str.find('[');
    int b = str.find(']', a + 1);
    int c = str.find('[', b + 1;);
    int d = str.find(']', c + 1);

    string t1 = str.substr(a + 1, b - a - 1);
    string t2 = str.substr(c + 1, d - c - 1);

    cout << stoi(t1) + stoi(t2);

    return 0;
}