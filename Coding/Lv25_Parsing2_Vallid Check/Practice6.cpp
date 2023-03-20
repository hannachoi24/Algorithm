#include <iostream>
#include <string>
using namespace std;

// | 사이에 있는 숫자들 출력

int main()
{
    string str = "12|123|1234";

    int a = 0;
    int b = 0;

    str += '|';
    while (1)
    {
        b = str.find('|', a + 1);

        if (b == -1)
            break;

        string temp = str.substr(a, b - a);
        cout << temp << '\n';

        a = b + 1;
    }

    return 0;
}