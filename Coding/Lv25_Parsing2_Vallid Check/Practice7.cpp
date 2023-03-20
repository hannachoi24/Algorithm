#include <iostream>
#include <string>
using namespace std;

// - 사이에 있는 수들의 합을 출력
// hint. 문자열을 수로 바꾸는 stoi()사용

int main()
{
    string str = "123-324-43543-12";

    str += '-';

    int a = 0;
    int b = 0;
    int sum = 0;
    while (1)
    {
        b = str.find('-', a + 1);
        if (b == -1)
            break;
        string temp = str.substr(a, b - a);
        sum += stoi(temp);

        a = b + 1;
    }

    cout << sum;

    return 0;
}