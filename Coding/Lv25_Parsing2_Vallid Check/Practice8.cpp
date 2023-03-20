#include <iostream>
#include <string>
using namespace std;

// :과 , 사이에 있는 수들의 합을 출력
// hint. 문자열을 수로 바꾸는 stoi()사용

int main()
{
    string str = "ID:45,BTS:1545";

    int a = 0;
    int b = 0;
    int sum = 0;

    str += ",";
    while (1)
    {
        a = str.find(':', a);
        if (a == -1)
            break;
        b = str.find(',', a + 1);

        string temp = str.substr(a + 1, b - a - 1);
        sum += stoi(temp);

        a = b + 1;
    }

    cout << sum;

    return 0;
}