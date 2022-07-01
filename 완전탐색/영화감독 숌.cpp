#include <iostream>
#include <string>
using namespace std;

/* 숫자를 1씩증가하여 모든 숫자를 차례대로 검사한다.
수를 string으로 바꿔서 find 함수를 통해 '666'이 포함되어 있는지 확인하고
포함되어 있다면 카운트를 증가시켜준다.

카운트가 n과 같아지면 현재 숫자를 출력한다. */

int main()
{
    int n;
    int count = 0;
    int title = 665;
    string s;

    cin >> n;

    while (++title)
    {
        s = to_string(title); // to_string 함수는 숫자 타입의 데이터를 안전하게 스트링 타입으로 변경하도록 하는 함수

        if (s.find("666") != -1)
        {
            ++count;
        }

        if (count == n)
        {
            cout << title << endl;
            break;
        }
    }
    return 0;
}