#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int i = 0;
    while (i < str.length())
    {
        string name = "";
        while (i < str.length() && !isdigit(str[i]))
        {
            name += str[i++]; // 현재 인덱스에 해당하는 값 넣자마자 str인덱스 증가
        }

        int number = 0;
        while (i < str.length() && isdigit(str[i]))
        {
            number = number * 10 + (str[i++] - '0'); // int형으로 변환
        }

        cout << name << "#" << number + 17 << '\n';
    }

    return 0;
}

/* 또 다른 코드
#include <iostream>
#include <string>
using namespace std;

string str;
int getIntIndex(int start) {
    for (int i = start; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') return i;
    }
    return -1;
}

int getCharIndex(int start) {
    for (int i = start; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') return i;
    }
    return -1;
}

void print(string name, string num)
{
    cout << name << "#";
    int n = stoi(num);
    n += 17;
    cout << n << endl;
}

int main()
{
    cin >> str;
    //str = "AB100CDEF112F4G5";

    int a = 0;
    int b = 0;
    string name, num;
    while (1) {
        b = getIntIndex(a);
        name = str.substr(a, b - a);

        a = b;
        b = getCharIndex(a);
        if (b == -1) {
            b = str.length();
            num = str.substr(a, b - a);
            print(name, num);
            break;
        }

        num = str.substr(a, b - a);
        print(name, num);
        a = b;
    }

    return 0;
}
*/