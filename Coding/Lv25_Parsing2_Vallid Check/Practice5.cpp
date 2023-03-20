#include <iostream>
#include <string>
using namespace std;

// [] 사이에 있는 문자들 출력

int main()
{
    string str = "ABC[BTS]KK[KFC]ggT[TT]";

    int a = 0;
    int b = 0;
    while (1)
    {
        a = str.find('[', a);
        b = str.find(']', a + 1);

        if (a == -1)
            break;

        string temp = str.substr(a + 1, b - a - 1);
        cout << temp << '\n';

        a = b + 1;
    }

    return 0;
}
